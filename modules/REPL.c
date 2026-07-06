#include <stdio.h>
#include "REPL.h"

/*
 *  @brief Starts the read/write loop of the shell.
 *
 *  Shows the prompt, captures the input and passes it to the tokenizer.
 *
 *  @return 0 if the sessions finishes successfully.
 *  @return 1 if there was an error during the read.
 */

int ReadEvalPrintLoop (void) {
    char *fgets_status;
    char buffer[1024];

    /*
     * a do-while loop to make it more verbose and readable, it could be more compact, but in the end for the assembly
     * code it's the same, so instead of delegating the responsibility of checking if fgets didn't return NULL to the
     * call of fgets, a variable takes care of that
     */

    do {
        fputs("-> ", stdout);
        fflush(stdout);                                          // force the flush of the buffer so it doesn't get stuck
        fgets_status = fgets(buffer, sizeof(buffer), stdin);   // if fgets returns NULL, then break the loop

        if (fgets_status != NULL) {
            // TODO: invocar al tokenizer
        }

    } while (fgets_status != NULL);

    if (ferror(stdin) != 0) {                                    // check if it returned NULL bc of an error or just an EOF
        fputs("\n[ERROR] fgets returned NULL\n", stderr);
        return 1;
    }

    fputs("\n[MSG] session successfully finished!\n", stdout); // if it returns 0, then it just was an EOF

    return 0;
}

