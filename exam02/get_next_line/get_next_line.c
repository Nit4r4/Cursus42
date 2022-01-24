#include "get_next_line.h"

/*
 * a new pointer is made from leftover, end with \n or \0
 * argument : leftover
 * return : line
 */
char	*ft_fill_line(char *statiq)
{
	unsigned int	i;
	char			*str;

	if (!statiq[0])
		return (NULL);
	str = NULL;
	i = 0;
	while (statiq[i])
	{
		if (statiq[i] == '\n')
		{
			i++;
			str = ft_substr(statiq, 0, i);
			return (str);
		}
		i++;
	}
	if (statiq[i] == '\0')
	{
		str = ft_strdup(statiq);
		return (str);
	}
	return (0);
}

/*
 * a new pointer is made from leftover but only unused  characters
 * argument : old leftover, line
 * return : new static leftover
 */
char	*ft_overwrite_statiq(char *statiq, char *s)
{
	char	*jarjar;
	int		s_len;
	int		statiq_len;

	if (!s)
	{
		free(statiq);
		return (NULL);
	}
	s_len = ft_strlen(s);
	statiq_len = ft_strlen(statiq);
	jarjar = ft_substr(statiq, s_len, statiq_len - s_len);
	free(statiq);
	return (jarjar);
}

/*
 * read file and return filled static table (leftover) with saved content
 * argument : fd, static leftover
 * return : new static leftover
 */
char	*ft_read_buffer(int fd, char *statiq)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	been_read;

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
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	leftover = ft_read_buffer(fd, leftover);
	if (!leftover)
		return (NULL);
	line = ft_fill_line(leftover);
	leftover = ft_overwrite_statiq(leftover, line);
	return (line);
}