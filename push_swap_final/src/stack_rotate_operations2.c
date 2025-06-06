/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_operations2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:44:09 by bfebles-          #+#    #+#             */
/*   Updated: 2025/06/05 20:44:53 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b, bool print)
{
	rra(stack_a, false);
	rrb(stack_b, false);
	if (print)
		ft_putstr_fd("rrr\n", 1);
	if (DEBUG)
		display_stacks(stack_a, stack_b);
}
