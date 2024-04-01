#include "pipex.h"

int var = 42;

int main(void)
{
    pid_t pid;

    printf("El proceso empieza:  PID: %d\n", getpid());
    pid = fork(); 

    printf("Este proceso el nuevo PID %d valor PI valor pid: %d", getpid(), pid); // esta se ejecuta dos veces una el padre y el otro el hijo son dos PID diferentes 

    if (pid > 0) // se ejecuta el padre 
    {
        var = 42;
    }
    else if (pid == 0) // se ejecuta el hijo 
    {
        var = 33; 
    }
    else // error 
    {
    }
    while (1)
    {
        sleep(2);
        printf("Proceso PID = %d , var = %d ejecutandose \n", getpid(), var);
    }
    return (0);
}
