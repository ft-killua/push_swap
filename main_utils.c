/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:26:55 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/29 00:35:28 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_1;
	int		len_2;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	str = malloc(sizeof(char) * len_1 + len_2 + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		str[len_1++] = s2[i++];
	str[len_1] = 0;
	return (str);
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
			exit(ft_error("Error", 0));
		else
		{
			str = ft_strjoin(str, av[i]);
			str = ft_strjoin(str, " ");
			i++;
		}
	}
	return (str);
}
