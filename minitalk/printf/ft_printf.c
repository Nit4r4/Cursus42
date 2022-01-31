/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:33:05 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/16 09:46:07 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// const char *btween_quotes : ce qu'il y a entre les guillemets

#include "ft_printf.h"

int	ft_printf(const char *btween_quotes, ...)
{
	va_list	args;
	int		count;

	va_start(args, btween_quotes);
	count = 0;
	if (!btween_quotes)
		return (0);
	while (*btween_quotes != '\0')
	{
		if (*btween_quotes != '%')
			count += write(1, btween_quotes, 1);
		else
		{
			btween_quotes++;
			ft_norminette(*btween_quotes, &count, args);
		}
		btween_quotes++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	*s = "Hey";
	int		d = -10;
	int		fret = 0;
	int		ret = 0;

	printf("Salut\n");
	printf("%%s : %s\n", s);
	ret = printf("%%d : %d\n", d);
	printf("%%x : %x\n", d);
	printf("ret printf: %d\n", ret);

	ft_printf("Salut\n");
	ft_printf("%%s : %s\n", s);
	fret = printf("%%d : %d\n", d);
	ft_printf("%%x : %x\n", d);
	printf("ret ft_printf: %d\n", fret);

	return (0);
}