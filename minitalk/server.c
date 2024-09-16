/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:20:21 by barbarafebl       #+#    #+#             */
/*   Updated: 2024/09/16 14:06:51 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int signum)
{
    static unsigned char c = 0;
    static int bits_received = 0;

    c <<= 1;
    if (signum == SIGUSR1)
        c |= 1;
    bits_received++;

    if (bits_received == 8)
    {
        write(1, &c, 1);
        bits_received = 0;
        c = 0;
    }
}

int main(void)
{
    pid_t pid = getpid();
    ft_printf("Servidor PID: %d\n", pid);

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while (1)
        pause();

    return 0;
}
