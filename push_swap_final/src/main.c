/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/05/02 12:50:13 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack('a');
	stack_b = init_stack('b');
	if (!stack_a || !stack_b)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		error_exit(NULL, NULL);
	}
	if (parse_args(argc, argv, stack_a) == -1)
		error_exit(stack_a, stack_b);
	if (has_duplicates(stack_a))
		error_exit(stack_a, stack_b);

	if (!is_stack_sorted(stack_a))
	{
		// Assign indices before choosing the sorting algorithm if stack is not sorted
		assign_indices(stack_a); 
		
		if (stack_a->size <= 5)
			sort_small(stack_a, stack_b, stack_a->size);
		else
			radix_sort(stack_a, stack_b); // Use radix_sort for larger stacks
	}

	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}