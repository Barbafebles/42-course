// agrc argument count 
// argv argument vector 
// envp rutas del entorno 

#include <stdio.h>
int main (int argc, char *argv[])
 {
    for(int i = 0;i < argc; i++)
    {
        printf("argumento %d, %s\n son: %d", i, argv[i], argc);
    }
    return 0;
 }

