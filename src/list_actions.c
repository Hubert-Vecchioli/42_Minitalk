/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:40:09 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/11 19:17:04 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_free_list(t_holder *holder)
{
	t_list	*temp;

	if (holder->head)
	{
		while (holder->head)
		{
			temp = holder->head->next;
			holder->head->value = 0;
			holder->head->next = NULL;
			free(holder->head);
			holder->head = temp;
		}
	}
}

void	ft_lstadd_back(t_holder *holder, t_list *new)
{
	if (!holder->head)
		holder->head = new;
	else
		ft_lstlast(holder->head)->next = new;
}

t_list	*ft_lstnew(t_holder *holder, unsigned char value)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
	{
		ft_free_list(holder);
		exit(0);
	}
	lst->value = value;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
