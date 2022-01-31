/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:33:09 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/16 19:58:00 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "main.c"

int		ft_printf(const char *btween_quotes, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int     ft_putnbr(long int n);
int		ft_positive_putnbr(unsigned int n);
int		ft_putbase(unsigned int n, unsigned int base, char *t);
int		ft_putbase_lg(unsigned long n, unsigned int base, char *t);
int		ft_putpointer(unsigned long n);
void	ft_norminette(char c, int *count, va_list args);

#endif