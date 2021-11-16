/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:33:53 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/16 09:47:32 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	v;
	int		count;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (n >= 0 && n <= 9)
	{
		(ft_putchar_fd(n + 48, fd));
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * -1, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		v = n % 10;
		ft_putchar_fd(v + 48, fd);
	}
	return (count = ft_count_digit(n));
}
