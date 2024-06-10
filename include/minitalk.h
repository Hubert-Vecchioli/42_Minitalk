/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:12:50 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/10 10:45:23 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_send_bit(int bit, int pid);
void	ft_send_byte(int c, int sent_bits, int pid);
void	ft_receipt_acknowledgment(int bit);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_print(int bit_received, siginfo_t *info, void *vd);
char	*ft_bfrjoin(char line, char *buffer);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	ft_manage_1(int bit_received, siginfo_t *info, void *vd);
void	ft_manage_2(int bit_received, siginfo_t *info, void *vd);
void	ft_bzero(void *ptr, size_t n);

#endif