/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:33:33 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/11 17:50:59 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "../ft_isalnum.c"
#include "../ft_isalpha.c"
#include "../ft_isdigit.c"

int	main()
{
	printf("ISALNUM\n");
	printf("should be 1 - [D] %d\n", isalnum('D'));
	printf("should be 0 - [124] %d\n" , isalnum(124));

	printf("FT_ISALNUM\n");
	printf("should be 1 - [D] %d\n", ft_isalnum('D'));
	printf("should be 0 - [124] %d\n" , ft_isalnum(124));

	return (0);
}
