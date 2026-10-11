# Ejercicios y trabajos formativos de 42 Madrid

Este repositorio reúne código y ejercicios desarrollados durante mi formación en **42 Madrid**. Son trabajos académicos con enunciados definidos por el programa; aquí los presento como parte de mi aprendizaje, no como experiencia profesional.

## Trabajos terminados

| Trabajo | En qué consiste | Conceptos practicados |
| --- | --- | --- |
| [so_long](./so_long) | Juego 2D con mapas, movimiento y elementos coleccionables. | C, estructuras, validación de mapas y gráficos |
| [push_swap](./push_swap_final) | Ordenación de números mediante operaciones sobre dos pilas. | Algoritmos, estructuras de datos y optimización |
| [pipex](./pipex) | Ejecución de comandos conectados mediante una tubería. | Procesos Unix, `fork`, `execve`, `pipe` y redirecciones |
| [libft](./libft) | Biblioteca de funciones en C. | Memoria, cadenas y funciones de utilidad |
| [get_next_line](./get_next_line) | Lectura de archivos línea a línea. | Lectura con descriptores y memoria dinámica |
| [ft_printf](./ft_printf) | Implementación de formatos básicos de salida. | Funciones variádicas y conversión de formatos |

Los seis trabajos están confirmados como terminados por la autora. Ese estado académico no garantiza que cada copia publicada compile o esté libre de errores; consulta los resultados de revisión de cada directorio.

## Otros trabajos del repositorio

- [minitalk](./minitalk%20final): comunicación entre procesos mediante señales (**estado de finalización pendiente de confirmar**).
- [philo](./philo): ejercicio relacionado con hilos y sincronización (**estado de finalización pendiente de confirmar**).

> Algunos directorios pueden contener archivos de prueba o versiones de trabajo. Este repositorio refleja un proceso de aprendizaje y no pretende ser una colección de productos finales.

## Sobre 42 Madrid

42 utiliza una metodología de aprendizaje práctico, colaboración y revisión entre estudiantes (*peer-to-peer*).

## Compilación y revisión

Cada trabajo tiene sus propias instrucciones; no hay una compilación global del repositorio. Los requisitos y resultados están documentados en los README de cada directorio.

Auditoría del 11 de octubre de 2026 en Linux: Libft y ft_printf compilan; get_next_line pasó comprobaciones de lectura; push_swap pasó 44 casos de ordenación. La copia publicada de pipex presenta errores de compilación y código incompleto. so_long no pudo verificarse por faltar CMake y entorno gráfico. minitalk compila, pero no se ha confirmado su finalización; philo falla al compilar.

No hay una suite propia de CI para estos trabajos. Los tests y workflows dentro de MLX42 pertenecen a la dependencia, no validan automáticamente el juego.
