#include "push_swap.h"

static int is_number(char *str)
{
    int i = 0;
    
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

static int is_duplicate(t_stack *stack, int num)
{
    t_node *current = stack->top;
    while (current)
    {
        if (current->value == num)
            return 1;
        current = current->next;
    }
    return 0;
}

static long atoi_long(char *str)
{
    long num = 0;
    int sign = 1;
    int i = 0;
    
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i])
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num * sign;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;
        
    t_stack *stack_a = create_stack();
    t_stack *stack_b = create_stack();
    
    if (!stack_a || !stack_b)
        return 1;
        
    for (int i = argc - 1; i > 0; i--)
    {
        if (!is_number(argv[i]))
        {
            write(2, "Error\n", 6);
            free_stack(stack_a);
            free_stack(stack_b);
            return 1;
        }
        
        long num = atoi_long(argv[i]);
        if (num > INT_MAX || num < INT_MIN || is_duplicate(stack_a, num))
        {
            write(2, "Error\n", 6);
            free_stack(stack_a);
            free_stack(stack_b);
            return 1;
        }
        
        push(stack_a, num);
    }
    
    if (!is_sorted(stack_a))
        radix_sort(stack_a, stack_b);
        
    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
}