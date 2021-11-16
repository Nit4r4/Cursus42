/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positive_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:04:40 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/16 09:57:23 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_positive_putnbr(unsigned int n, int fd)
{
	char			v;
	unsigned int	count;

	count = 0;
	if (n >= 0 && n <= 9)
		return (ft_putchar_fd((n + 48), 1));
	else
	{
		count += ft_positive_putnbr(n / 10, 1);
		v = n % 10;
		count += ft_putchar_fd(v + 48, fd);
	}
	return (count);
}
