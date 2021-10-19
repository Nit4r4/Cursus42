/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:07:24 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/15 11:40:35 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
	int	slength;

	slength = (ft_strlen(s));
	while (slength >= 0)
	{
		if (s[slength] == c)
			return ((char *)s + slength);
		slength--;
	}
	return (NULL);
}
