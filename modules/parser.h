#pragma once

typedef enum {
    ST_SPACE,
    ST_QUOTE
} TOK_STATE;

int chkQuote(char);

int tokenizer(char *string);