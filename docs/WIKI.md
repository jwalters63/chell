# Chell Wiki
Documentación técnica del diseño arquitectónico del Shell.

## 1. Flujo de Ejecución (Pipeline)
El shell procesa los comandos siguiendo este flujo estricto (O(N) complejidad):
1. **REPL**: Captura el string bruto del teclado. Si falla, aborta.
2. **Sanitizer**: Limpia el string (ej. elimina `\n`).
3. **Tokenizer (Lexer)**: Analiza el string en una sola pasada usando una máquina de estados (FSM). Preserva los espacios dentro de comillas e inyecta `\0` para dividir las palabras sin requerir `malloc`. Termina inyectando un centinela `NULL` para la compatibilidad con `execvp`.
4. **Executor (Enrutador)**: Evalúa el arreglo de punteros:
   - Verifica primero si es un Comando Interno (Built-in).
   - Si no es un Built-in, asume que es un binario externo y realiza `fork()` + `execvp()`.

## 2. Taxonomía de Códigos (shellStatus)
Para evitar tratar los desvíos lógicos como errores (Ej. "No es un Builtin"), los códigos se categorizan mediante prefijos semánticos:

### Códigos de Sistema (SYS_)
Representan el flujo normal de control o decisiones de enrutamiento. No imprimen errores en pantalla.
- `OK (0)`: Ejecución perfecta.
- `SYS_NOT_BUILTIN`: Indica al Ejecutor que el comando no existe en la librería interna, por lo que debe buscarlo como binario externo.

### Códigos de Advertencia (WARN_)
Flujos anormales pero que no representan un peligro o fallo sintáctico grave.
- `WARN_IS_EMPTY`: El usuario presionó Enter sin escribir comandos. El REPL debe ignorarlo silenciosamente.

### Códigos de Error (ERR_)
Fallos reales que deben ser interceptados e impresos en rojo por `printErrorMsg`.
- `ERR_FGETS_FAIL`: Fallo crítico en la lectura del teclado (stdin).
- `ERR_SYNTAX`: Error sintáctico general.
- `ERR_UNCLOSED_QUOTES`: El usuario abrió comillas pero nunca las cerró.
