/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/05/02 11:35:49 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Writes a string to the specified file descriptor
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

/*
 * Checks if a character is a digit (0-9)
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
 * Checks if a character is a whitespace
 */
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

/*
 * Prints error message and exits the program
 */
void	error_exit(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(RESET, 2);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	exit(1);
}