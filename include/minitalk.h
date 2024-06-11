/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:12:50 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/11 19:14:03 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	unsigned char	value;
	struct s_list	*next;
}	t_list;

typedef struct s_holder
{
	t_list	*head;
}	t_holder;

void	ft_send_bit(int bit, int pid);
void	ft_send_byte(int c, int sent_bits, int pid);
void	ft_receipt_acknowledgment(int bit);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_print(int bit_received, siginfo_t *info);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	ft_manage_1(int signum, siginfo_t *info, void *vd);
void	ft_manage_2(int signum, siginfo_t *info, void *vd);
void	ft_bzero(void *ptr, size_t n);
void	ft_print_str(t_holder *holder);
void	ft_free_list(t_holder *holder);
void	ft_lstadd_back(t_holder *holder, t_list *new);
t_list	*ft_lstnew(t_holder *holder, unsigned char value);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

#endif