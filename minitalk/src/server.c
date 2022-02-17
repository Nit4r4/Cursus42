/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:59:03 by lgenevey          #+#    #+#             */
/*   Updated: 2022/02/17 20:34:06 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"


/*
	Here we create signal handler
	int sig : signal that needs to be handled
*/
void	sig_handler(int sig)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
		ft_printf("correct signal sent");
}

/*
	error checker
*/
int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	while(1)
	{

	}

	return (0);
}