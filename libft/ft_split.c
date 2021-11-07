/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:06:39 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/05 22:28:16 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static	int	ft_how_many_words(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		count++;
		while (*str && *str != c)
			str++;
		while (*str == c && *str)
			str++;
	}
	return (count);
}

static int	ft_count_letters(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	ft_free(char **result, int i)
{
	while (i--)
		free(result[i]);
	free(result);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		nb_words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nb_words = ft_how_many_words((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		while (*s == c && *s)
			s++;
		str[i] = ft_substr((char *)s, 0, ft_count_letters((char *)s, c));
		if (!str[i])
			ft_free(str, i);
		s = s + ft_count_letters((char *)s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
