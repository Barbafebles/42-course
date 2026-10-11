# ft_printf — 42 Madrid

Trabajo formativo terminado, según confirmación de la autora. Implementación de una parte de `printf`: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` y `%%`.

## Conceptos

Funciones variádicas con `va_list`, conversión de números, recursión y recuento de caracteres escritos. No implementa todas las opciones de la función estándar: anchura, precisión y flags no están soportados.

## Compilar y utilizar

Desde este directorio, con Make y un compilador C:

```sh
make
cc -Wall -Wextra -Werror -I. ejemplo.c libftprintf.a -o ejemplo
./ejemplo
```

El archivo `ejemplo.c` debe incluir `ft_printf.h` y definir `main`. `make clean` elimina objetos y `make fclean` también la biblioteca.

## Verificación

Auditoría del 11 de octubre de 2026 en Linux: compilación correcta; una comprobación combinada de texto, enteros, hexadecimal, porcentaje y valor devuelto pasó. No es una prueba completa de todos los formatos.

Pendiente: un formato acabado en `%` puede hacer que se lea más allá de su terminador. No utilizar formatos no soportados ni cadenas de formato sin validar.
