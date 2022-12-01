/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_five_handred.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:07:12 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/18 17:05:52 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_finder(t_stack **stack_b, int index)
{
	t_stack	*holder;
	int		position;

	position = 0;
	holder = *stack_b;
	while (holder)
	{
		if (holder->index == index)
			break ;
		holder = holder->next;
		position++;
	}
	return (position);
}

void	ft_big_sorter(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	max_index;
	int	middle;
	int	position;

	max_index = size - 1;
	while (*stack_b)
	{
		middle = (max_index + 1) / 2;
		position = ft_finder(stack_b, max_index);
		if ((*stack_b)->index == max_index)
		{
			ft_pa_pb(stack_a, stack_b, YES, 'a');
			max_index--;
		}
		else if (position <= middle)
			ft_ra_rb_rr(stack_a, stack_b, YES, 'b');
		else if (position > middle)
			ft_rra_rrb_rrr(stack_a, stack_b, YES, 'b');
	}
}

void	ft_sort_100_500(t_stack **stack_a,
			t_stack **stack_b, int size, int flag)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i && i > 1)
		{
			ft_pa_pb(stack_a, stack_b, YES, 'b');
			ft_ra_rb_rr(stack_a, stack_b, YES, 'b');
			i++;
		}
		else if ((*stack_a)->index <= (i + flag))
		{
			ft_pa_pb(stack_a, stack_b, YES, 'b');
			i++;
		}
		else if ((*stack_a)->index >= i)
			ft_ra_rb_rr(stack_a, stack_b, YES, 'a');
	}
	ft_big_sorter(stack_a, stack_b, size);
}
