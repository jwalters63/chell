cmake_minimum_required(VERSION 4.2)
project(cshell C)

set(CMAKE_C_STANDARD 11)

add_executable(cshell
        main.c
        modules/REPL.c
        modules/REPL.h)
