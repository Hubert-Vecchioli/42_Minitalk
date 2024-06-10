/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:31:01 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/10 04:34:19 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, sizeof(char));
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (fd < 0)
		return ;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb / 10 != 0)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_strlen(const char *str)
{
	int	lenght;

	lenght = 0;
	while (str[lenght])
	{
		lenght++;
	}
	return (lenght);
}
