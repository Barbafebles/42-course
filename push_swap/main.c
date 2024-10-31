
#include "push_swap.h"

static int	check_duplicates(int argc, char **argv, int i)
{
	int	j;

	j = i + 1;
	while (j < argc)
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			return (0);
		j++;
	}
	return (1);
}

static int	validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_input(argv[i]) || !check_duplicates(argc, argv, i))
			return (0);
		i++;
	}
	return (1);
}

static int	init_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = create_stack();
	*stack_b = create_stack();
	if (!*stack_a || !*stack_b)
		return (0);
	return (1);
}

static void	fill_stack(t_stack *stack_a, int argc, char **argv)
{
	int	i;

	for (i = argc - 1; i > 0; i--)
		push(stack_a, ft_atoi(argv[i]));
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!validate_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!init_stacks(&stack_a, &stack_b))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	fill_stack(stack_a, argc, argv);
	if (!is_sorted(stack_a))
	{
		if (stack_a->size <= 5)
			sort_small(stack_a, stack_b);
		else
			sort_large(stack_a, stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
