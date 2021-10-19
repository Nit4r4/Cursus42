/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:50:12 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/15 14:59:45 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*pointer;

	pointer = s;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			if (pointer[i] != 0)
			{	
				pointer[i] = 0;
			}
			i++;
		}
	}
}
