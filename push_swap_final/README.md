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

## Verificación

Auditoría del 11 de octubre de 2026 en Linux: compila con las opciones del Makefile. Un simulador independiente de operaciones comprobó las 24 permutaciones de cuatro valores y 20 muestras de 5, 10, 50 y 100 enteros distintos. También se comprobó el rechazo de duplicados, texto y enteros fuera de rango; sin argumentos sale sin operaciones. No se han validado límites de movimientos, fugas de memoria ni todos los casos extremos. No hay suite propia de tests en el repositorio.
