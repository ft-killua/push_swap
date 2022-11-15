/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_ra_rb_rr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:17:48 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/14 21:24:57 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ft_sa_or_sb(t_stack *stack, int print, char flag)
{
    int first;

    if (print == YES && flag == 'a')
        ft_putendl_fd("sa", 1);
    else if (print == YES && flag == 'b')
        ft_putendl_fd("sb", 1);
    if (stack->u_size > 1)
    {
        first = stack->number[0];
        stack->number[0] = stack->number[1];
        stack->number[1] = first;
    }
}

void    ft_sa_and_sb(t_both *stacks, int print)
{
    if (print == YES)
        ft_putendl_fd("ss", 1);
    ft_sa_or_sb(&stacks->stack_a, print, 'a');
    ft_sa_or_sb(&stacks->stack_b, print, 'b');
}

void    ft_rotate_a(t_stack *stack_a, int print)
{
    int first;

    if (print == YES)
        ft_putendl_fd("ra", 1);
    first = stack_a->number[0];
    ft_shift_up(stack_a->number, stack_a->u_size);
    stack_a->number[stack_a->u_size - 1] = first;
}

void    ft_rotate_b(t_stack *stack_b, int print)
{
    int first;

    if (print == YES)
        ft_putendl_fd("rb", 1);
    first = stack_b->number[0];
    ft_shift_up(stack_b->number, stack_b->u_size);
    stack_b->number[stack_b->u_size - 1] = first;
}

void    ft_rotate_a_b(t_both *stacks,int print)
{
    if (print == YES)
        ft_putendl_fd("rr", 1);
    ft_rotate_a(&stacks->stack_a, NO);
    ft_rotate_b(&stacks->stack_b, NO);
}
