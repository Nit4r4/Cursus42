/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:00:30 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/25 15:16:39 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// l23 : le + 1 c'est pour prendre en compte le 0 qui termine le tableau de char

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	copy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}
