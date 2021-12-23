/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:03:39 by lgenevey          #+#    #+#             */
/*   Updated: 2021/12/23 14:52:45 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ici on va decider combien de ligne on veut lire

#include "get_next_line.h"
#include <stdio.h>
/*
int	main(void)
{
	int	fd;
	int	i;

	//fd = open("gnlTester/files/41_with_nl", O_RDONLY);
	//fd = open("test.txt", O_RDONLY);

	// on veut au moins un fichier
	if (fd > 0)
	{
		//ici combien de fois on veut appeler gnl, combien de lignes on veut afficher
		i = 0;
		while (i <= 2)
		{
			printf("%d:%s", i++, get_next_line(fd));
		}
	}
	else
		return (-1);
	close(fd);
	return (0);
}*/



int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);

	if (fd > 0)
	{
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			line = get_next_line(fd);
		}
	}
	else
		return (-1);
	close(fd);
	return (0);
}