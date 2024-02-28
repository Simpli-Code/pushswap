/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cha <cha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:50:36 by chruhin           #+#    #+#             */
/*   Updated: 2023/06/17 12:29:40 by cha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list_size(t_list **list_a, int list_size)
{
	t_list	*list_b;

	list_b = NULL;
	if (list_size == 2)
	{
		swap_elements(list_a, "a\n");
		free_list(list_a);
	}
	else if (list_size == 3)
	{
		sort_3_elements(list_a);
		free_list(list_a);
	}
	else if (list_size <= 5)
	{
		sort_5_elements(list_a, &list_b, list_size);
		free_list(list_a);
		free_list(&list_b);
	}
	else
		helper_check_list_size(list_a, &list_b, list_size);
	return (0);
}

int	helper_check_list_size(t_list **list_a, t_list **list_b, int list_size)
{
	if (list_size <= 100)
	{
		sort_100_elements(list_a, list_b, list_size);
		free_list(list_a);
		free_list(list_b);
	}
	else
	{
		sort_500_elements(list_a, list_b, list_size);
		free_list(list_a);
		free_list(list_b);
	}
	return (0);
}

void	sort_3_elements(t_list **list_a)
{
	int	a;
	int	b;
	int	c;

	a = (*list_a)->value;
	b = (*list_a)->next->value;
	c = (*list_a)->next->next->value;
	if (a > b && c > b && c > a)
		swap_elements(list_a, "a\n");
	else if (a > b && a > c && b > c)
	{
		swap_elements(list_a, "a\n");
		reverse_rotate_elements(list_a, "a\n");
	}
	else if (a > b && c > b && a > c)
		rotate_elements(list_a, "a\n");
	else if (a < b && a < c && c < b)
	{
		swap_elements(list_a, "a\n");
		rotate_elements(list_a, "a\n");
	}
	else if (a < b && c < a && c < b)
		reverse_rotate_elements(list_a, "a\n");
}

void	sort_5_elements(t_list **list_a, t_list **list_b, int list_size)
{
	t_list	*tmp;

	tmp = *list_a;
	while (ft_lstsize(*list_a) != 3)
	{
		if (tmp->index == 0 || tmp->index == list_size - 1)
		{
			tmp = tmp->next;
			push_elements(list_a, list_b, "b\n");
		}
		else
		{
			tmp = tmp->next;
			rotate_elements(list_a, "a\n");
		}
	}
	helper_sort_5(list_a, list_b);
}

void	helper_sort_5(t_list **list_a, t_list **list_b)
{
	sort_3_elements(list_a);
	while (ft_lstsize(*list_b) != 0)
	{
		if ((*list_b)->index == 0)
		{
			push_elements(list_b, list_a, "a\n");
		}
		else
		{
			push_elements(list_b, list_a, "a\n");
			rotate_elements(list_a, "a\n");
		}
	}
}
