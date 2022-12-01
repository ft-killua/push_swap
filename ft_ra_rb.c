/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:30:56 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/18 21:09:15 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*holder;
	t_stack	*new_tail;

	new_tail = *stack;
	*stack = (*stack)->next;
	holder = *stack;
	while (holder->next)
		holder = holder->next;
	holder->next = new_tail;
	holder->next->next = NULL;
}

void	ft_ra_rb_rr(t_stack **stack_a, t_stack **stack_b, int print, char stack)
{
	if (stack == 'a')
	{
		ft_rotate(stack_a);
		if (print == YES)
			ft_putendl_fd("ra", 1);
	}
	else if (stack == 'b')
	{
		ft_rotate(stack_b);
		if (print == YES)
			ft_putendl_fd("rb", 1);
	}
	else
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		if (print == YES)
			ft_putendl_fd("rr", 1);
	}
}
