/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:50:35 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/15 00:21:19 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ft_sort_three(t_stack *stack_a)
{
    int *nbr;

    nbr = stack_a->number;
    if (ft_stack_sorted(stack_a))
        return ;
    if (nbr[0] > nbr[1] && nbr[0] < nbr[2] && nbr[1] < nbr[2])
        ft_sa_or_sb(stack_a, YES, 'a');
    else if (nbr[0] > nbr[1] && nbr[1] < nbr[2])
    {
        ft_sa_or_sb(stack_a, YES, 'a');
        ft_reverse_rotate_a(stack_a, YES);
    }
    else if (nbr[0] > nbr[1] && nbr[0] > nbr[2] && nbr[1] < nbr[2])
        ft_rotate_a(stack_a, YES);
    else if (nbr[0] < nbr[1] && nbr[1] > nbr[2] && nbr[0] < nbr[2])
    {
        ft_sa_or_sb(stack_a, YES, 'a');
        ft_rotate_a(stack_a, YES);
    }
    else if (nbr[0] < nbr[1] && nbr[1] > nbr[2] && nbr[0] > nbr[2])
        ft_reverse_rotate_a(stack_a, YES);
}