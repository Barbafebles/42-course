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
