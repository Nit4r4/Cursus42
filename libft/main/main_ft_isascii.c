/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:55:29 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/11 18:03:23 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "../ft_isascii.c"

int	main()
{
	printf("\ntest isascii 0x82 : %d\n", isascii(0x82));
	printf("test isascii 'F' : %d\n", isascii('F'));
	printf("test isascii 48 : %d\n", isascii(48));


	printf("test ft_isascii '0x82' : %d\n", ft_isascii(0x82));
	printf("test ft_isascii 'F' : %d\n", ft_isascii('F'));
	printf("test ft_isascii 48 : %d\n", ft_isascii(48));


	return (0);
}
