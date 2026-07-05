#include <stdio.h>
#include "models/structs.h"

int main(void) {
    struct REPL repl;                                         // Instantiate the REPL struct
    char *fgets_status;                                       // Check fgets's state

    do {                                                      // REPL runs in-definitively under ideal circumstances
        fputs("-> ", stdout);                               // Prompt for the user
        fgets_status = fgets(repl.buffer, sizeof(repl.buffer), stdin);
        fflush(stdout);
    } while (fgets_status != NULL);

    fputs("\n[ERROR] fgets returned NULL", stderr);         // Debug message

    return 0;
}