/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:38:16 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/10 15:21:53 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_bfrjoin(char line, char *buffer)
{
	char		*result;
	int			size_buffer;
	int			i;

	if (buffer == NULL)
		size_buffer = 1;
	else
		size_buffer = ft_strlen(buffer);
	result = malloc((1 + size_buffer) * sizeof(char));
	if (!result)
		return (free(buffer), exit(0), NULL);
	i = 0;
	while (buffer != NULL && i < size_buffer - 1)
	{
		result[i] = buffer[i];
		i++;
	}
	result[i] = line;
	if (!line)
		result[i + 1] = 0;
	if (buffer != NULL)
		free(buffer);
	return (result);
}

void	ft_print(int bit_received, siginfo_t *info, void *vd)
{
	//static char		*result;
	static int		bit;
	static unsigned char		c;

	(void)vd;
	if (!c)
		c = 0;
	//c = c * 2 + bit_received;
	c = (c << 1) | bit_received;
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd((char)c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	ft_manage_1(int bit_received, siginfo_t *info, void *vd)
{
	(void) bit_received;
	ft_print(0, info, vd);
}

void	ft_manage_2(int bit_received, siginfo_t *info, void *vd)
{
	(void) bit_received;
	ft_print(1, info, vd);
}

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
	{}
}