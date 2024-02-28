/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:09:46 by chruhin           #+#    #+#             */
/*   Updated: 2023/06/20 15:17:13 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	*array;
	int	arr_size;

	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			if (is_empty_string(argv[i]))
				exit_error();
			i++;
		}
		arr_size = count_arguments(argv);
		array = ft_calloc(1, sizeof(int) * arr_size);
		if (array == NULL)
		{
			free_int_arr(array);
			exit_error();
		}
		make_integer_array(arr_size, array, argv);
	}
	else
		return (1);
	return (0);
}

int	count_arguments(char *argv[])
{
	int		i;
	int		j;
	int		count;
	char	**args;

	i = 1;
	count = 0;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		if (args == NULL)
		{
			free_str_arr(args);
			exit_error();
		}
		j = 0;
		while (args[j])
		{
			my_atoi(args[j++], args);
			count++;
		}
		free_str_arr(args);
		i++;
	}
	return (count);
}

int	make_integer_array(int arr_size, int *array, char *argv[])
{
	int		i;
	int		j;
	int		value;
	char	**args;

	i = 1;
	value = 0;
	while (argv[i])
	{
		args = ft_split(argv[i++], ' ');
		if (args == NULL)
		{
			free_str_arr(args);
			exit_error();
		}
		j = 0;
		while (args[j])
		{
			array[value] = my_atoi(args[j++], args);
			value++;
		}
		free_str_arr(args);
	}
	check_for_duplicates(arr_size, array);
	return (0);
}

int	my_atoi(const char *str, char **args)
{
	int	i;
	int	sign;
	int	sum;

	i = 0;
	sum = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
		{
			sign = -1;
			i++;
		}
		if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
	}
	sum = helper_atoi(str, i, sign, args);
	return (sum);
}

int	helper_atoi(const char *str, int i, int sign, char **args)
{
	long int	sum;

	sum = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			free_str_arr(args);
			exit_error();
		}
		sum = sum * 10 + ((str[i] - '0') * sign);
		if (sum < -2147483648 || sum > 2147483647)
		{
			free_str_arr(args);
			exit_error();
		}
		i++;
	}
	return (sum);
}
