#pragma once
#define MAX_ARGS 16

struct Command {
    char *args[MAX_ARGS];
    int argc;
};