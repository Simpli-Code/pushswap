/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:41:02 by chruhin           #+#    #+#             */
/*   Updated: 2023/06/21 12:23:19 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

int		is_empty_string(char argv[]);
int		count_arguments(char *argv[]);
int		make_integer_array(int arr_size, int *array, char *argv[]);
int		my_atoi(const char *str, char **args);
int		helper_atoi(const char *str, int i, int sign, char **args);
int		is_empty_string(char argv[]);
int		check_for_duplicates(int arr_size, int *array);
int		is_array_sorted(int arr_size, int *array);
int		ft_isspace(const char ch);

int		create_list(int arr_size, int *array);
int		ft_lstsize(t_list *lst);
int		bubble_sort(t_list *list_a, int arr_size, int *array);
int		assign_index_to_list(t_list *list_a, int *array);
int		check_list_size(t_list **list_a, int list_size);
int		helper_check_list_size(t_list **list_a, t_list **list_b, int list_size);

void	sort_3_elements(t_list **list_a);
void	sort_5_elements(t_list **list_a, t_list **list_b, int list_size);
void	helper_sort_5(t_list **list_a, t_list **list_b);
void	sort_100_elements(t_list **list_a, t_list **list_b, int list_size);
void	sort_500_elements(t_list **list_a, t_list **list_b, int list_size);

void	swap_elements(t_list **list, char *c);
void	push_elements(t_list **list_a, t_list **list_b, char *c);
void	rotate_elements(t_list **list, char *c);
void	reverse_rotate_elements(t_list **list, char *c);

void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);

void	exit_error(void);
void	free_str_arr(char *str[]);
void	free_int_arr(int *array);
void	free_list(t_list **list);

#endif
