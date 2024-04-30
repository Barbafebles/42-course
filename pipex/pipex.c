/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbafebles <barbafebles@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:45:23 by barbafebles       #+#    #+#             */
/*   Updated: 2024/04/30 15:35:30 by barbafebles      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parse(int argc, char *argv[], char **cmd1, char **cmd2, char **infile, char **outfile)
{
    // se comprueba que el numero de argumentos es igual a 5
    if (argc != 5)
    {
        ft_error("Numero incorrecto de argumentos");
    }
    // se comprueba que argv[1], argv[2], argv[3] y argv[4] no son NULL antes de usarlos
    if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] == NULL)
    {
        ft_error("Argumento(s) no proporcionado(s)");
    }
    // se separaan los argumentos que pasaran por el pipex
    *cmd1 = ft_split(argv[2], ' '); // argv[2] y argv[3]
    *cmd2 = ft_split(argv[3], ' '); 
    // asignacion de los argumentos 1 y 4 (nombres de entrada y salida)
    *infile = argv[1];
    *outfile = argv[4];
    // si cmd1 y cmd2 es igual a NULL devuelve error 
    if (*cmd1 == NULL || *cmd2 == NULL)
    {
        ft_error("Error al parseo de los argumentos");
    }
}

/*
int main(int argc, char *argv[])
{
    char **cmd1;
    char **cmd2;
    char *infile;
    char *outfile;

    parse(argc, argv, &cmd1, &cmd2, &infile, &outfile);

    // Imprime los comandos y los nombres de los archivos para verificar que se han parseado correctamente
    // Esta sección necesita ajuste para imprimir correctamente, dado que cmd1 y cmd2 son arreglos de cadenas.
    printf("Comando 1: %s\n", cmd1[0]); // Solo imprime el primer elemento para prueba
}
*/
//--------------------------------------------------------------------------------------------------------------------------

// Ejecutar el primer comando. Crea proceso fork 
void exec_comd1(int *pipefd, char **cmd, char **envp)
{
    pid_t piped;
    piped = fork(); // copia del proceso actual 
    if (piped == -1)
    {
        ft_error("Error creando el fork");
    }
    if (piped == 0) // hijo 
    {
        // Redirigir la salida estándar al extremo de escritura de la tubería
        if (dup2(pipefd[1], STDOUT_FILENO) == -1)
        {
            ft_error("Error con dup2");
        }
        // Cerrar los descriptores de archivo que ya no necesitamos
        close(pipefd[0]);
        close(pipefd[1]);
        // Ejecutar el comando
        if (execve(cmd[0], cmd, envp) == -1)
        {
            ft_error("Error con execve");
        }
    }
}

void exec_cmd2(int *pipefd, char **cmd, char **envp)
{
    pid_t pipe;
    pipe = fork();// copia proceso actual 
    if (pipe == -1)
    {
        ft_error("Error creando el fork");
    }
    if (pipe == 0) // hijo 
    {
        // extremo de de lectura 
        if (dup2(pipefd[0], STDIN_FILENO) == -1)
        {
            ft_error("Error con dup2");
        }
        close(pipefd[1]);
        close(pipefd[0]);
        if (execve(cmd[0], cmd, envp) == -1)
        {
            ft_error("Error");
        }
    }
}
