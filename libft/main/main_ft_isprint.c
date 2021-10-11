/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:07:21 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/11 18:25:46 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "../ft_isprint.c"

int	main()
{
	printf("isprint - 32 : %d\n", isprint(32));
	printf("isprint - 127 : %d\n", isprint(127));
	printf("isprint - G : %d\n", isprint('G'));
	printf("Should be 0 isprint - 18 : %d\n", isprint(18));
	
	printf("ft_isprint - 32 : %d\n", ft_isprint(32));
	printf("ft_isprint - 127 : %d\n", ft_isprint(127));
	printf("ft_isprint - G : %d\n", ft_isprint('G'));
	printf("Should be 0 ft_isprint - 18 : %d\n", ft_isprint(18));
	
	
	return (0);
}
