# get_next_line — 42 Madrid

Trabajo formativo terminado, según confirmación de la autora. La función `get_next_line(fd)` devuelve la siguiente línea de un descriptor de archivo, conservando el salto de línea cuando existe. Devuelve `NULL` cuando no obtiene una línea.

## Conceptos

`read`, descriptores, buffers, memoria dinámica y conservación de datos entre llamadas con una variable estática. Esta versión conserva un único estado: no está diseñada para alternar varios descriptores.

## Compilar y utilizar

No hay Makefile ni programa principal activo. Desde este directorio:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -I. ejemplo.c get_next_line.c get_next_line_utils.c -o ejemplo
./ejemplo
```

`ejemplo.c` debe incluir `get_next_line.h`, abrir el archivo y llamar a la función hasta recibir `NULL`. Cada línea devuelta debe liberarse con `free`; el descriptor debe cerrarse con `close`. El `main` comentado del fuente es una prueba histórica y no debe activarse tal cual: no termina al llegar a `NULL`.

## Verificación

Auditoría del 11 de octubre de 2026 en Linux: compilación correcta; archivo vacío, líneas normales, línea vacía, última línea sin salto y línea de 10.000 caracteres pasaron una comparación de salida. No se simularon fallos de reserva ni se validaron todos los errores de lectura.

Pendiente: `ft_strjoin` escribe en la reserva inicial antes de comprobar si `malloc` falló. La gestión de fallos de memoria necesita revisión.
