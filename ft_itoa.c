/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:50:42 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/04 16:59:21 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

int	ft_count_digits_in_number(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_more_space(int n)
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

	n_length = ft_count_digits_in_number((int) n);
	str = (char *)malloc(sizeof(char) * n_length + 1);
	if (str == NULL)
		return (NULL);
	str[n_length] = '\0';
	if (n == -2147483648 || n == 0)
		return (ft_more_space(n));
	while (n_length > 0 && n != 0)
	{
		if (n < 0)
		{
			str[0] = '-';
			n = n * -1;
		}
		else
		{
			str[n_length - 1] = (n % 10) + 48;
			n = n / 10;
			n_length--;
		}
	}
	return (str);
}
