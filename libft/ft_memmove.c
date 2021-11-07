/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:06:13 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/22 14:42:19 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*pdest;
	char	*psrc;

	psrc = (char *)src;
	pdest = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (pdest > psrc)
	{
		while (len > 0)
		{
			pdest[len - 1] = psrc[len - 1];
			len--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			pdest[i] = psrc[i];
	}
	return (pdest);
}
