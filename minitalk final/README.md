# minitalk — 42 Madrid

**Estado:** terminado, confirmado por la autora. Trabajo formativo en C para enviar mensajes entre un cliente y un servidor usando señales Unix.

## Conceptos

Procesos, PID, `SIGUSR1`, `SIGUSR2`, codificación bit a bit y confirmación de recepción. El servidor muestra su PID y recibe el texto enviado por el cliente.

## Compilar y ejecutar

Desde este directorio, con Make y un compilador C:

```sh
make
./server
```

En otra terminal, sustituye `12345` por el PID que muestra el servidor:

```sh
./client 12345 "Hola DAM"
```

Usa únicamente el PID del servidor de prueba. Finaliza el servidor con Ctrl+C. Las bibliotecas Libft y ft_printf están incluidas.

