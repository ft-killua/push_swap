/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:31:10 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/14 18:17:21 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ft_swap(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

int *ft_init_array(t_stack *stack_a)
{
    int i;
    int *array;

    i = 0;
    array = malloc(sizeof(int) * stack_a->size);
    while (i < stack_a->size)
    {
        array[i] = stack_a->number[i];
        i++;
    }
    return (array);
}

int *ft_sort_array(t_stack *stack_a)
{
	int	i;
	int	j;
	int	min_index;
	int	*sorted_array;

	i = 0;
	sorted_array = ft_init_array(stack_a);
    while (i < stack_a->size - 1)
    {
        min_index = i;
        j = i + 1;
        while (j < stack_a->size)
        {
            if (sorted_array[j] < sorted_array[min_index])
                min_index = j;
            j++;
        }
        ft_swap(&sorted_array[min_index], &sorted_array[i]);
        i++;
    }
    return (sorted_array);
}

void ft_sort_rest_one_handred(t_both *stacks)
{
    if (stacks->stack_a.u_size == 2)
    {
        if (!ft_stack_sorted(&stacks->stack_a))
            ft_sa_or_sb(&stacks->stack_a, YES, 'a');
    }
    if (stacks->stack_a.u_size == 3)
        ft_sort_three(&stacks->stack_a);
    if (stacks->stack_a.u_size == 5 || stacks->stack_a.u_size == 4)
        ft_sort_five(stacks);
    if (stacks->stack_a.u_size > 5)
        ft_sort_five_to_ten(stacks, stacks->stack_a.u_size);
}

void ft_sort_rest_five_handred(t_both *stacks)
{
    if (stacks->stack_a.u_size == 2)
    {
        if (!ft_stack_sorted(&stacks->stack_a))
            ft_sa_or_sb(&stacks->stack_a, YES, 'a');
    }
    if (stacks->stack_a.u_size == 3)
        ft_sort_three(&stacks->stack_a);
    if (stacks->stack_a.u_size == 5 || stacks->stack_a.u_size == 4)
        ft_sort_five(stacks);
    if (stacks->stack_a.u_size > 5 && stacks->stack_a.u_size <= 10)
        ft_sort_five_to_ten(stacks, stacks->stack_a.u_size);
    if (stacks->stack_a.u_size > 10)
        ft_one_handred(stacks);
}
