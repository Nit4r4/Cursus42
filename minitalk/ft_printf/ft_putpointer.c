/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:13:09 by lgenevey          #+#    #+#             */
/*   Updated: 2022/01/31 18:31:36 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase_lg(unsigned long n, unsigned int base, char *t)
{
	int	count;

	count = 0;
	if (n >= 0 && n < base)
		return (write(1, &t[n % base], 1));
	else
	{
		count += ft_putbase_lg(n / base, base, t);
		return (write(1, &t[n % base], 1) + count);
	}
}

int	ft_putpointer(unsigned long n)
{
	int	count;

	count = write(1, "0x", 2);
	count += ft_putbase_lg(n, 16, "0123456789abcdef");
	return (count);
}
