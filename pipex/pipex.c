/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:45:23 by barbafebles       #+#    #+#             */
/*   Updated: 2024/04/15 13:58:06 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parse(int argc, char *argv[], char ***cmd1, char ***cmd2, char **infile, char **outfile)
{
    if (argc != 5)
    {
        ft_error("Numero incorrecto de argumentos");
    }
    *cmd1 = ft_split(argv[2], ' '); // argv[2] y argv[3]
    *cmd2 = ft_split(argv[3], ' '); 

    *infile = argv[1];
    *outfile = argv[4];

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


/*
    Crear una tubería con pipe.
    Usar fork para crear un proceso hijo que ejecute el primer comando.
    Configurar las redirecciones adecuadas con dup2.
    Ejecutar el comando con execve.
    Repetir un proceso similar para el segundo comando.
*/


void exec_comd1(int *pipefd, int infile_fd, char **cmd, char **envp)
{
    pid_t pipe;
    pipe = fork();
    if (pipe == -1)
    {
        ft_error("Error creando el fork");
    }
    if (pipe == 0)
    {
        // Estamos en el proceso hijo
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
