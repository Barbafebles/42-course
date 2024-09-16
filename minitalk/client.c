/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:20:09 by barbarafebl       #+#    #+#             */
/*   Updated: 2024/09/16 14:08:06 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_char_as_signals(char c, pid_t server_pid)
{
    int i;

    i = 8;
    while (i--)
    {
        if ((c >> i) & 1)
            kill(server_pid, SIGUSR1); // Enviar bit 1
        else
            kill(server_pid, SIGUSR2); // Enviar bit 0
        usleep(500);
    }
}

int main(int argc, char **argv)
{
    pid_t server_pid;
    char *message;
    int i;

    if (argc != 3)
    {
        write(1, "Uso: ./cliente <PID_servidor> <mensaje>\n", 40);
        return 1;
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

    return 0;
}

