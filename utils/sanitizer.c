#include "sanitizer.h"
#include <stdbool.h>
#include <string.h>

/*
 *  @brief Checks if a character is a newline.
 *
 *  Helper function used by sanitizeString to identify
 *  characters that need to be replaced.
 *
 *  @param checking The character to evaluate.
 *  @return true if the character is a newline, false otherwise.
 */

int chkNewline(char checking) {
    if (checking == '\n') {
        return true;
    } return false;
}

/*
 *  @brief Strips newline characters from a string by replacing them with null terminators.
 *
 *  fgets preserves the trailing newline ('\n') from stdin, which would cause
 *  issues downstream (e.g. the tokenizer would treat it as part of the last argument,
 *  and execvp would fail to find the command). This function mutates the string
 *  in-place to guarantee a clean, newline-free buffer before further processing.
 *
 *  @param string Pointer to the mutable char array to sanitize.
 */

void sanitizeString(char *string) {
    size_t str_len = strlen(string);                     // cache the length to avoid recalculating on each iteration
    for (int i = 0; i < str_len; i++) {
        if (chkNewline(string[i])) {
            string[i] = '\0';                            // replace newline in-place, effectively truncating the string
        }
    }
}