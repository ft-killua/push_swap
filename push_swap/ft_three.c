/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:50:35 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/16 00:42:31 by hidhmmou         ###   ########.fr       */
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
    else if (nbr[0] > nbr[1] && nbr[1] > nbr[2])
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

// case1 : [2,1,3]->sa->[1,2,3].

// case2 : [3,2,1]->sa->[2,3,1]->rra->[1,2,3].

// case3: [3,1,2]->ra->[1,2,3].

// case4 : [1,3,2]->sa->[3,1,2]->ra->[1,2,3].

// case5 : [2,3,1]->rra->[1,2,3].