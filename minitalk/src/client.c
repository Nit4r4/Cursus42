/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:58:50 by lgenevey          #+#    #+#             */
/*   Updated: 2022/02/17 20:21:06 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	v;
	int		sign;

	i = 0;
	v = 0;
	sign = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		v += str[i] - 48;
		v *= 10;
		i++;
	}
	return ((v * sign) / 10);
}

void	bittruc(pid_t pid, char c)
{

}

void	sig_message(pid_t pid, char *s)
{

}

/*

*/
int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Incorrect arguments : [./appname] [server pid] [string]\n");
		return (0);
	}
	pid_t	server_pid;
	char	*message;

	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	return (0);
}