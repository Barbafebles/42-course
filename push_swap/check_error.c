/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:48:42 by barbarafebl       #+#    #+#             */
/*   Updated: 2023/09/15 20:00:59 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int check_error(char *str)
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
int	ft_strcmp(char *s1, char*s2)
{
	unsigned int	m;

	m = 0;
	while (s1[m] == s2[m] && s1[m] != '\0' && s2[m] != '\0')
	{
			m++;
	}
	return (s1[m] - s2[m]);
}

/*
int ft_strcmp(char *str1, char *str2)
{
   int i;
	
   if(!str1 || !str2)
	return 0;

   while(str1 != '\0' ||  str2 != '\0')
	{
		if(str1[i] == str2[i])
			i++;
		else 
			return 0;
	}
	return 1;	
}
*/


int main(int argc, char **argv)
{
    int	j = 1;

    while(j+1 < argc)
    {
	printf("%d", ft_strcmp(argv[j], argv[j+1]));
        //printf("%d", check_error(argv[j]));
            j++;
    }
    return(0);
}
