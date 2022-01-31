/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positive_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:04:40 by lgenevey          #+#    #+#             */
/*   Updated: 2022/01/31 16:49:03 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_positive_putnbr(unsigned int n)
{
	char			v;
	unsigned int	count;

	count = 0;
	if (n >= 0 && n <= 9)
		return (ft_putchar((n + 48)));
	else
	{
		count += ft_positive_putnbr(n / 10);
		v = n % 10;
		count += ft_putchar(v + 48);
	}
	return (count);
}