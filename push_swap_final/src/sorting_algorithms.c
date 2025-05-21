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

// Helper function for bubble sort (not part of public API)
static void bubble_sort(int *arr, int size)
{
    int i;
    int j;
    int temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void assign_indices(t_stack *stack_a)
{
    int     size;
    int     *arr;
    t_node  *current_node;
    int     i;

    if (!stack_a || !stack_a->top || stack_a->size <= 1)
        return;
    size = stack_a->size;
    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        error_exit(stack_a, NULL); // Assuming NULL for stack_b if not used
    current_node = stack_a->top;
    i = 0;
    while (current_node)
    {
        arr[i++] = current_node->value;
        current_node = current_node->next;
    }
    bubble_sort(arr, size);
    current_node = stack_a->top;
    while (current_node)
    {
        i = 0;
        while (i < size)
        {
            if (current_node->value == arr[i])
            {
                current_node->index = i;
                break;
            }
            i++;
        }
        current_node = current_node->next;
    }
    free(arr);
}

void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int		max_num;
    int		max_bits;
    int		i_bit;
    int		j;
    int		num_elements_in_pass;
    t_node	*current_node_for_scan;
    int		count_zeros;
    int		count_ones;
    bool	should_push_zeros_to_b;
    bool	current_top_bit_is_one;

    if (!stack_a || stack_a->size <= 1 || is_stack_sorted(stack_a))
        return;

    max_num = stack_a->size - 1;
    max_bits = 0;
    max_bits = 0;
    if (stack_a->size == 0)
        return;
    if (max_num > 0)
    {
        while ((max_num >> max_bits) != 0)
            max_bits++;
    }
    if (max_bits == 0 && max_num == 0) // Handles stack_a->size == 1
        max_bits = 1; // Process at least one bit if there's one element (index 0)
                      // Though is_stack_sorted or size <=1 should catch this.
                      // Let's ensure the loop for i_bit runs meaningfully or not at all.
                      // If max_num is 0, max_bits will be 0. Loop for i_bit won't run. Correct.

    for (i_bit = 0; i_bit < max_bits; i_bit++)
    {
        num_elements_in_pass = stack_a->size;
        count_zeros = 0;
        count_ones = 0;
        current_node_for_scan = stack_a->top;
        j = 0;
        while (j < num_elements_in_pass && current_node_for_scan != NULL)
        {
            if (((current_node_for_scan->index >> i_bit) & 1) == 0)
                count_zeros++;
            else
                count_ones++;
            current_node_for_scan = current_node_for_scan->next;
            j++;
        }

        should_push_zeros_to_b = (count_zeros <= count_ones);

        for (j = 0; j < num_elements_in_pass; j++)
        {
            if (!stack_a->top)
                break;
            current_top_bit_is_one = ((stack_a->top->index >> i_bit) & 1);

            if (should_push_zeros_to_b)
            {
                if (current_top_bit_is_one) // Bit is 1, rotate in A
                    ra(stack_a, true);
                else // Bit is 0, push to B
                    pb(stack_a, stack_b, true);
            }
            else // Push ones to B, rotate zeros in A
            {
                if (!current_top_bit_is_one) // Bit is 0, rotate in A
                    ra(stack_a, true);
                else // Bit is 1, push to B
                    pb(stack_a, stack_b, true);
            }
        }
        while (!is_stack_empty(stack_b))
        {
            pa(stack_a, stack_b, true);
        }
    }
}

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
    // Assuming the smallest was pushed first, then second smallest.
    // After pa, the second smallest is at top. It should go to its sorted place.
    // If sort_three sorted to 0 1 2, and we push back 3, then 4.
    // This part might need adjustment based on final stack state.
    // For now, assuming simple pushes back, then will rely on main sort or adjust.
    // The original logic was:
    // The original sort_five pushed the two smallest to b, sorted three in a,
    // then pushed them back.
    // pb(min1)
    // pb(min2)
    // sort_three(a) [s1, s2, s3]
    // pa(b,a) -> a gets min2 on top: [min2, s1, s2, s3]
    // pa(b,a) -> a gets min1 on top: [min1, min2, s1, s2, s3]
    // This order is correct.
    pa(a, b, true); 
    if (b->top) // If b was not empty (i.e., we are sorting 5 elements, not 4)
      pa(a, b, true);
}


void sort_small(t_stack *stack_a, t_stack *stack_b, int size)
{
    if (size <= 1)
        return;
    if (size == 2)
    {
        if (stack_a->top->value > stack_a->top->next->value)
            sa(stack_a, true);
        return;
    }
    if (size == 3)
        sort_three(stack_a);
    // For size 4: push 1 to B, sort_three A, push back.
    // For size 5: push 2 to B, sort_three A, push back.
    // sort_five handles this logic by pushing 2 (or 1 if size is 4, due to loop condition)
    else if (size == 4) 
    {
        // Push the smallest element to B
        int min_val = find_min(stack_a);
        while(stack_a->top->value != min_val)
        {
            // Smart rotate: if val is in bottom half, rra, else ra
            int pos = 0;
            t_node *curr = stack_a->top;
            while(curr && curr->value != min_val) {
                curr = curr->next;
                pos++;
            }
            if (pos <= stack_a->size / 2)
                ra(stack_a, true);
            else
                rra(stack_a, true);
        }
        pb(stack_a, stack_b, true);
        sort_three(stack_a);
        pa(stack_a, stack_b, true);
    }
    else if (size == 5)
        sort_five(stack_a, stack_b); // sort_five as implemented (pushes 2 to B)
}

// Counting sort functions are now removed.
// find_min and find_max are kept as they are used by sort_five and the new sort_small for size 4.