/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:49:36 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/15 21:05:09 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// int ft_check_nbr(char *nbr)
// {
//     int i;
    
//     i = 0;
//     if (nbr[i] == '-')
//         i++;
//     while (nbr[i])
//     {
//         if (!ft_isdigit(nbr[i]))
//             return (0);
//         i++;
//     }
//     return (1);
// }

int ft_check_dup(t_both *stacks, int nbr)
{
    int size;
    int i;

    i = 0;
    size = stacks->stack_a.u_size;
    if (size == 0)
        return (1);
    while (i < size)
    {
        if (stacks->stack_a.number[i] == nbr)
            return (0);
        i++;
    }
    return (0);
}

int ft_nbrs_counter(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            count++;
        i++;
    }
    return (count);
}

int ft_error(char *err_msg, int ret_val, t_both *stacks)
{
    if (stacks)
    {
        if (stacks->stack_a.number)
            free(stacks->stack_a.number);
        if (stacks->stack_b.number)
            free(stacks->stack_b.number);
    }
    if (err_msg)
        ft_putendl_fd(err_msg, 2);
    return (ret_val);
}
