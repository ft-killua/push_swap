/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:28:48 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/28 21:43:41 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_node(long int a)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->number = a;
	node->next = NULL;
	return (node);
}

void	ft_add_node_back(t_stack **stack, long int a)
{
	t_stack	*new;
	t_stack	*holder;

	new = ft_create_node(a);
	if (*stack)
	{
		holder = *stack;
		while (holder->next)
			holder = holder->next;
		holder->next = new;
	}
	else
		*stack = new;
}

void	ft_init_stack_sorted_array(t_stack **stack_a,
			int *sorted_arr, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (!ft_check_nbr(av[i]))
			exit(ft_error("Error", 0));
		else
		{
			sorted_arr[j] = ft_atoi(av[i]);
			ft_add_node_back(stack_a, sorted_arr[j]);
			i++;
			j++;
		}
	}
}

void	ft_init_stack_sorted_array2(t_stack **stack_a,
			int *sorted_arr, char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if (!ft_check_nbr(splited[i]))
			exit(ft_error("Error", 0));
		else
		{
			sorted_arr[i] = ft_atoi(splited[i]);
			ft_add_node_back(stack_a, sorted_arr[i]);
			i++;
		}
	}
}

void	ft_fill_indexs(t_stack **stack_a, int *sorted_arr, int size)
{
	int		i;
	t_stack	*holder;

	i = 0;
	holder = *stack_a;
	while (holder)
	{
		while (i < size)
		{
			if (holder->number == sorted_arr[i])
				holder->index = i;
			i++;
		}
		holder = holder->next;
		i = 0;
	}
}
