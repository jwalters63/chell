/*
 *  models/structs.h
 *
 *  Core data structures for the Chell shell.
 *  Following a Data-Oriented Design (DOD) approach, structs here
 *  are pure data containers with no behavior attached.
 */

#pragma once

#define MAX_ARGS 16                                              // conservative upper limit for argument count (baby steps)

typedef struct {
    int status;
    int argc;                                                    // stands for argument count
    char *tokens[MAX_ARGS];                                      // array of pointers, each pointing to the start of a token inside the mutated buffer
} args;