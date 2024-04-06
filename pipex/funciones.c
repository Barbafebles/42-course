
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
*/

int main() 
{ 
    int file_desc = open("datos.txt",O_WRONLY | O_APPEND); 
      
    // here the newfd is the file descriptor of stdout (i.e. 1) 
    dup2(file_desc, 1) ;  
          
    // All the printf statements will be written in the file 
    // "tricky.txt" 
    printf("I will be printed in the file tricky.txt\n"); 
      
    return 0; 
 
}