# pipex — 42 Madrid

**Estado:** terminado (trabajo académico).

Ejercicio en C para reproducir la conexión de comandos mediante una tubería, trabajando con la ejecución de procesos y la redirección de entrada y salida en sistemas Unix.

## Qué se trabaja

- Creación de procesos con `fork`.
- Ejecución de programas con `execve`.
- Comunicación mediante `pipe` y redirección con `dup2`.
- Descriptores de archivo, argumentos y manejo de errores.

## Código

La implementación principal está en [`pipex.c`](./pipex.c), con archivos auxiliares, cabeceras y `Makefile` en este directorio.

Este trabajo sigue un enunciado académico de 42 Madrid.

## Estado de la copia publicada

El trabajo está confirmado como terminado por la autora, pero **esta copia de GitHub no se ha podido compilar ni ejecutar**. Puede corresponder a una versión de trabajo anterior a la entrega final.

Auditoría del 11 de octubre de 2026 en Linux:

- `make` falla porque `LIBFT_DIREC` contiene una ruta absoluta del equipo original.
- `make LIBFT_DIREC=libft` evita esa ruta, pero falla en `parse` por asignar un `char **` a un `char *`.
- `get_path` en `utils.c` está vacío y los fuentes seleccionados por el Makefile no aportan un `main` activo.

La interfaz prevista es `./pipex infile "cmd1" "cmd2" outfile`. No se presenta como instrucción ejecutable validada. Primero hay que localizar la versión final o autorizar una revisión del código. No hay pruebas automatizadas propias.
