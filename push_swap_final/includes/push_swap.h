/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:20:26 by bfebles-          #+#    #+#             */
/*   Updated: 2025/06/06 15:16:46 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

# define DEBUG 0

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
	char			name;
}					t_stack;

t_stack				*init_stack(char name);
void				free_stack(t_stack *stack);

/* Stack utility functions */
void				push_to_stack(t_stack *stack, int value);
int					pop_from_stack(t_stack *stack);
int					is_stack_empty(t_stack *stack);
int					is_stack_sorted(t_stack *stack);
void				display_stacks(t_stack *stack_a, t_stack *stack_b);
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);

/* Stack operations */
void				sa(t_stack *stack_a, bool print);
void				sb(t_stack *stack_b, bool print);
void				ss(t_stack *stack_a, t_stack *stack_b, bool print);
void				pa(t_stack *stack_a, t_stack *stack_b, bool print);
void				pb(t_stack *stack_a, t_stack *stack_b, bool print);
void				ra(t_stack *stack_a, bool print);
void				rb(t_stack *stack_b, bool print);
void				rr(t_stack *stack_a, t_stack *stack_b, bool print);
void				rra(t_stack *stack_a, bool print);
void				rrb(t_stack *stack_b, bool print);
void				rrr(t_stack *stack_a, t_stack *stack_b, bool print);

/* Sorting algorithms */
void				sort_small(t_stack *stack_a, t_stack *stack_b, int size);
void				sort_three(t_stack *stack_a);
void				sort_five(t_stack *stack_a, t_stack *stack_b);
void				assign_indices(t_stack *stack_a);
void				chunk_sort(t_stack *a, t_stack *b);

/* Input parsing and validation */
int					parse_args(int argc, char **argv, t_stack *stack_a);
int					is_valid_number(char *str);
int					has_duplicates(t_stack *stack);
long				ft_atol(const char *str);
void				free_split_array(char **array);

/* Utility functions */
void				ft_putstr_fd(char *s, int fd);
int					ft_isdigit(int c);
int					ft_isspace(int c);
void				error_exit(t_stack *stack_a, t_stack *stack_b);

#endif
