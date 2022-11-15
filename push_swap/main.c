/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:47:54 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/15 20:46:35 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int ac, char *av[])
{
	t_both	stacks;
	char	*str;

	if (ac == 1)
		return (0);
	str = ft_av_to_string(av);
	stacks = ft_store_numbers(str);
	if (ft_stack_sorted(&stacks.stack_a))
		return(ft_error(NULL, 0, &stacks));
	if (stacks.stack_a.size == 2)
		ft_sa_or_sb(&stacks.stack_a, YES, 'a');
    if (stacks.stack_a.size == 3)
        ft_sort_three(&stacks.stack_a);
    if (stacks.stack_a.size == 5 || stacks.stack_a.size == 4)
        ft_sort_five(&stacks);
    if (stacks.stack_a.size > 5 && stacks.stack_a.size <= 10)
        ft_sort_ten(&stacks);
    if (stacks.stack_a.size > 10 && stacks.stack_a.size <= 100)
        ft_one_handred(&stacks);
    if (stacks.stack_a.size > 100)
        ft_five_handred(&stacks);
    return (ft_error(NULL, 0, &stacks));
}

    //int i = 0;//
    // printf("%d", stacks.stack_a.size);
    // return 0;