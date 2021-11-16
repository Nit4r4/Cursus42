/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:08:00 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/16 09:30:08 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digit(int n)
{
	int		count;
	long	nlong;

	count = 0;
	nlong = (long)n;
	if (nlong < 0)
	{
		nlong = nlong * -1;
		count++;
	}
	if (nlong == 0)
		count++;
	while (nlong > 0)
	{
		nlong = nlong / 10;
		count++;
	}
	return (count);
}
