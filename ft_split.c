/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:06:39 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/04 17:28:08 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_how_many_words(const char *s, int c)
{
	int		nb_words;
	char	*start;

	nb_words = 0;
	start = (char *)s;
	while (*start != '\0')
	{
		while (*start == c)
			start++;
		if (*start != c)
		{
			if (ft_strchr(start, c) != NULL || nb_words == 0)
				nb_words++;
			while (*start != c && *start != '\0')
				start++;
		}
	}
	return (nb_words);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	//char	*s2;
	int		nb_of_arrays;
	int		count;
	int		i;

	//s2 = (char *)s;
	nb_of_arrays = ft_how_many_words(s, c);
	str = (char **)malloc(sizeof(char *) * nb_of_arrays + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s2 != 0)
	{
		while (*s2 == c)
			s2++;
		if (*s2 != c)
		{
			count = 0;
			while (*s2 != c && *s2 != 0)
			{
				count++;
				s2++;
			}
			str[i] = ft_substr(s, *s2, count);
			ft_strlcpy(str[i], s2 - count, count + 1);
			i++;
		}
	}
	str[nb_of_arrays] = 0;
	return (str);
}
