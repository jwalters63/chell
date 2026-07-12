cmake_minimum_required(VERSION 4.2)
project(cshell C)

set(CMAKE_C_STANDARD 11)

add_executable(cshell
        main.c
        modules/REPL.c
        modules/REPL.h
        utils/tokenizer.h
        utils/tokenizer.c
        utils/sanitizer.c
        utils/sanitizer.h
        models/structs.h
        utils/errors.c
        utils/errors.h
        modules/executor.c
        modules/executor.h
        builtins/core.c
        builtins/core.h)
