/*
 *  main.c
 *
 *  Entry point for the Chell shell.
 *  Delegates all interactive logic to the REPL module, keeping
 *  the main function minimal and focused on orchestration.
 */

#include "modules/REPL.h"

int main(void) {

    readEvalPrintLoop();

    return 0;
}