/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:19:56 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/13 15:56:01 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_reverse_rotate_a(t_stack *stack_a, int print)
{
	int last;

	if (print == YES)
		ft_putendl_fd("rra", 1);
	last = stack_a->number[stack_a->u_size - 1];
	ft_shift_down(stack_a->number, stack_a->u_size);
	stack_a->number[0] = last;
}

void	ft_reverse_rotate_b(t_stack *stack_b, int print)
{
	int last;

	if (print == YES)
		ft_putendl_fd("rrb", 1);
	last = stack_b->number[stack_b->u_size - 1];
	ft_shift_down(stack_b->number, stack_b->u_size);
	stack_b->number[0] = last;
}

void	ft_reverse_rotate_a_b(t_both *stacks, int print)
{
	if (print == YES)
		ft_putendl_fd("rrr" ,1);
	ft_reverse_rotate_a(&stacks->stack_a, NO);	
	ft_reverse_rotate_b(&stacks->stack_b, NO);
}