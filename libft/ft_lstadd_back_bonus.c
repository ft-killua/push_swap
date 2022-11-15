/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:43:36 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/10/10 02:42:13 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*item;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		item = ft_lstlast(*lst);
		item->next = new;
	}
	else
		*lst = new;
}
