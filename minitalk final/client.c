/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- < bfebles-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:46:54 by bfebles-          #+#    #+#             */
/*   Updated: 2024/10/29 16:28:46 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	response;

void	ft_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;

	(void)context;
	(void)info;
	response = 1;
	if (signum == SIGUSR1)
		ft_printf("Bytes received: %d\n", i / 8);
	else if (signum == SIGUSR2)
		i++;
}

int	ft_char_to_bin(char c, int srv_pid)
{
	int	bit_idx;

	bit_idx = 7;
	while (bit_idx >= 0)
	{
		response = 0;
		if ((c >> bit_idx) & 1)
		{
			if (kill(srv_pid, SIGUSR1) == -1)
				ft_error("Error al enviar señal SIGUSR1");
		}
		else
		{
			if (kill(srv_pid, SIGUSR2) == -1)
				ft_error("Error al enviar señal SIGUSR2");
		}
		while (!response)
			usleep(100);
		bit_idx--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					srv_pid;
	int					i;

	if (ac != 3)
		ft_error("Usage:\t./client [SRV_PID] [MESSAGE]");
	srv_pid = ft_atoi(av[1]);
	if (srv_pid <= 0)
		ft_error("Invalid PID");
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = ft_sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("Sigaction error");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error("Sigaction error");
	i = 0;
	while (av[2][i])
		ft_char_to_bin(av[2][i++], srv_pid);
	ft_char_to_bin('\0', srv_pid);
	return (0);
}
