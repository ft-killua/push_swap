/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:41:17 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/12/01 01:33:02 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_stack(t_stack **stack)
{
	t_stack	*holder1;
	t_stack	*holder2;

	if (*stack && (*stack)->next)
	{
		holder1 = *stack;
		holder2 = (*stack)->next;
		holder1->next = (*stack)->next->next;
		holder2->next = holder1;
		*stack = holder2;
	}
}

void	ft_sa_sb_ss(t_stack **stack_a, t_stack **stack_b, int print, char stack)
{
	if (stack == 'a')
	{
		ft_swap_stack(stack_a);
		if (print == YES)
			ft_putendl_fd("sa", 1);
	}
	else if (stack == 'b')
	{
		ft_swap_stack(stack_b);
		if (print == YES)
			ft_putendl_fd("sb", 1);
	}
	else
	{
		ft_swap_stack(stack_a);
		ft_swap_stack(stack_b);
		if (print == YES)
			write(1, "ss\n", 3);
	}
}
