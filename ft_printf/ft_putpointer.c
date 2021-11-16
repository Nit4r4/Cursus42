/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:13:09 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/16 09:47:46 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase_lg_fd(unsigned long n, unsigned int base, char *t, int fd)
{
	int	count;

	count = 0;
	if (n >= 0 && n < base)
		return (write(fd, &t[n % base], 1));
	else
	{
		count += ft_putbase_lg_fd(n / base, base, t, fd);
		return (write(fd, &t[n % base], 1) + count);
	}
}

int	ft_putpointer(unsigned long n)
{
	int	count;

	count = write(1, "0x", 2);
	count += ft_putbase_lg_fd(n, 16, "0123456789abcdef", 1);
	return (count);
}
