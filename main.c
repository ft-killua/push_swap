/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:40:16 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/29 00:36:01 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_norm(int size, int *sorted_arr, t_stack **stack_a, t_stack **stack_b)
{
	ft_sort_array(sorted_arr, size);
	ft_fill_indexs(stack_a, sorted_arr, size);
	ft_push_swap(stack_a, stack_b, size);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted_arr;
	char	**splited;

	splited = NULL;
	if (ac == 2)
		splited = ft_split(av[1], ' ', &ac);
	if (ac > 2)
	{
		sorted_arr = malloc(sizeof(int) * (ac - 1));
		if (splited)
		{
			ft_init_stack_sorted_array2(&stack_a, sorted_arr, splited);
			ft_isdup2(splited);
		}
		else
		{
			ft_init_stack_sorted_array(&stack_a, sorted_arr, ac, av);
			ft_isdup(ac, av);
		}
		if (ft_issorted(&stack_a))
			return (0);
		ft_norm(ac - 1, sorted_arr, &stack_a, &stack_b);
	}
}
