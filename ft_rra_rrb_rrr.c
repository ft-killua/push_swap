/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:40:00 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/18 17:20:08 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last_previous(t_stack *stack)
{
	t_stack	*last_pervious;

	last_pervious = NULL;
	if (stack && stack->next)
	{
		last_pervious = stack;
		while (last_pervious->next->next)
			last_pervious = last_pervious->next;
	}
	return (last_pervious);
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last_pervious;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		last_pervious = ft_last_previous(*stack);
		last = last_pervious->next;
		last_pervious->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	ft_rra_rrb_rrr(t_stack **stack_a, t_stack **stack_b,
			int print, char stack)
{
	if (stack == 'a')
	{
		ft_reverse_rotate(stack_a);
		if (print == YES)
			ft_putendl_fd("rra", 1);
	}
	else if (stack == 'b')
	{
		ft_reverse_rotate(stack_b);
		if (print == YES)
			ft_putendl_fd("rrb", 1);
	}
	else
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
		if (print == YES)
			ft_putendl_fd("rrr", 1);
	}
}
