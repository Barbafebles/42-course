
#include "pipex.h"

/*
open 
int ft_open(const char *file, int flags);
file = el archivo que quiero abrir 
flags = como se abre el archivo 

int main()
{
    int fd = open("datos.txt", O_RDONLY);
    if (fd == -1)
        ft_error ("Error");
    printf("%d", fd);
    return 0;
}
*/

//----------------------------------------------------------------------------------------------------------------------

/*
close 
int close(int fd);
fd = el archivo que se quiere cerrar 
'0' la funcion acabo con exito 
'-1' ocurrio un error 
devuelve 3 al ser el valor mas bajo disponible

int main()
{
    printf("Abriendo el archivo..\n");

    int fd = open("datos.txt", O_RDONLY);
    if (fd == -1)
    {
        ft_error("Error abriendo el archivo");
        return 1;
    }
    printf("Archivo abierto:, fd = %d\n", fd);
        sleep(2);
    printf("Cerrando el archivo...\n");
    if (close(fd) == -1)
    {
        ft_error("Fallo el close");
            return 1;
    }

    printf("Archivo cerrado...\n");
    return (0);
}
*/

//------------------------------------------------------------------------------------------------------------------------

/*
read 
ssize_t read(int fd, void *buf, size_t count);
fd = es el archivo que queremos leer. 
*buf = un puntero donde lo que leamos en read lo almacenamiento, el bufer debe ser suficiente para para contener
el 'count' bytes. 
'count' es el numero de bytes a leer.   

int main()
{
    int fd; 
    char    buffer[234];
    ssize_t bytes;

    fd = open("datos.txt", O_RDONLY);
    if(fd == -1)
    {
        ft_error("Error en open");
    }
    bytes = read(fd, buffer, sizeof(buffer));
    if (bytes == -1)
    {
        ft_error("Error en read");
        close(fd);
        return (EXIT_FAILURE);
    }
    printf("Se leyo todo correctamente: %ld\n", bytes);
    close(fd);
    return (0);
}
*/

//----------------------------------------------------------------------------------------------------------------------------------------

/*
write
ssize_t write(int fd, const void *buf, size_t count);
fd = el archivo que queremos leer
buf = un puntero al buffer que contiene los datos que deseas escribir. Este buffer debe contener al menos 'count' bytes de datos 
count = el número de bytes a escribir desde el buffer buf al descriptor de archivo fd

unsigned int ft_strlen(const char *s)
{
    int len = 0;
    while (*s != '\0')
    {
        len++;
        s++;
    }
    return len;
}

int main()
{
    int fd;
    char *mensage;
    ssize_t  bytes;

    mensage = " ";
    fd = open("datos.txt", O_RDWR, O_CREAT);
    if (fd == -1)
        ft_error("Error en open");
    bytes = write(fd, mensage, ft_strlen(mensage));
    if (bytes == -1)
    {
        ft_error("Error al escribir en el archivo");
        close(fd);
        return (EXIT_FAILURE);
    }
    printf("Se escribireron %zd\n", bytes);
    return (0);
}
*/

//-------------------------------------------------------------------------------------------------------------------------------------------

/*
malloc 
void *malloc(size_t size);
size = es el tamano de bloques [bytes] de memoria que se le quiere asignar
Retorna un puntero: A la memoria asignada si la asignación fue exitosa. Este puntero es de tipo void*,
lo que significa que puede ser convertido a cualquier tipo de puntero.

int main()
{
    int *ptr = NULL;
    int n = 5;
    int i;
    ptr = ((int*)malloc(n * sizeof(int)));

    if (ptr == 0)
    {
        ft_error("Fail");
            return 1;
    }
    // inicializo el array
    while (i < n)
    {
        ptr[i] = i;
        i++;
    }
    // reiniciamos el array a 0
    i = 0;
    while( i < n)
    {
        printf("%d\n", ptr[i]);
        i++;
    }
    free(ptr);
    return 0;
}
*/

//----------------------------------------------------------------------------------------------------------------------------------------

/*
free 
void free(void *ptr)

Codigo de arriba

*/

//----------------------------------------------------------------------------------------------------------------------------------------------

/*
perror 
void perror(const char *str)
str = contiene un mensaje customizado que va a ser ejecutado despues del error 
No retorna nada.

// funcion

void    ft_error(char *s)
{
    perror(s);
    exit(EXIT_FAILURE);
}

int main()
{
    int i = 10;

    if(i > 5)
    {
        printf("El nunmero es: %d\n", i);
        ft_error("Es mayor que 5");
        return (0);
    }
    else if (i <= 5)
    {
        printf("Se cumple el if: %d\n", i);
        return (0);
    }
}
*/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
errno 
Es una variable definida en C 

int main()
{
    const char *file;
    file = "pepe.txt";
    int fd; 
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        printf("Valor erno %d\n", errno);
        ft_error("Error abriendo el archivo");
    }
    else 
    {
        close(fd);
    }
    return (0);
}
*/

//-----------------------------------------------------------------------------------------------------------------------------------------------------

/*
strerror 
char *strerror(int errnum)
errnum = al numero del error (usualmente errno)

int main()
{   
    int fd = open("noexistente.txt", O_RDONLY);
    if (fd == -1)
    {
        char *p = strerror(errno);
        printf("Error: %s\n", p);
    }
    return (0);
}
*/

