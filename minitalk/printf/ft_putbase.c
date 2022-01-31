/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_putbase_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:49:13 by lgenevey          #+#    #+#             */
/*   Updated: 2021/11/16 09:34:14 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* &table[n % base]
*  on veut l'index que nous donne le reste du modulo qui correspond
*  a la valeur en hexadecimal
*/

#include "ft_printf.h"

int	ft_putbase(unsigned int n, unsigned int base, char *table)
{
	int	count;

	count = 0;
	if (n > 15)
		count += ft_putbase(n / base, 16, &table);
	count += ft_putchar(&table[n % base]);
	return (count);
}