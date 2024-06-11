/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:36:58 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/11 19:42:43 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_answer_from_server_received;

int	main(int ac, char **av)
{
	struct sigaction	ssigaction;
	int					pid;

	ft_bzero(&ssigaction, sizeof(struct sigaction));
	ssigaction.sa_handler = &ft_receipt_acknowledgment;
	sigaction(SIGUSR1, &ssigaction, NULL);
	pid = ft_atoi(av[1]);
	if (ac != 3 || pid <= 0)
		return (0);
	while (*av[2])
	{
		ft_send_byte((unsigned char)*av[2], 0, pid);
		av[2]++;
	}
	write(1, "Message sucessfully sent\n", 25);
	ft_send_byte((unsigned char)0, 0, pid);
	return (0);
}

void	ft_send_bit(int bit, int pid)
{
	int		kill_failure;

	kill_failure = 0;
	g_answer_from_server_received = 0;
	if (bit == 1)
		kill_failure = kill(pid, SIGUSR2);
	else
		kill_failure = kill(pid, SIGUSR1);
	if (kill_failure == -1)
		exit(0);
	while (!g_answer_from_server_received)
	{
	}
}

void	ft_send_byte(int c, int sent_bits, int pid)
{
	sent_bits++;
	if (sent_bits < 8)
		ft_send_byte(c / 2, sent_bits, pid);
	if (c % 2 == 1)
		ft_send_bit(1, pid);
	else
		ft_send_bit(0, pid);
}

void	ft_receipt_acknowledgment(int bit)
{
	(void) bit;
	g_answer_from_server_received = 1;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}
