/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:00:00 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/06 13:20:00 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <string.h> // Para strcmp
#include <stdlib.h> // Para malloc, realloc, free
#include <unistd.h> // Para read, write, STDIN_FILENO

#define BUFFER_SIZE 42 // Para read_line_from_stdin

// Reads a line from STDIN_FILENO. Returns NULL on EOF or error.
static char	*read_line_from_stdin(void)
{
	char	*line_buffer;
	char	single_char_buff[1];
	int		bytes_read;
	int		buffer_capacity;
	int		line_len;

	buffer_capacity = BUFFER_SIZE;
	line_buffer = (char *)malloc(buffer_capacity);
	if (!line_buffer)
		return (NULL);
	line_len = 0;
	bytes_read = read(STDIN_FILENO, single_char_buff, 1);
	while (bytes_read > 0)
	{
		if (line_len + 1 >= buffer_capacity)
		{
			buffer_capacity *= 2;
			char *temp_buffer = (char *)realloc(line_buffer, buffer_capacity);
			if (!temp_buffer)
			{
				free(line_buffer);
				return (NULL);
			}
			line_buffer = temp_buffer;
		}
		line_buffer[line_len++] = single_char_buff[0];
		if (single_char_buff[0] == '\n')
			break ;
	}
	if (bytes_read <= 0 && line_len == 0)
	{
		free(line_buffer);
		return (NULL);
	}
	line_buffer[line_len] = '\0';
	return (line_buffer);
}

static int	execute_instruction(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (strcmp(line, "sa\n") == 0)
		sa(stack_a, false);
	else if (strcmp(line, "sb\n") == 0)
		sb(stack_b, false);
	else if (strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b, false);
	else if (strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b, false);
	else if (strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, false);
	else if (strcmp(line, "ra\n") == 0)
		ra(stack_a, false);
	else if (strcmp(line, "rb\n") == 0)
		rb(stack_b, false);
	else if (strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b, false);
	else if (strcmp(line, "rra\n") == 0)
		rra(stack_a, false);
	else if (strcmp(line, "rrb\n") == 0)
		rrb(stack_b, false);
	else if (strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b, false);
	else
	{
		// Handle lines that might not have \n (e.g. last line from push_swap)
		if (strlen(line) > 0 && line[strlen(line) - 1] != '\n')
		{
			if (strcmp(line, "sa") == 0 && strlen(line) == 2)
				sa(stack_a, false);
			else if (strcmp(line, "sb") == 0 && strlen(line) == 2)
				sb(stack_b, false);
			else if (strcmp(line, "ss") == 0 && strlen(line) == 2)
				ss(stack_a, stack_b, false);
			else if (strcmp(line, "pa") == 0 && strlen(line) == 2)
				pa(stack_a, stack_b, false);
			else if (strcmp(line, "pb") == 0 && strlen(line) == 2)
				pb(stack_a, stack_b, false);
			else if (strcmp(line, "ra") == 0 && strlen(line) == 2)
				ra(stack_a, false);
			else if (strcmp(line, "rb") == 0 && strlen(line) == 2)
				rb(stack_b, false);
			else if (strcmp(line, "rr") == 0 && strlen(line) == 2)
				rr(stack_a, stack_b, false);
			else if (strcmp(line, "rra") == 0 && strlen(line) == 3)
				rra(stack_a, false);
			else if (strcmp(line, "rrb") == 0 && strlen(line) == 3)
				rrb(stack_b, false);
			else if (strcmp(line, "rrr") == 0 && strlen(line) == 3)
				rrr(stack_a, stack_b, false);
			else
				return (1); // Invalid instruction (no newline, no match)
		}
		else // Line ends with \n but didn't match, or other invalid format (e.g. empty line from input)
		{
			return (1); // Invalid instruction
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	int		exec_ret;

	if (argc < 2)
		return (0);
	stack_a = init_stack('a');
	stack_b = init_stack('b');
	if (!stack_a || !stack_b)
	{
		// error_exit handles NULL stacks, but good practice to check before use
		free_stack(stack_a); // Handles NULL
		free_stack(stack_b); // Handles NULL
		ft_putstr_fd("Error\n", 2); // Minimal error for init failure
		exit(1);
	}
	if (parse_args(argc, argv, stack_a) == -1 || has_duplicates(stack_a))
	{
		// error_exit in parse_args or has_duplicates should handle freeing and message
		// If they don't, this is a fallback:
		// Ensure stacks are freed if error_exit isn't called or doesn't exit
		// error_exit in the project is expected to print "Error\n" and exit(1)
		// So, direct exit here might not be needed if error_exit is robust.
		// However, to be absolutely safe with this checker:
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1); 
	}
	
	line = read_line_from_stdin();
	while (line)
	{
		// Skip empty lines or lines only containing a newline character
		if (line[0] == '\0' || (line[0] == '\n' && line[1] == '\0'))
		{
			free(line);
			line = read_line_from_stdin();
			continue;
		}

		exec_ret = execute_instruction(line, stack_a, stack_b);
		
		if (exec_ret != 0)
		{
			free(line);
			ft_putstr_fd("Error\n", 2); // Error for invalid instruction
			free_stack(stack_a);
			free_stack(stack_b);
			exit(1);
		}
		free(line);
		line = read_line_from_stdin();
	}

	if (is_stack_sorted(stack_a) && is_stack_empty(stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
		
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
run_in_bash_session('\n# Overwrite checker_main.c to ensure it is clean\necho "Overwriting checker_main.c with the final cleaned version."\n\n# Recompilar el proyecto (push_swap y checker)\nmake -C push_swap_final clean && make -C push_swap_final all\n\n# Ejecutar el script de prueba\npython3 test_runner.py\n')
