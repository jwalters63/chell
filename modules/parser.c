/*
 *  modules/parser.c
 *
 *  Custom FSM (Finite State Machine) tokenizer for the Chell shell.
 *  Splits a raw input string into tokens by mutating the buffer in-place,
 *  replacing delimiters with null terminators and collecting pointers
 *  to the start of each token. Supports quoted strings to preserve
 *  spaces within arguments.
 */

#include "parser.h"
#include "../models/structs.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*
 *  @brief Checks if a character is a double-quote.
 *
 *  Helper function used by the tokenizer to detect state transitions
 *  between ST_SPACE and ST_QUOTE modes.
 *
 *  @param checking The character to evaluate.
 *  @return true if the character is a double-quote, false otherwise.
 */

int chkQuote(char checking) {
    if (checking == '"') {
        return true;
    } return false;
}

/*
 *  @brief Tokenizes a raw input string using a two-state FSM.
 *
 *  Walks through the string character by character. In the default state (ST_SPACE),
 *  spaces are replaced with null terminators to split words. When a double-quote is
 *  encountered, the FSM toggles into ST_QUOTE mode where spaces are preserved,
 *  allowing multi-word arguments like "hola mundo".
 *
 *  The function mutates the original buffer in-place for efficiency (no memory
 *  allocation needed) and stores pointers to each token's starting address
 *  inside an args struct.
 *
 *  @param string Pointer to the mutable char array to tokenize.
 *
 *  TODO: change return type from void to args so the REPL can forward
 *        the parsed tokens to the executor.
 */

void tokenizer(char *string) {
    bool isQuote = false;
    size_t str_len = strlen(string);

    args cmd;
    cmd.argc = 0;

    // TODO BUG-004: if string is empty, this creates a ghost token pointing to '\0'.
    //                add an early return when buffer is empty or whitespace-only.
    // TODO BUG-003: if string starts with a space, tokens[0] points to a space that
    //                gets replaced by '\0', resulting in an empty token.
    //                skip leading spaces before assigning tokens[0].
    cmd.tokens[0] = &string[0];                                  // the first word always starts at position 0
    cmd.argc++;

    for (int i = 0; i < str_len; i++) {
        if (chkQuote(string[i])) {
            isQuote = !isQuote;                                  // toggle: ST_SPACE <-> ST_QUOTE
            // TODO BUG-001: the quote character itself remains in the token output.
            //                replace it with '\0' (or shift pointers) so quotes
            //                don't appear in the final argument.
        }

        if (isQuote == false && string[i] == ' ') {
            string[i] = '\0';                                    // inject null terminator to split the word
            // TODO BUG-002: consecutive spaces (e.g. "ls  -l") cause an empty ghost
            //                token because string[i+1] is another space. Check that
            //                the next char is not a space before saving the pointer.
            if (i < str_len - 1) {
                cmd.tokens[cmd.argc] = &string[i + 1];           // save pointer to the start of the next token
                cmd.argc++;
            }
        }
    }
}