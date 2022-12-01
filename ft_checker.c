/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:45:13 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/28 23:59:23 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	ft_check_nbr(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '-')
		i++;
	if (nbr[i] == '+')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_isdup(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				exit(ft_error("Error", 1));
			j++;
		}
		i++;
	}
}

void	ft_isdup2(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				exit(ft_error("Error", 1));
			j++;
		}
		i++;
	}
}

int	ft_issorted(t_stack	**stack_a)
{
	t_stack	*holder;
	int		i;

	i = 0;
	holder = *stack_a;
	while (holder->next)
	{
		if (holder->number > holder->next->number)
			return (0);
		holder = holder->next;
	}
	return (1);
}
