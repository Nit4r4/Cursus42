/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:02:20 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/11 17:27:29 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "../ft_isdigit.c"

int	main()
{
	printf("0 if not char number - 1 if is digit (between 48 and 57)\n\n");
	printf("ISDIGIT\n");
    printf("'a' : %d\n", isdigit('a'));
    printf("'4' : %d\n", isdigit('4'));
    printf("6 : %d\n", isdigit(6));
    printf("48 : %d\n", isdigit(48));
    
	printf("FT_ISDIGIT\n");
    printf("'a' : %d\n", ft_isdigit('a'));
    printf("'4' : %d\n", ft_isdigit('4'));
    printf("6 : %d\n", ft_isdigit(6));
    printf("48 : %d\n", ft_isdigit(48));

	return (0);
}
