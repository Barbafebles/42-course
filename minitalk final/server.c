#include "minitalk.h"

// Función para imprimir un mensaje de error
void ft_error(const char *msg)
{
    perror(msg); // Imprime el mensaje de error relacionado con la última llamada al sistema fallida
    exit(EXIT_FAILURE); // Salir del programa en caso de error crítico
}

// Función para convertir señales en un carácter binario
void ft_bin_to_char(int sig, char *c)
{
    if (sig == SIGUSR1)
        *c = (*c << 1) | 1; // Si se recibe SIGUSR1, el bit actual es 1
    else if (sig == SIGUSR2)
        *c <<= 1; // Si se recibe SIGUSR2, el bit actual es 0
}

// Manejador de señales para el servidor
void ft_signal_handler(int signum, siginfo_t *info, void *context)
{
    static pid_t client_pid = 0;
    static char c = 0;
    static int bits_received = 0;

    (void)context;
    if (client_pid == 0)
        client_pid = info->si_pid; // Almacena el PID del cliente

    ft_bin_to_char(signum, &c); // Convierte la señal en un bit y lo agrega al carácter

    bits_received++;
    if (bits_received == 8) // Si se han recibido 8 bits, el carácter está completo
    {
        bits_received = 0;
        if (c == '\0') // Si el carácter es nulo, el mensaje ha terminado
        {
            kill(client_pid, SIGUSR1); // Enviar señal de confirmación al cliente
            client_pid = 0; // Reinicia el PID del cliente
            return;
        }
        ft_printf("%c", c); // Imprime el carácter recibido
        c = 0; // Reinicia el carácter
    }
    kill(client_pid, SIGUSR2); // Envía una señal de confirmación al cliente para indicar que se recibió un bit
}

int main(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO; // Configura para recibir información adicional sobre la señal
    sa.sa_sigaction = ft_signal_handler; // Asigna el manejador de señales

    // Establece los manejadores para SIGUSR1 y SIGUSR2
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
        ft_error("Error al establecer el manejador de señales");

    ft_printf("Servidor PID: %d\n", getpid()); // Imprime el PID del servidor

    while (1)
        pause(); // Espera las señales

    return (0);
}

