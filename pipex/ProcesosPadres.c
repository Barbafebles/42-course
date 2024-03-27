
// esto es solo para aprender como funcionan los procesos y fork()
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



// como se crea un proceso padre e hijo 
/*
int main()
{
    pid_t pid;
    pid = fork();
    if (pid == -1)
    {
        printf("fork() ha fallado\n");
        return (1);
    }
    
    if(pid == 0)
    {
        printf("Soy un proceso hijo: %d\n", pid);
    }
    if(pid > 0)
    {
        printf("Soy el padre y mi hijo es: %d\n", pid);
    }
}
*/


/*
// muestra como la memoria esta duplicada pero no compartida 
void    child_routine(pid_t pid, int *nb)
{
    printf(" Soy el hijo y recibo este PID del fork: %d\n", pid);
    printf("El numero es: %d\n", *nb);
}
void    parent_routine(pid_t pid, int *nb)
{
    printf(" Soy el padre. Este es el PI que recibo del Fork: %d\n", pid);
    printf("El numero es: %d\n", *nb);
}

int main(void)
{
    pid_t pid;
    int nb;

    nb = 42;
    printf("Despues del fork, el numero es: %d\n", nb);
    pid = fork(); // creo los procesos hijos
    if (pid == -1)
        return (EXIT_FAILURE);
    else if(pid == 0) 
        child_routine(pid, &nb);
    else if(pid > 0) // si el pid es mayor que 0 es el padre 
        parent_routine(pid, &nb);
    return(EXIT_SUCCESS);
}
*/

// crear una funcion que haga esperar a hijo 

int main (void)
{
    pid_t pid;
    pid = fork();

    if (pid == -1)
        return (1);
    else if (pid == 0)
    {
        printf("Hijo: soy el hijo y mi PID es: %d\n", pid);
        sleep(2);
        printf("Hijo: Listo\n");
    }
    else if (pid > 0)
    {
        printf("Padre: soy el padre y mi hijo es: %d\n", pid);
        printf("Padre: Listo\n");
    }
    return (0);
}
