/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:50:42 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/05 22:23:56 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

static	int	ft_count_digits_in_number(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	if (n == 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static	char	*ft_more_space(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		n_length;
	char	*str;

	if (n == -2147483648 || n == 0)
		return (ft_more_space(n));
	n_length = ft_count_digits_in_number((int) n);
	str = (char *)malloc(sizeof(char) * (n_length + 1));
	if (!str)
		return (NULL);
	str[n_length] = '\0';
		if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n_length > 0)
	{
		str[n_length - 1] = (n % 10) + 48;
		n = n / 10;
		n_length--;
	}
	return (str);
}
