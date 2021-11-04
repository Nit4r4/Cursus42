/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:30:14 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/04 20:27:20 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	s2 = malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (i == start)
		{
			j = 0;
			while (j < len)
			{
				s2[j] = s[i + j];
				j++;
			}
			s2[j] = 0;
		}
		i++;
	}
	return (s2);
}
