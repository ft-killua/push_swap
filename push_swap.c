/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:38:58 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/18 18:52:42 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack_a, t_stack **stack_b)
{
	int	nbr[3];

	nbr[0] = (*stack_a)->number;
	nbr[1] = (*stack_a)->next->number;
	nbr[2] = (*stack_a)->next->next->number;
	if (nbr[0] > nbr[1] && nbr[0] < nbr[2] && nbr[1] < nbr[2])
		ft_sa_sb_ss(stack_a, stack_b, YES, 'a');
	else if (nbr[0] > nbr[1] && nbr[1] > nbr[2])
	{
		ft_sa_sb_ss(stack_a, stack_b, YES, 'a');
		ft_rra_rrb_rrr(stack_a, stack_b, YES, 'a');
	}
	else if (nbr[0] > nbr[1] && nbr[0] > nbr[2] && nbr[1] < nbr[2])
		ft_ra_rb_rr(stack_a, stack_b, YES, 'a');
	else if (nbr[0] < nbr[1] && nbr[1] > nbr[2] && nbr[0] < nbr[2])
	{
		ft_sa_sb_ss(stack_a, stack_b, YES, 'a');
		ft_ra_rb_rr(stack_a, stack_b, YES, 'a');
	}
	else if (nbr[0] < nbr[1] && nbr[1] > nbr[2] && nbr[0] > nbr[2])
		ft_rra_rrb_rrr(stack_a, stack_b, YES, 'a');
}

void	ft_rest_five(t_stack **stack_a, t_stack **stack_b)
{
	int	u_size;

	u_size = ft_stack_used_size(*stack_b);
	ft_sort_three(stack_a, stack_b);
	while (u_size)
	{
		if ((*stack_b)->index == 0)
			ft_pa_pb(stack_a, stack_b, YES, 'a');
		else
		{
			ft_pa_pb(stack_a, stack_b, YES, 'a');
			ft_ra_rb_rr(stack_a, stack_b, YES, 'a');
		}
		u_size = ft_stack_used_size(*stack_b);
	}
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*top;
	int		used_size;

	top = *stack_a;
	used_size = ft_stack_used_size(*stack_a);
	while (used_size != 3)
	{
		if (top->index == 0)
		{
			top = top->next;
			ft_pa_pb(stack_a, stack_b, YES, 'b');
		}
		else if (top->index == size - 1)
		{
			top = top->next;
			ft_pa_pb(stack_a, stack_b, YES, 'b');
		}
		else
		{
			top = top->next;
			ft_ra_rb_rr(stack_a, stack_b, YES, 'a');
		}
		used_size = ft_stack_used_size(*stack_a);
	}
	ft_rest_five(stack_a, stack_b);
}

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		ft_sa_sb_ss(stack_a, stack_a, YES, 'a');
	else if (size == 3)
		ft_sort_three(stack_a, stack_b);
	else if (size <= 5)
		ft_sort_five(stack_a, stack_b, size);
	else if (size > 5 && size <= 100)
		ft_sort_100_500(stack_a, stack_b, size, 15);
	else
		ft_sort_100_500(stack_a, stack_b, size, 30);
}
