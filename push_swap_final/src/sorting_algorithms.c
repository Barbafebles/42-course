/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/05/02 13:49:04 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_three(t_stack *a)
{
    // Si hay menos de 2 o ya está ordenado, no hacer nada
    if (a->size < 2 || is_stack_sorted(a))
        return;
    // Caso de exactamente 2 elementos
    if (a->size == 2)
    {
        sa(a, true);
        return;
    }

    int x = a->top->value;
    int y = a->top->next->value;
    int z = a->top->next->next->value;

    // 1) x es el mayor
    if (x > y && x > z)
    {
        if (y < z)
            ra(a, true);
        else
        {
            sa(a, true);
            rra(a, true);
        }
    }
    // 2) y es el mayor
    else if (y > x && y > z)
    {
        if (x < z)
        {
            sa(a, true);
            ra(a, true);
        }
        else
            rra(a, true);
    }
    // 3) z es el mayor (patrón x<z<y)
    else
        sa(a, true);
}

void sort_five(t_stack *a, t_stack *b)
{
    int i;
    int min;
    int pos;
    t_node *cur;

    // Empuja dos mínimos a la pila B
    for (i = 0; i < 2; i++)
    {
        min = find_min(a);
        pos = 0;
        cur = a->top;
        while (cur->value != min)
        {
            cur = cur->next;
            pos++;
        }
        // elegir la rotación más corta
        if (pos <= a->size / 2)
            while (a->top->value != min)
                ra(a, true);
        else
            while (a->top->value != min)
                rra(a, true);
        pb(a, b, true);
    }
    // Ordena los 3 restantes en A
    sort_three(a);
    // Recupera los dos elementos de B, colocándolos correctamente
    pa(a, b, true);
    ra(a, true);
    pa(a, b, true);
    ra(a, true);
}

void sort_small(t_stack *stack_a, t_stack *stack_b, int size)
{
    if (size <= 3)
        sort_three(stack_a);
    else
        sort_five(stack_a, stack_b);
}

static void counting_sort_push(t_stack *stack_a, t_stack *stack_b, int *count)
{
    int i;
    int current;

    i = 0;
    while (i < stack_a->size)
    {
        current = stack_a->top->value;
        if (count[current] > 0)
        {
            pb(stack_a, stack_b, true);
            count[current]--;
        }
        else
            ra(stack_a, true);
        i++;
    }
}

void counting_sort(t_stack *stack_a, t_stack *stack_b)
{
    int *count;
    int min;
    int max;
    int range;
    t_node *current;

    min = find_min(stack_a);
    max = find_max(stack_a);
    range = max - min + 1;
    count = (int *)calloc(range, sizeof(int));
    if (!count)
        error_exit(stack_a, stack_b);

    current = stack_a->top;
    while (current)
    {
        count[current->value - min]++;
        current = current->next;
    }

    counting_sort_push(stack_a, stack_b, count);
    while (!is_stack_empty(stack_b))
        pa(stack_a, stack_b, true);

    free(count);
}