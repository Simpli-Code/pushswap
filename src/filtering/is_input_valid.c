/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:41:02 by chruhin           #+#    #+#             */
/*   Updated: 2023/06/21 12:23:39 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty_string(char argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isspace(argv[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_for_duplicates(int arr_size, int *array)
{
	int	i;
	int	j;

	i = -1;
	while (++i < arr_size)
	{
		j = i + 1;
		while (j < arr_size)
		{
			if (array[i] == array[j])
			{
				free_int_arr(array);
				exit_error();
			}
			j++;
		}
	}
	if (is_array_sorted(arr_size, array) == 1)
		create_list(arr_size, array);
	else
	{
		free_int_arr(array);
		return (0);
	}
	return (0);
}

int	is_array_sorted(int arr_size, int *array)
{
	int	i;

	i = 0;
	while (i < arr_size - 1)
	{
		if (array[i] > array[i + 1])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

int	ft_isspace(const char ch)
{
	if ((ch >= 9 && ch <= 13) || ch == 32)
		return (1);
	return (0);
}
