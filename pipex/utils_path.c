// Funcion que encuentre 
// Agregar el path 
// Check

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned long n)
{
	unsigned long	i;

	i = 0;
	while (((unsigned char)s1[i] != '\0' || (unsigned char)s2[i] != '\0')
		&& (i < n))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

char *find_path(char **envp)
{
    int i;
    i = 0;
    while (envp[i] != NULL)
    {
        if(ft_strncmp(envp[i], "PATH", 4) == 0)
        return(&envp[i][5]);
        i++;
    }
    return (NULL);
}
