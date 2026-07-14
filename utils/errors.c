#include <stdio.h>
#include "errors.h"

void printErrorMsg(shellStatus status) {
    switch (status) {
        case OK:
            break;

        case WARN_IS_EMPTY:
            break;

        case ERR_FGETS_FAIL:
            fputs("[ERROR] fgets returned NULL\n", stderr);
            break;

        case ERR_SYNTAX:
            fputs("[ERROR] Syntax Error\n", stderr);
            break;

        case ERR_UNCLOSED_QUOTES:
            fputs("[ERROR] Unclosed Quotes\n", stderr);
            break;
    }
}