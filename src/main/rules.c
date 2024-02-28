/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:50:17 by chruhin           #+#    #+#             */
/*   Updated: 2023/05/04 15:23:40 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elements(t_list **list, char *c)
{
	int	tmp_value;
	int	tmp_index;

	if (*list == NULL || (*list)->next == NULL)
	{
		return ;
	}
	tmp_value = (*list)->value;
	tmp_index = (*list)->index;
	(*list)->value = (*list)->next->value;
	(*list)->index = (*list)->next->index;
	(*list)->next->value = tmp_value;
	(*list)->next->index = tmp_index;
	write(1, "s", 1);
	write(1, c, 2);
}

void	push_elements(t_list **list_a, t_list **list_b, char *c)
{
	t_list	*tmp;

	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = *list_b;
	*list_b = tmp;
	write(1, "p", 1);
	write(1, c, 2);
}

void	rotate_elements(t_list **list, char *c)
{
	t_list	*tmp;
	t_list	*last;

	if (*list == NULL || (*list)->next == NULL)
	{
		return ;
	}
	tmp = *list;
	last = *list;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*list = (*list)->next;
	last->next = tmp;
	last->next->next = NULL;
	write(1, "r", 1);
	write(1, c, 2);
}

void	reverse_rotate_elements(t_list **list, char *c)
{
	t_list	*prelast;
	t_list	*last;

	if (*list == NULL || (*list)->next == NULL)
	{
		return ;
	}
	prelast = NULL;
	last = *list;
	while (last->next != NULL)
	{
		prelast = last;
		last = last->next;
	}
	last->next = *list;
	*list = last;
	prelast->next = NULL;
	write(1, "rr", 2);
	write(1, c, 2);
}
