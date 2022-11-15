/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:59:28 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/15 21:13:20 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char    **ft_new_stacks(char *str, t_both *stacks)
{
	int		size;
	char	**numbers;
	
	numbers = ft_split(str, ' ');
	size = ft_nbrs_counter(str);
	stacks->stack_a.number = (int *)malloc(sizeof(int) * size);
	stacks->stack_b.number = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.u_size = 0;
	stacks->stack_b.u_size = 0;
	free(str);
	return (numbers);
}

t_both	ft_store_numbers(char *str)
{
	t_both		stacks;
	char		**numbers;
	long long	nbr;
	int			i;

	i = 0;
	numbers = ft_new_stacks(str, &stacks);
	while (numbers[i])
	{
		//if (!ft_check_nbr(numbers[i]))//
		//	exit(ft_error("Error", 0, &stacks));
		nbr = ft_atoi(numbers[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			exit(ft_error("Error", 0, &stacks));
		stacks.stack_a.number[i] = nbr;
		stacks.stack_a.u_size++;
		free(numbers[i]);
		i++;
	}
    free (numbers);
    return (stacks);
}

int ft_check_nbr(char *nbr)
{
    int i;
    
    i = 0;
    if (nbr[i] == '-')
        i++;
    while (nbr[i])
    {
        if (!ft_isdigit(nbr[i]))
            return (0);
        i++;
    }
    return (1);
}

char	*ft_av_to_string(char **av)
{
	char	*str;
	int		i;

	i = 1;
	str = (char *)malloc(1);
	while (av[i])
	{
		if (!ft_check_nbr(av[i]))
			exit(ft_error("Error", 0, NULL));
		else
		{
			str = ft_strjoin(str, av[i]);
            str = ft_strjoin(str, " ");
			i++;
		}
	}
	return (str);
}