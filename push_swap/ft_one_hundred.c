/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_hundred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:04:05 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/15 18:42:49 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_get_index_of(t_both *stacks, int target)
{
	int	i;

    i = 0;
	while (i < stacks->stack_a.u_size)
	{
		if (stacks->stack_a.number[i] <= target)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_move_top(t_both *stacks, int index)
{
	int	half;

	half = stacks->stack_a.u_size / 2;
	while (index != 0)
	{
		if (index <= half)
		{
			ft_rotate_a(&stacks->stack_a, YES);
			index--;
		}
		else
		{
			ft_reverse_rotate_a(&stacks->stack_a, YES);
			index++;
			if (index == stacks->stack_a.u_size)
				break ;
		}
	}
}

void	ft_push_under(t_both *stacks, int key_nbr)
{
	int	index;

	index = ft_get_index_of(stacks, key_nbr);
	while (index != -1)
	{
		ft_move_top(stacks, index);
		ft_push_stack_b(stacks, YES);
		index = ft_get_index_of(stacks, key_nbr);
	}
}

void ft_one_handred(t_both *stacks)
{
    int i;
    int key_nbr;
    int *sorted_array;

    i = 1;
    sorted_array = ft_sort_array(&stacks->stack_a);
    while (i != 4)
    {
        key_nbr = ft_magic(sorted_array, 
                stacks->stack_a.size, i, 4);
        ft_push_under(stacks, key_nbr);
        i++;
    }
    free (sorted_array);
    ft_sort_rest_one_handred(stacks);
    while (stacks->stack_b.u_size != 0)
    {
        ft_max_to_top(stacks);
        ft_push_stack_a(stacks, YES);
    }
}

void    ft_five_handred(t_both *stacks)
{
    int i;
    int key_nbr;
    int *sorted_array;

    i = 1;
    sorted_array = ft_sort_array(&stacks->stack_a);
    while (i != 8)
    {
        key_nbr = ft_magic(sorted_array,
                stacks->stack_a.size, i, 8);
        ft_push_under(stacks, key_nbr);
        i++;
    }
    free (sorted_array);
    ft_sort_rest_five_handred(stacks);
    while (stacks->stack_b.u_size != 0)
    {
        ft_max_to_top(stacks);
        ft_push_stack_a(stacks, YES);
    }
}