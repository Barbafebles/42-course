# Libft — 42 Madrid

Trabajo formativo terminado, según confirmación de la autora. Biblioteca de funciones en C para cadenas, memoria, conversiones y salida mediante descriptores.

## Conceptos

Punteros, memoria dinámica, tratamiento de cadenas, cabeceras y bibliotecas estáticas. Esta copia incluye las funciones declaradas en `libft.h`; no contiene una implementación de listas enlazadas.

## Compilar y utilizar

Desde este directorio, con un compilador C y Make:

```sh
make
cc -Wall -Wextra -Werror -I. ejemplo.c libft.a -o ejemplo
./ejemplo
```

`ejemplo.c` debe aportar su propio `main` e incluir `libft.h`. La biblioteca no es un programa ejecutable. `make clean` elimina objetos generados y `make fclean` también la biblioteca.

## Verificación

Auditoría del 11 de octubre de 2026 en Linux: compilación correcta y comprobaciones básicas de `ft_strlen`, `ft_strjoin` y reserva a cero. No se ha validado exhaustivamente cada función. El desbordamiento de `num * size` en `ft_calloc` se corrigió en la [PR #7](https://github.com/Barbafebles/42-course/pull/7), con pruebas de regresión.

Las pruebas de estas correcciones se ejecutan desde la raíz con `python3 tests/regression.py` (Linux y GCC). Pasaron también con AddressSanitizer y UndefinedBehaviorSanitizer; LeakSanitizer no pudo ejecutarse por restricciones del entorno.
