#include "parser.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int chkQuote(char checking) {
    if (checking == '"') {
        return true;
    }
    return false;
}

int tokenizer(char *string) {
    bool isQuote = false;
    size_t str_len = strlen(string);

    for (int i = 0; i < str_len; i++) {
        if (chkQuote(string[i])) {
            isQuote = !isQuote;
        }

        if (isQuote == false && string[i] == ' ') {
            string[i] = '\0';
        }
    }
}