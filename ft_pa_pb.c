/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:23:12 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 23:28:04 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*holder;

	holder = *from;
	*from = (*from)->next;
	holder->next = *to;
	*to = holder;
}

void	ft_pa_pb(t_stack **stack_a, t_stack **stack_b, int print, char stack)
{
	if (*stack_b)
	{
		if (stack == 'a')
		{
			ft_push(stack_b, stack_a);
			if (print == YES)
				ft_putendl_fd("pa", 1);
		}
	}
	if (*stack_a)
	{
		if (stack == 'b')
		{
			ft_push(stack_a, stack_b);
			if (print == YES)
				ft_putendl_fd("pb", 1);
		}
	}
}
