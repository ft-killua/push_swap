/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:06:28 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/13 23:32:33 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_min_index(t_stack *stack_a)
{
	int	i;
	int	min_index;

	i = 0;
	min_index = 0;
	while (i < stack_a->u_size)
	{
		if (stack_a->number[min_index] > stack_a->number[i])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	ft_min_to_top(t_both *stacks)
{
	int	min_index;

	min_index = ft_min_index(&stacks->stack_a);
	while (min_index != 0)
	{
		if (min_index <= 2)
			ft_rotate_a(&stacks->stack_a, YES);
		else
			ft_reverse_rotate_a(&stacks->stack_a, YES);
		min_index = ft_min_index(&stacks->stack_a);
	}
}

void	ft_sort_five(t_both *stacks)
{
	int	count;

	count = 0;
	if (!ft_stack_sorted(&stacks->stack_a))
	{
		if (stacks->stack_a.u_size == 5)
		{
			ft_min_to_top(stacks);
			ft_push_stack_b(stacks, YES);
			count++;
		}
		if (stacks->stack_a.u_size == 4)
		{
			ft_min_to_top(stacks);
			ft_push_stack_b(stacks, YES);
			count++;
		}
		ft_sort_three(&stacks->stack_a);
		while (count > 0)
		{
			ft_push_stack_a(stacks, YES);
			count--;
		}
	}
}
