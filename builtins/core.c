#include "core.h"

#include <string.h>
#include <stdlib.h>

shellStatus builtinExit(args cmd) {
    if (strcmp(cmd.tokens[0], "exit") == 0) {
        exit(0);
    } else return ERR_SYNTAX;
}