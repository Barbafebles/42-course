
// esto es solo para aprender como funcionan los procesos y fork()
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include "pipex.h"


//-----------------------------------------------------------------------------------------------------------------
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


//----------------------------------------------------------------------------------------------------------------------------
/*
// muestra como la memoria esta duplicada pero no compartida 
void    child_routine(pid_t pid, int *nb)
{
    printf(" Soy el hijo y recibo este PID del fork: %d\n", pid);
    printf("El numero es: %d\n", *nb);
}
void    parent_routine(pid_t pid, int *nb)
{
    printf(" Soy el padre. Este es el PI que recibo de Hijo: %d\n", pid); 
    printf("El numero es: %d\n", *nb);
}

int main(void)
{
    pid_t pid;
    int nb; 

    nb = 42; // este es el numero que se va a compartir entre los procesos
    printf("Antes del fork, el numero es: %d\n", nb);
    pid = fork(); // creo los procesos hijos
    if (pid == -1)
        return (EXIT_FAILURE);
    else if(pid == 0) 
        child_routine(pid, &nb);
    else if(pid > 0) // el padre
        parent_routine(pid, &nb);
    return(EXIT_SUCCESS);
}
*/

//----------------------------------------------------------------------------------------------------------------------------------------------
/*
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
*/
 //--------------------------------------------------------------------------------------------------------------------------------
 // Evitar procesos zombies 
/*
 int main ()
 {
    pid_t pid;

    pid = fork();
    if(pid == -1)
        return (EXIT_FAILURE);
    else if(pid == 0)
    {
        printf("Soy el proceso hijo. Mi PID interno es: %d\n", pid);
        printf("Hijo listo!\n");
    }
    else if (pid > 0)
    {
        printf("Soy el proceso padre. Mi PID es: %d y el PID de mi hijo es: %d\n", getpid(), pid);
        printf("Padre listo!\n");  // Un loop infinito, el padre nunca acaba.
        while (1)
            usleep(1);
    }
    return (0);
}
*/
// -----------------------------------------------------------------------------------------------------------------------------
// Aprender sobre wait y waitpid. Los prototipos son: 
// pid_t wait(int *status)
// pid_t waitpid(pid_t pid, int *status, int options)


//----------------------------------------------------------------------------------------------------------------------------------

// Como crear tuberias 
/*
int pipe(int pipefd[2]) 
 
el pid[0] es final de lectura
el pid[1] es final de escritura

si da fallo devuelve -1 
*/
/*
int ft_strlen(char *s)
{
    int i = 0;
    while(s[i] != '\0')
        i++;
    return (i);
}

void    writestr(int fd, const char *str)
{
    write(fd, str, ft_strlen(str));
}

int main()
{
    int pipefd[2]; // donde guardo los pipe fd [0]read [1]write
    pid_t   pid; // donde guardo el fork value 
    char    buf; // donde vamos a guardar los caracteres read by read 

// creamos un pipe donde vamos a guardar los fd 
    if (pipe(pipefd) == -1) // 
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

// creamos el fork 
    pid = fork();
    if (pid == -1)
    {
        ft_error("Fork");
    }
    else if (pid == 0) // proceso hijo 
    {
        // cerrar el extremo del pipe de escritura
        close(pipefd[1]);
        writestr(STDOUT_FILENO, "Hijo: cual es le secreto en este pipe?\n");
        writestr(STDOUT_FILENO, "Hijo: \"");
        // Leer los caracteres del pipe uno por uno 
        while(read(pipefd[0],&buf,1) > 0)
        {
            // Escribir el carácter leído en la salida estándar
            write(STDOUT_FILENO, &buf, 1);
        }
        writestr(STDOUT_FILENO, "\"\n");
        writestr(STDOUT_FILENO, "Hijo: Ohh wow tu eres mi padre \n");
        // cerrar el proceso 
        close(pipefd[0]);
        exit(EXIT_FAILURE);
    }

    else // proceso padre 
    {
        // cierro la lectura 
        close(pipefd[0]);
        writestr(STDERR_FILENO, "Padre: Estoy escribiendo un secreto en este pipe\n");
        // escribimos dentro del pipe
        writestr(pipefd[1], "\e[33mYo soy tu padre!\e[0m");
        // Cierra el final de escritura de la tubería (el lector verá EOF)
        close(pipefd[1]);
        //esperamos al hijo 
        wait(NULL);
        writestr(STDOUT_FILENO, "Padre: hola hijo\n");
        exit(EXIT_SUCCESS);
    }

}
*/