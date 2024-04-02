#include "pipex.h"

void    execute(char *cmd, int in, int out)
{
    pid_t pid;
    pid = fork();

    if (pid == -1)
    {
        ft_error("Error en el fork");
    }
    else if (pid > 0) // padre 
    {
        // printf("El proceso hijo: PID %d\n", pid);
    }
    // redirecciono el stdin 
    if (in != -1)
    {
        if (dup2(in, STDIN_FILENO) == -1)
            ft_error("Error en redireccionar la stdin");
    }
    close (in); // cierra el fd que no necesito

}                                      