
#include "minitalk.h"

void	ft_error(const char *msg)
{
	perror(msg);
}

void	ft_sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit_count;

	(void)context;
	(void)info;
	if (signum == SIGUSR1)
		ft_printf("Bytes received: %d\n", bit_count / 8);
	else if (signum == SIGUSR2)
		bit_count++;
}

void	send_char_as_signals(char c, pid_t server_pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_error("Error al enviar SIGUSR1");
				return ;
			} // Enviar bit 1
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_error("Error al enviar SIGUSR2");
				return ;
			} // Enviar bit 0
		}
		usleep(SLEEP_DURATION);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;
	int					i;

	if (argc != 3)
		return (ft_error("Uso: ./client <PID_servidor> <mensaje>"), 1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (ft_error("PID inválido"), 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = ft_sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("Error al asignar handler para SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error("Error al asignar handler para SIGUSR2");
	i = 0;
	while (argv[2][i])
		send_char_as_signals(argv[2][i++], server_pid);
	// Enviar carácter nulo para indicar el fin del mensaje
	send_char_as_signals('\0', server_pid);
	return (0);
}
