#pragma once

typedef enum {
    OK = 0,
    ERR_FGETS_FAIL = 1,
    ERR_UNCLOSED_QUOTES = 2,
    ERR_IS_EMPTY = 3,
    ERR_SYNTAX = 4
} shellStatus;

void printErrorMsg(shellStatus status);