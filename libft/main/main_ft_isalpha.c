/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:40:55 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/11 17:01:57 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "ft_isalpha.c"

int	main() {
	printf("0 if not alpha -- 1 if is alpha\n\n");
	printf("isalpha - 'a' : %d\n", isalpha('a'));
	printf("isalpha - -5 : %d\n", isalpha(-5));
    printf("isalpha - 'Z' : %d\n", isalpha('Z'));
    printf("isalpha - 1 : %d\n", isalpha(1));
    printf("isalpha - 91 : %d\n", isalpha(91));
	printf("isalpha - 27 : %d\n\n", isalpha(27));

    printf("ft_isalpha - 'a' : %d\n", ft_isalpha('a'));
    printf("ft_isalpha - -5 : %d\n", ft_isalpha(-5));
	printf("ft_isalpha - 'Z' : %d\n", ft_isalpha('Z'));
    printf("ft_isalpha - 1 : %d\n", ft_isalpha(1));
    printf("ft_isalpha - 91 : %d\n", ft_isalpha(91));
    printf("ft_isalpha - 27 : %d\n", ft_isalpha(27));

	return (0);
}
