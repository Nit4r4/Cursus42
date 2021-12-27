/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:09:57 by lgenevey          #+#    #+#             */
/*   Updated: 2021/12/27 16:42:39 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_fill_line(char *statiq)
{
	unsigned int	i;
	char			*s2;

	if (!statiq[0])
		return (NULL);
	s2 = NULL;
	i = 0;
	while (statiq[i] != '\0')
	{
		if (statiq[i] == '\n')
		{
			i++;
			s2 = ft_substr(statiq, 0, i);
			return (s2);
		}
		i++;
	}
	if (statiq[i] == '\0')
	{
		s2 = ft_strdup(statiq);
		return (s2);
	}
	return (0);
}

char	*ft_overwrite_statiq(char *statiq, char *s)
{
	char	*jarjar;
	int		s_length;
	int		statiq_length;

	if (!s)
	{
		free(statiq);
		return (NULL);
	}
	s_length = ft_strlen(s);
	statiq_length = ft_strlen(statiq);
	jarjar = ft_substr(statiq, s_length, statiq_length - s_length);
	free(statiq);
	return (jarjar);
}

char	*ft_read_buffer(int fd, char *statiq)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		been_read;

	been_read = 1;
	while (!ft_strchr(statiq, '\n') && been_read != 0)
	{
		been_read = read(fd, buffer, BUFFER_SIZE);
		if (been_read == -1)
			return (NULL);
		buffer[been_read] = '\0';
		statiq = ft_strjoin(statiq, buffer);
	}
	return (statiq);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftover[65535];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	leftover[fd] = ft_read_buffer(fd, leftover[fd]);
	if (!leftover[fd])
		return (NULL);
	line = ft_fill_line(leftover[fd]);
	leftover[fd] = ft_overwrite_statiq(leftover[fd], line);
	return (line);
}
