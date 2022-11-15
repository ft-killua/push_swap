/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:58:43 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/14 18:20:36 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ft_sort_five_to_ten(t_both *stacks, int size)
{
    if (!ft_stack_sorted(&stacks->stack_a))
    {
        while (stacks->stack_a.u_size >= 5)
        {
            ft_min_to_top_ten(stacks);
            ft_push_stack_b(stacks, YES);
        }
        ft_sort_five(stacks);
        while(stacks->stack_a.u_size != size)
            ft_push_stack_a(stacks, YES);
    }
}

int ft_magic(int *sorted_array, int size, int i, int chunks)
{
    int magic_nbr;

    magic_nbr = sorted_array[(size * i) / chunks];
    return (magic_nbr);
}

int ft_get_max_index(t_stack *stack_b)
{
    int i;
    int max_index;

    i = 0;
    max_index = i;
    while (i < stack_b->u_size)
    {
        if (stack_b->number[max_index] < stack_b->number[i])
            max_index = i;
        i++;
    }
    return (max_index);
    
}

void    ft_max_to_top(t_both *stacks)
{
    int max_index;

    max_index = ft_get_max_index(&stacks->stack_b);
    while (max_index != 0)
    {
		if (max_index <= (stacks->stack_b.u_size / 2))
			ft_rotate_b(&stacks->stack_b, YES);
		else
			ft_reverse_rotate_b(&stacks->stack_b, YES);
		max_index = ft_get_max_index(&stacks->stack_b);
    }
}
