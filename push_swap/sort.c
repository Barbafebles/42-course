
#include "push_swap.h"

static void	sort_three_case_one(t_stack *stack)
{
	sa(stack);
}

static void	sort_three_case_two(t_stack *stack)
{
	sa(stack);
	rra(stack);
}

static void	sort_three_case_three(t_stack *stack)
{
	ra(stack);
}

static void	sort_three_case_four(t_stack *stack)
{
	sa(stack);
	ra(stack);
}

static void	sort_three_case_five(t_stack *stack)
{
	rra(stack);
}

static void	sort_three(t_stack *stack)
{
	int first, second, third;
	first = stack->top->value;
	second = stack->top->next->value;
	third = stack->top->next->next->value;
	if (first > second && second < third && first < third)
		sort_three_case_one(stack);
	else if (first > second && second > third)
		sort_three_case_two(stack);
	else if (first > second && second < third && first > third)
		sort_three_case_three(stack);
	else if (first < second && second > third && first < third)
		sort_three_case_four(stack);
	else if (first < second && second > third && first > third)
		sort_three_case_five(stack);
}

static void	handle_remaining(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
	{
		pa(stack_a, stack_b);
		if (stack_a->top->value > stack_a->top->next->value)
			sa(stack_a);
	}
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	if (stack_a->size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			sa(stack_a);
		return ;
	}
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
		return ;
	}
	while (stack_a->size > 3)
		pb(stack_b, stack_a);
	sort_three(stack_a);
	handle_remaining(stack_a, stack_b);
}
