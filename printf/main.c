#include "ft_printf.h"

int main(void)
{
  int   i;
  int   j;
  char  *s = "hola esto es una prueba";
  i = ft_printf("Holaa  %c %s %p %x %X %d %d %u %%\n", 'A', s, s, 255, 255, 250, 343, -343);
  j = printf("Holaa  %c %s %p %x %X %d %d %u %%\n", 'A', s, s, 255, 255, 250, 343, -343);
	ft_printf("mio:\t\t%i\noriginal:\t%i", i, j);
}