// ---------------------------------------------------------------------------------------------------------------------------------------

/*
access
int access(const char *pathname, int how);
pathname =  Es un puntero a una cadena de caracteres que especifica la ruta al archivo cuyos permisos de acceso deseas verificar.
how =  Es un entero que especifica el tipo de acceso que deseas verificar para el archivo.

int main()
{
    const char *path = "noexiste.txt";
    if (access(path, F_OK) == -1)
    {
        ft_error("Error al acceder");
    }
    else
    {
        printf("El archivo %s, se puede leer\n", path);
    }
    return (0);
}
*/

// ------------------------------------------------------------------------------------------------------------------------------------------

/*
dup 
int dup(int oldfd);
oldfd = descriptor de archivo antiguo cuya copia se va a crear

int main()
{
    int fd;
    int new;

    fd = open("datos.txt", O_RDONLY);
    if (fd == -1)
    {
        ft_error("Error abriendo el archivo");
    }
    // duplicar el fd
    new = dup(fd);
    if (new == -1)
    {
        ft_error("Error al duplicar el fd");
    }
    int c = dup(new);
    if (c == -1)
    {
        ft_error("no se puede duplicar mas");
    }
    printf("el fd viejo: %d\n", fd);
    printf("el fd nuevo :%d\n", new);
    printf("el tercero :%d\n", c);

    //cierro los fd ya usados 
    close(fd);
    close(new);
    close(c);
}
*/

//-----------------------------------------------------------------------------------------------------------------------------------

/*
dup2
int dup2(int oldfd, int newfd);
oldfd: el fd viejo
newfd el fd nuevo que vas a copiar con dup2() 

int main()
{
    int newfd;
    int oldfd;

    oldfd = open("datos.txt", O_RDONLY);
    if (oldfd == -1)
    {
        ft_error("Error al abrir el fd");
        return (1);
    }
    close (0);
    newfd = dup2(oldfd, 0);
    if (newfd == -1)
    {
        ft_error("Error duplicando el fd");
    }
    printf("El old: %d\n", oldfd);
    printf("El nuevo %d\n", newfd);
    close (oldfd);

    return (0);
}
*/

//-------------------------------------------------------------------------------------------------------------------------------

/*
execve
int execve(const char* path, const char* argv[], char* const envp[])


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

*/

//----------------------------------------------------------------------------------------------------------------------------------

/*
exit 
void exit(int status);

int main()
{
    int fd;
    fd = open("datos.txt", O_RDONLY);
    if (fd == -1)
    {
        ft_error("Error al abrir el fd");
        exit (1);
    }
    else if (fd)
    {
        printf("El fd: %d\n", fd);
    }
    return (0);
}
*/

//-------------------------------------------------------------------------------------------------------------------------------------

/*
fork
void forkexample()
{
    pid_t p;
    p = fork();
    if (p < 0)
    {
      perror("fork fail");
      exit(1);
    }
    // proceso hijo por que devuelve 0
    else if ( p == 0)
        printf("Hello from Child!\n");
 
    // proceso padre 
    else
        printf("Hello from Parent!\n");
}
int main()
{
    forkexample();
    return 0;
}
*/

//-----------------------------------------------------------------------------------------------------------------------

/*
pipe 
int pipe(int fds[2]);

Parameters :
fd[0] will be the fd(file descriptor) for the 
read end of pipe.
fd[1] will be the fd for the write end of pipe.
Returns : 0 on Success.
-1 on error.

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

//------------------------------------------------------------------------------------------------------------------------------------

/*
unlink
int unlink(const char *pathname)
pathname = ruta del archivo que quiero eliminar 

si tiene exito devuelve 0 sino devuelve -1 y errno establece el 

me elimina el .txt

int main()
{
    if (unlink("datos.txt") == -1)
    {
        ft_error("Error eliminando el archivo");
    }
    
    printf("Archivo eliminado con exito\n");
    return (0);
}
*/

//--------------------------------------------------------------------------------------------------------------------------------------

/*
wait 


int main()
{
    pid_t pid;
    pid = fork();
    if (pid == -1)
    {
        ft_error("Fallo en crear el fork");
    }
    if (pid == 0) // proceso hijo
    {
        wait(NULL);
        printf("Soy el hijo\n", getpid());
    }
    if (pid > 0)
    {
        printf("Soy el proceso padre voy primero\n", getppid());
    }
    return (0);
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------

/*
waitpid
pid_t waitpid(pid_t pid, int *status, int options);
pid = ID del proceso 
*status = variable entera donde wairpid almacena el estado de salida del padre 
options = banderas que cambian con waitpid 

#include <sys/wait.h> // Asegúrate de incluir esta biblioteca para usar waitpid()

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == -1)
    {
        ft_error("Fallo en crear el fork");
    }
    if (pid == 0) // proceso hijo
    {
        printf("Soy el hijo\n", getpid());
    }
    else // proceso padre
    {
        int status;
        waitpid(pid, &status, 0); // El proceso padre espera al hijo especificado por pid
        printf("Soy el proceso padre voy primero\n", getppid());
    }
    return (0);
}
*/

//--------------------------------------------------------------------------------------------------------------------------------------

/*
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
*/
