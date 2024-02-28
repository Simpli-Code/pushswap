/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:47:20 by chruhin           #+#    #+#             */
/*   Updated: 2023/06/21 12:21:46 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	lst = NULL;
	return (size);
}

static int	find_index(t_list **list_b, int index)
{
	int		position;
	t_list	*current_node;

	position = 0;
	current_node = *list_b;
	while (current_node && current_node->index != index)
	{
		current_node = current_node->next;
		position++;
	}
	return (position);
}

static void	sort_b(t_list **list_a, t_list **list_b, int list_size)
{
	int	bigest;
	int	half;
	int	position;

	bigest = list_size - 1;
	while (*list_b)
	{
		half = (bigest + 1) / 2;
		position = find_index(list_b, bigest);
		if ((*list_b)->index == bigest)
		{
			push_elements(list_b, list_a, "a\n");
			bigest--;
		}
		else if (position <= half && (*list_b)->index != bigest)
		{
			rotate_elements(list_b, "b\n");
		}
		else if (position > half && (*list_b)->index != bigest)
		{
			reverse_rotate_elements(list_b, "b\n");
		}
	}
}

void	sort_100_elements(t_list **list_a, t_list **list_b, int list_size)
{
	int	i;
	int	limit;

	i = 0;
	limit = 15;
	while (*list_a)
	{
		if ((*list_a)->index <= i)
		{
			push_elements(list_a, list_b, "b\n");
			rotate_elements(list_b, "b\n");
			i++;
		}
		else if ((*list_a)->index <= (i + limit))
		{
			push_elements(list_a, list_b, "b\n");
			i++;
		}
		else
		{
			rotate_elements(list_a, "a\n");
		}
	}
	sort_b(list_a, list_b, list_size);
}

void	sort_500_elements(t_list **list_a, t_list **list_b, int list_size)
{
	int	i;
	int	limit;

	i = 0;
	limit = 30;
	while (*list_a)
	{
		if ((*list_a)->index <= i)
		{
			push_elements(list_a, list_b, "b\n");
			rotate_elements(list_b, "b\n");
			i++;
		}
		else if ((*list_a)->index <= (i + limit))
		{
			push_elements(list_a, list_b, "b\n");
			i++;
		}
		else
		{
			rotate_elements(list_a, "a\n");
		}
	}
	sort_b(list_a, list_b, list_size);
}
