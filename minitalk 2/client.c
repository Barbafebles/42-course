
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
