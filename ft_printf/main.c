/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:54:28 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/15 20:46:13 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char			*str = "yoksjdg";
	char			c = 'L';
	int				d = -58;
	int				*p = &d;
	unsigned int	u = -8;
	int				ret_printf = 0;
	int				ret_ft_printf = 0;

	printf("Salut\n");
	printf("%%c : %c\n", c);
	printf("%%d : %d\n", d);
	printf("%%p : %p\n", p);
	printf("%%x : %x\n", d);
	printf("%%u : %u\n", u);
	ret_printf = printf("%%s : %s\n", str);
	printf("retour de prinf %%d : %d\n\n", ret_printf);

	ft_printf("Salut\n");
	ft_printf("%%c : %c\n", c);
	ft_printf("%%d : %d\n", d);
	ft_printf("%%p : %p\n", p);
	ft_printf("%%x : %x\n", d);
	ft_printf("%%u : %u\n", u);
	ret_ft_printf = ft_printf("%%s : %s\n", str);
	printf("retour de ft_prinf %%d : %d\n\n", ret_ft_printf);

	return (0);
}
