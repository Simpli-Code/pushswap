/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:09:46 by chruhin           #+#    #+#             */
/*   Updated: 2023/06/21 14:57:38 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*list;

	list = (t_list *)ft_calloc(1, sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->value = value;
	list->next = NULL;
	return (list);
}

t_list	*ft_lstadd_node(t_list *list, int value)
{
	t_list	*new_node;
	t_list	*tmp;

	new_node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!new_node)
		return (NULL);
	tmp = list->next;
	list->next = new_node;
	new_node->value = value;
	new_node->next = tmp;
	return (new_node);
}

int	create_list(int arr_size, int *array)
{
	int		i;
	t_list	*list_a;

	list_a = NULL;
	i = arr_size - 1;
	list_a = ft_lstnew(array[0]);
	if (list_a == NULL)
	{
		free_list(&list_a);
		free_int_arr(array);
		exit_error();
	}
	while (i > 0)
	{
		if (ft_lstadd_node(list_a, array[i]) == NULL)
		{
			free_list(&list_a);
			free_int_arr(array);
			exit_error();
		}
		i--;
	}
	bubble_sort(list_a, arr_size, array);
	return (0);
}

int	bubble_sort(t_list *list_a, int arr_size, int *array)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < arr_size - 1)
	{
		j = arr_size - 1;
		while (j > i)
		{
			if (array[j - 1] > array[j])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
			}
			j--;
		}
		i++;
	}
	if (assign_index_to_list(list_a, array))
		check_list_size(&list_a, arr_size);
	return (0);
}

int	assign_index_to_list(t_list *list_a, int *array)
{
	int	i;

	i = 0;
	while (list_a)
	{
		if (list_a->value == array[i])
		{
			list_a->index = i;
			list_a = list_a->next;
			i = -1;
		}
		i++;
	}
	free_int_arr(array);
	return (1);
}
