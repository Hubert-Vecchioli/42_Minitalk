/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:38:16 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/11 19:15:47 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	main(void)
{
	struct sigaction	s_sigaction1;
	struct sigaction	s_sigaction2;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction1.sa_sigaction = ft_manage_1;
	s_sigaction1.sa_flags = SA_SIGINFO;
	s_sigaction2.sa_sigaction = ft_manage_2;
	s_sigaction2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction1, NULL);
	sigaction(SIGUSR2, &s_sigaction2, NULL);
	while (1)
	{
	}
}

void	ft_manage_1(int signum, siginfo_t *info, void *vd)
{
	(void) signum;
	(void)vd;
	ft_print(0, info);
}

void	ft_manage_2(int signum, siginfo_t *info, void *vd)
{
	(void) signum;
	(void)vd;
	ft_print(1, info);
}

void	ft_print(int bit_received, siginfo_t *info)
{
	static int				bit;
	static unsigned char	c;
	static pid_t			previous_pid;
	static t_holder			holder;

	if (info->si_pid != previous_pid)
	{
		ft_free_list(&holder);
		bit = 0;
		previous_pid = info->si_pid;
	}
	c = (c << 1) | bit_received;
	bit++;
	if (bit == 8)
	{
		ft_lstadd_back(&holder, ft_lstnew(&holder, c));
		if (c == 0)
		{
			ft_print_str(&holder);
		}
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
