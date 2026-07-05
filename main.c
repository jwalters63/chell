#include <stdbool.h>
#include <stdio.h>

struct REPL {
    char buffer[1024]; // Buffer que guarda las cadenas de string
};

int main(void) {
    struct REPL repl; // Crear el objeto del struct REPL

    while (true) { // REPL, la unica forma de matar al shell es con CTRL + C
        fputs("-> ", stdout); // Prompt para el usuario
        fgets(repl.buffer, sizeof(repl.buffer), stdin);
    }
}