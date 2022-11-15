/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:43:54 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/15 03:40:20 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

long long   ft_atoi(const char *str)
{
	int			i;
	long long	result;
	int		    sign;
    
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
