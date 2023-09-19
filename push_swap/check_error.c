/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:48:42 by barbarafebl       #+#    #+#             */
/*   Updated: 2023/09/17 15:06:06 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int ft_isnumber(char *str)
{
    int i; 

    i = 0;
    if(str[i] == '-' && (str[i+1]>=48 && str[i+1]<=57))
        i++;
    else if(str[i] >=48 && str[i] <=57)
        i++;
    else 
        return 0;
    while(str[i] != '\0')
    {
        if(str[i] >= 48 && str[i]<= 57)
            i++;
        else 
            return 0;
    }
    return 1;
}

int ft_strcmp(char *str1, char *str2)
{
	int i;
	i = 0;
	if (!str1 || !str2)
		return 0;
	
	while(str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		
		else
			return 0;
	}
	return 1;
}

int valid_int(const char *str)
{
	int signo;
	int i;	
	
	signo = 1;
	i = 0;

	if(str[i] == '\0')
		return 0;

	if(str[i] == '-')
		signo = -1;
		i++;;
	
	long long number;

	while(str[i] != '\0')
	{
		if(str[i] < 0 || str[i] > 9)
			return 0;
		number = number * 10 + (str[i] - '0');
	if(number * signo > INT_MAX || number * signo < INT_MIN)
		return 0;
	i++;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	const char *cadena = argv[1];

	if (valid_int(cadena)) 
	{
        printf("\"%s\" es un valor válido de int.\n", cadena);
    	} 
	else 
	{
        printf("\"%s\" no es un valor válido de int.\n", cadena);
    	}

    return 0;
}

/*
int main(int argc, char **argv)
{
    int	j = 1;

    while(j+1 < argc)
    {
	printf("%d", valid_int(argv[j], argv[j+1]));
        //printf("%d", check_error(argv[j]));
            j++;
    }
    return(0);
}
*/
