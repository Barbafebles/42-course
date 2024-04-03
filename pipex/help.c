#include "pipex.h"

void execute(char *cmd[], int in, int out, char **envp) 
{
    pid_t pid;
    pid = fork();

    if (pid == -1) 
    {
        // Si falla el fork
        ft_error("Error en el fork");
    } 
    else if (pid == 0) // Proceso hijo
    {
        // Redirigir stdin si es necesario
        if (in != -1) 
        {
            if (dup2(in, STDIN_FILENO) == -1)
                ft_error("Error en redireccionar la stdin");
            close(in); // Cierra el fd que no necesito
        }
        // Redirigir stdout si es necesario
        if (out != -1) 
        {
            if(dup2(out, STDOUT_FILENO) == -1)
                ft_error("Error en la redireccion de stdout");
            close(out);
        }
        // Ejecutar el comando
        if (execve(cmd[0], cmd, envp) == -1) 
        {
            ft_error("Error en execve");
            exit(EXIT_FAILURE); // Salir si falla execve
        }
    } 
    else 
    {
        // Esperar por el proceso hijo
        waitpid(pid, NULL, 0);
    }
}

char **environ; 
int main() 
{
    // Comando a ejecutar: 'ls -l'
    char *cmd[] = {"/bin/ls", "-l", NULL};

    // No se requiere redirección, así que usamos -1 para 'in' y 'out'
    int in = -1;
    int out = -1;

    // Llama a execute con el comando, sin redirecciones y el entorno actual
    execute(cmd, in, out, environ);

    return 0;
}