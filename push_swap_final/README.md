# push_swap — 42 Madrid

**Estado:** terminado (trabajo académico).

Ejercicio de ordenación de números enteros en C mediante operaciones permitidas sobre dos pilas, con el objetivo de organizar los elementos usando una secuencia de movimientos.

## Qué se trabaja

- Estructuras de datos y operaciones sobre pilas.
- Algoritmos de ordenación.
- Tratamiento y validación de argumentos.
- Organización modular en C.

## Código

Los archivos fuente se encuentran en [`src/`](./src), junto con las cabeceras en [`includes/`](./includes). El directorio incluye un `Makefile`.

Este trabajo sigue un enunciado académico de 42 Madrid.

## Compilar y ejecutar

Desde este directorio, con Make y un compilador C:

```sh
make
./push_swap 3 2 1
```

La salida contiene operaciones de las pilas, no la lista ordenada. No se requiere ejecutar los binarios `checker_Mac` o `checker_linux` incluidos para compilar. `make clean` y `make fclean` limpian los productos generados.

