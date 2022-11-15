/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:46:38 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/13 17:02:13 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_min_to_top_ten(t_both *stacks)
{
	int min_index;

	min_index = ft_min_index(&stacks->stack_a);
	while (min_index != 0)
	{
		if (min_index <= 5)
			ft_rotate_a(&stacks->stack_a, YES);
		else
			ft_reverse_rotate_a(&stacks->stack_a, YES);
		min_index = ft_min_index(&stacks->stack_a);
	}
}

void	ft_sort_ten(t_both *stacks)
{
	if (!ft_stack_sorted(&stacks->stack_a))
	{
		while (stacks->stack_a.u_size != 5)
		{
			ft_min_to_top_ten(stacks);
			ft_push_stack_b(stacks, YES);
		}
		ft_sort_five(stacks);
		while (stacks->stack_a.u_size != stacks->stack_a.size)
			ft_push_stack_a(stacks, YES);
	}
}
