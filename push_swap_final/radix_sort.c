#include "push_swap.h"

int get_max_bits(t_stack *stack)
{
    int max = INT_MIN;
    t_node *current = stack->top;
    
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    
    int bits = 0;
    while (max > 0)
    {
        bits++;
        max >>= 1;
    }
    return bits;
}

void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int max_bits = get_max_bits(stack_a);
    int size = stack_a->size;
    
    for (int bit = 0; bit < max_bits; bit++)
    {
        for (int j = 0; j < size; j++)
        {
            int num = stack_a->top->value;
            if ((num >> bit) & 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        
        while (stack_b->size > 0)
            pa(stack_a, stack_b);
    }
}