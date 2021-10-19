/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:58:33 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/13 15:02:02 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t size)
{
	char	*mypointer;
	size_t	i;

	mypointer = pointer;
	i = 0;
	while (i < size)
	{
		mypointer[i] = value;
		i++;
	}
	return (mypointer);
}
