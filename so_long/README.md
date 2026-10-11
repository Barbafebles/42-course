# so_long — 42 Madrid

**Estado:** terminado (trabajo académico).

Juego 2D programado en C como parte del programa de 42 Madrid.

## Qué se trabaja

- Carga y validación de mapas.
- Movimiento del personaje, coleccionables y salida.
- Renderizado gráfico con la biblioteca MLX42.
- Organización del código en módulos y gestión de errores.

## Código

Los fuentes están en [`src/`](./src), los mapas en [`Maps/`](./Maps) y los recursos gráficos en [`xpm/`](./xpm). El proyecto incluye un `Makefile`.

Este trabajo sigue un enunciado académico de 42 Madrid.

## Compilar y ejecutar

Requiere compilador C, Make, CMake, GLFW y soporte gráfico OpenGL. MLX42 está incluida en el repositorio. Desde este directorio:

```sh
# Linux, con las dependencias instaladas
make OS=LINUX
./so_long Maps/map.ber
```

Para macOS el Makefile admite `make OS=MACOS` y busca GLFW en `/opt/homebrew/opt/glfw/lib`; esa ruta puede necesitar adaptación en otros equipos. Los requisitos detallados de la biblioteca se encuentran en [MLX42](./MLX42/README.md).

## Verificación

Auditoría del 11 de octubre de 2026: `make` se detuvo porque el entorno Linux utilizado no tiene CMake. La autora confirma que el juego funciona en su entorno. La auditoría no pudo reproducir la compilación completa ni la ejecución gráfica, y no validó todos los mapas. Las capturas del juego están pendientes de añadir. Los mapas incluidos permiten preparar pruebas de validación; los tests de MLX42 corresponden a la biblioteca y no constituyen una suite del juego.
