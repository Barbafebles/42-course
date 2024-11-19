#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    if (!stack->top)
        return 1;
        
    t_node *current = stack->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    write(1, "Stack A: ", 9);
    t_node *current = stack_a->top;
    while (current)
    {
        char num[12];
        int len = 0;
        int temp = current->value;
        
        if (temp == 0)
            write(1, "0 ", 2);
        else
        {
            if (temp < 0)
            {
                write(1, "-", 1);
                temp = -temp;
            }
            while (temp)
            {
                num[len++] = temp % 10 + '0';
                temp /= 10;
            }
            while (--len >= 0)
                write(1, &num[len], 1);
            write(1, " ", 1);
        }
        current = current->next;
    }
    write(1, "\nStack B: ", 10);
    current = stack_b->top;
    while (current)
    {
        char num[12];
        int len = 0;
        int temp = current->value;
        
        if (temp == 0)
            write(1, "0 ", 2);
        else
        {
            if (temp < 0)
            {
                write(1, "-", 1);
                temp = -temp;
            }
            while (temp)
            {
                num[len++] = temp % 10 + '0';
                temp /= 10;
            }
            while (--len >= 0)
                write(1, &num[len], 1);
            write(1, " ", 1);
        }
        current = current->next;
    }
    write(1, "\n", 1);
}