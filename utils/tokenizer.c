/*
 *  utils/tokenizer.c
 *
 *  Custom FSM (Finite State Machine) tokenizer for the Chell shell.
 *  Splits a raw input string into tokens by mutating the buffer in-place,
 *  replacing delimiters with null terminators and collecting pointers
 *  to the start of each token. Supports quoted strings to preserve
 *  spaces within arguments.
 */

#include "tokenizer.h"
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
 */

args tokenizer(char *string) {
    bool isQuote = false;
    size_t str_len = strlen(string);

    args cmd;
    cmd.argc = 0;

    int start = 0;

    // 1. Skip leading whitespaces
    while (string[start] == ' ') {
        start++;
    }

    // 2. If we hit the end, the input was empty or whitespace-only
    if (string[start] == '\0') {
        cmd.status = 1;
        return cmd;
    }

    // The first token always starts at the first non-whitespace character
    cmd.tokens[0] = &string[start];
    cmd.argc++;

    // Process from 'start' onwards, ignoring leading spaces
    for (int i = start; i < str_len; i++) {
        
        // --- QUOTE HANDLING ---
        if (chkQuote(string[i])) {
            if (isQuote == false) {
                // Opening quote: adjust the current token pointer to skip the quote character
                isQuote = true;
                cmd.tokens[cmd.argc - 1] = &string[i + 1];
            } else {
                // Closing quote: inject null terminator to cleanly end the token
                isQuote = false;
                string[i] = '\0';
            }
        }

        // --- SPACE HANDLING ---
        if (isQuote == false && string[i] == ' ') {
            string[i] = '\0';                                    // inject null terminator to split the word

            while (string[i + 1] == ' ') {                       // skip consecutive spaces
                string[i + 1] = '\0';
                i++;
            }

            if (i < str_len - 1) {
                cmd.tokens[cmd.argc] = &string[i + 1];           // save pointer to the start of the next token
                cmd.argc++;
            }
        }
    }

    // TODO: pasar los punteros al parser

    cmd.status = 0;
    return cmd;
}