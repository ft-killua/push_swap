/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:23:22 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/15 01:44:31 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ft_shift_down(int *number, int u_size)
{
	while (u_size > 0)
	{
	    number[u_size] = number[u_size - 1];
	    u_size--;
	}
}

void    ft_shift_up(int *number, int u_size)
{
	int i;

	i = 0;
	while (i < u_size)
	{
		number[i] = number[i + 1];
		i++;
	}
}

void    ft_push_stack_a(t_both *stacks, int print)
{
    int i;
	int u_size_a;
    int u_size_b;

    i = 0;
    u_size_a = stacks->stack_a.u_size;
    u_size_b = stacks->stack_b.u_size;
    if (print == YES)
        ft_putendl_fd("pa", 1);
    if (u_size_b == 0)
        return ;
    if (u_size_a == 0)
        stacks->stack_a.number[0] = stacks->stack_b.number[0];
    else
    {
        ft_shift_down(stacks->stack_a.number, u_size_a);
        stacks->stack_a.number[0] = stacks->stack_b.number[0];
    }
    ft_shift_up(stacks->stack_b.number, u_size_b);
    stacks->stack_a.u_size++;
    stacks->stack_b.u_size--;
}

void    ft_push_stack_b(t_both *stacks, int print)
{
    int i;
	int u_size_a;
    int u_size_b;

    i = 0;
    u_size_a = stacks->stack_a.u_size;
    u_size_b = stacks->stack_b.u_size;
    if (print == YES)
        ft_putendl_fd("pb", 1);
    if (u_size_a == 0)
        return ;
    if (u_size_b == 0)
        stacks->stack_b.number[0] = stacks->stack_a.number[0];
    else
    {
        ft_shift_down(stacks->stack_b.number, u_size_b);
        stacks->stack_b.number[0] = stacks->stack_a.number[0];
    }
    ft_shift_up(stacks->stack_a.number, u_size_a);
    stacks->stack_b.u_size++;
    stacks->stack_a.u_size--;
}

int ft_stack_sorted(t_stack *stack_a)
{
    int i;
    int *number;

    i = 0;
    number = stack_a->number;
    while (i < stack_a->u_size - 1)
    {
        if (number[i] > number[i + 1])
            return (0);
        i++;
    }
    return (1);
}