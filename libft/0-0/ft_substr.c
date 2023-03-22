/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:52:18 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/20 20:20:36 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_substr(char const *s, unsigned int start, unsigned long len)






















{
    unsigned long   i;
    char            *str;

    i = 0;
    if (!s)
        return (0);
    if (start > ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s))
        len = ft_strlen(s);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (0);
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
