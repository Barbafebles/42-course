#include "push_swap.h"

void sa(t_stack *stack_a)
{
    if (!stack_a->top || !stack_a->top->next)
        return;
    int temp = stack_a->top->value;
    stack_a->top->value = stack_a->top->next->value;
    stack_a->top->next->value = temp;
    write(1, "sa\n", 3);
}

void sb(t_stack *stack_b)
{
    if (!stack_b->top || !stack_b->top->next)
        return;
    int temp = stack_b->top->value;
    stack_b->top->value = stack_b->top->next->value;
    stack_b->top->next->value = temp;
    write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
    write(1, "ss\n", 3);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_b->top)
        return;
    push(stack_a, pop(stack_b));
    write(1, "pa\n", 3);
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a->top)
        return;
    push(stack_b, pop(stack_a));
    write(1, "pb\n", 3);
}

void ra(t_stack *stack_a)
{
    if (!stack_a->top || !stack_a->top->next)
        return;
    t_node *last = stack_a->top;
    while (last->next)
        last = last->next;
    last->next = stack_a->top;
    stack_a->top = stack_a->top->next;
    last->next->next = NULL;
    write(1, "ra\n", 3);
}

void rb(t_stack *stack_b)
{
    if (!stack_b->top || !stack_b->top->next)
        return;
    t_node *last = stack_b->top;
    while (last->next)
        last = last->next;
    last->next = stack_b->top;
    stack_b->top = stack_b->top->next;
    last->next->next = NULL;
    write(1, "rb\n", 3);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write(1, "rr\n", 3);
}