#include "minitalk.h"

void	ft_error(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE); // Salir si ocurre un error crítico
}


void	signal_handler(int signum)
{
	static unsigned char	c;
	static int				bits_received;

	c <<= 1;
	if (signum == SIGUSR1)
		c |= 1;
	bits_received++;
	if (bits_received == 8)
	{
		if (write(1, &c, 1) == -1)
		{
			ft_error("Error al escribir carácter");
		}
		bits_received = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Servidor PID: %d\n", pid);
	if (signal(SIGUSR1, signal_handler) == SIG_ERR)
	{
		ft_error("Error al asignar handler para SIGUSR1");
		return (1);
	}
	if (signal(SIGUSR2, signal_handler) == SIG_ERR)
	{
		ft_error("Error al asignar handler para SIGUSR2");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
