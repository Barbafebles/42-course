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

## Verificación

Auditoría del 11 de octubre de 2026 en Linux: cliente y servidor compilan. No se ha comprobado todavía la transmisión, la concurrencia entre clientes ni todos los errores. La finalización académica está confirmada por la autora.

Pendiente de revisión técnica: la variable que comunica el manejador de señal con el bucle del cliente no usa `volatile sig_atomic_t`; la espera de confirmación no tiene tiempo límite. Estos puntos no se han modificado en la PR de documentación.
