/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:06:34 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/22 15:02:40 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	char	*psrc;

	psrc = (char *)src;
	i = 0;
	if (destsize == 0)
		return (ft_strlen(psrc));
	while (psrc[i] && i < (destsize - 1))
	{
		dest[i] = psrc[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(psrc));
}
