#include <stdio.h>

struct REPL {                                                 // Struct para variables globales
    char buffer[1024];                                        // Buffer que guarda las cadenas de string
};

int main(void) {
    struct REPL repl;                                         // Crear el objeto del struct REPL
    char *fgets_status;                                       // Corroborar el estado de fgets

    do {                                                      // REPL, corre indefinidamente bajo circumstancias ideales
        fputs("-> ", stdout);                               // Prompt para el usuario
        fgets_status = fgets(repl.buffer, sizeof(repl.buffer), stdin);
    } while (fgets_status != NULL);

    fputs("fgets retornó NULL", stderr);                    // Mensaje de debug para saber exactamente por qué falló

    return 0;
}