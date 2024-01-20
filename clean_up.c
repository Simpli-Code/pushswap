/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cha <cha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:50:17 by chruhin           #+#    #+#             */
/*   Updated: 2023/06/17 12:42:04 by cha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_int_arr(int *array)
{
	if (array)
	{
		free(array);
	}
}

void	free_str_arr(char *str[])
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_list(t_list **list)
{
	t_list	*current_node;

	while ((*list) != NULL)
	{
		current_node = *list;
		(*list) = (*list)->next;
		free(current_node);
	}
}
