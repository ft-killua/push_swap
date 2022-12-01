/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assist_func_00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:52:51 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/18 17:24:21 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(const char t)
{
	if (t == ' ')
		return (1);
	if (t >= 9 && t <= 13)
		return (1);
	return (0);
}

static int	is_num(const char t)
{
	if (t >= '0' && t <= '9')
		return (1);
	return (0);
}

long long	ft_atoi(char *str)
{
	int			i;
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && is_num(str[i]))
		result = result * 10 + str[i++] - '0';
	return (sign * result);
}

int	ft_error(char *err_msg, int ret)
{
	ft_putendl_fd(err_msg, 2);
	return (ret);
}
