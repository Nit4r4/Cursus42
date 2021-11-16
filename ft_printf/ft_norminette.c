/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norminette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:36:21 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/16 09:55:48 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_norminette(char c, int *count, va_list args)
{
	if (c == '%')
		*count += write(1, &c, 1);
	else if (c == 'c')
		*count += ft_putchar_fd((char)va_arg(args, int), 1);
	else if (c == 's')
		*count += ft_case_s((char *)va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		*count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		*count += ft_positive_putnbr(va_arg(args, int), 1);
	else if (c == 'x')
		*count += ft_putbase_fd(va_arg(args, unsigned int),
				16, "0123456789abcdef", 1);
	else if (c == 'X')
		*count += ft_putbase_fd(va_arg(args, unsigned int),
				16, "0123456789ABCDEF", 1);
	else if (c == 'p')
		*count += ft_putpointer(va_arg(args, unsigned long));
}
