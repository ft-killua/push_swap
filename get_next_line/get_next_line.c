/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:50:00 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/10/30 15:47:05 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	char		*buffer;
	int			readed;
	int			nl_i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	readed = read(fd, buffer, BUFFER_SIZE);
	while (readed >= 0)
	{
		buffer[readed] = 0;
		temp = ft_strjoin(temp, buffer);
		nl_i = ft_find_nl(temp);
		if (nl_i != -1)
			return (ft_line(&line, &temp, nl_i, &buffer));
		if (!readed && !temp[0])
			break ;
		if (!readed)
			return (ft_reminder(&temp, 0, &buffer));
		readed = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_free(&temp, &buffer));
}

int	ft_find_nl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_reminder(char **str, int nl_i, char **to_free)
{
	char	*reminder;
	int		len;

	len = ft_strlen(*str + nl_i);
	reminder = ft_substr(*str, nl_i, len);
	free(*str);
	*str = NULL;
	if (to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
	return (reminder);
}

char	*ft_line(char **line, char **temp, int nl_i, char **to_free)
{
	*line = ft_substr(*temp, 0, nl_i + 1);
	*temp = ft_reminder(temp, nl_i + 1, 0);
	if (to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
	return (*line);
}

char	*ft_free(char **temp, char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	free(*temp);
	*temp = NULL;
	return (NULL);
}
