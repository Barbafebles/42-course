
#include "minitalk.h"

void ft_error(const char *msg)
{
    perror(msg);
}

void send_char_as_signals(char c, pid_t server_pid)
{
    int i;

    i = 8;
    while (i--)
    {
        if ((c >> i) & 1)
        {
            if (kill(server_pid, SIGUSR1) == -1)
            {
                ft_error("Error al enviar SIGUSR1");
                return;
            } // Enviar bit 1
        }
        else
        {
            if (kill(server_pid, SIGUSR2) == -1)
            {
                ft_error("Error al enviar SIGUSR2");
                return;
            } // Enviar bit 0
        }
        usleep(SLEEP_DURATION);
    }
}

int main(int argc, char **argv)
{
    pid_t server_pid;
    char *message;
    int i;

    if (argc != 3)
    {
        ft_error("Uso: ./client <PID_servidor> <mensaje>");
        return (1);
    }

    server_pid = ft_atoi(argv[1]);
    message = argv[2];

    i = 0;
    while (message[i])
    {
        send_char_as_signals(message[i], server_pid);
        i++;
    }

    // Enviar carácter nulo para indicar el fin del mensaje
    send_char_as_signals('\0', server_pid);

    return (0);
}
