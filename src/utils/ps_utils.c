/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:47:20 by chruhin           #+#    #+#             */
/*   Updated: 2023/06/21 14:32:06 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	substr = (char *)ft_calloc(1, sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static int	size_of_substr(const char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static int	count_substr(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
			{
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		subword;
	char	**splited;
	size_t	size;

	i = 0;
	j = 0;
	subword = count_substr(s, c);
	splited = (char **)ft_calloc(1, sizeof(char *) * (subword + 1));
	if (splited == NULL)
		return (NULL);
	while (j < subword)
	{
		while (s[i] == c)
			i++;
		size = size_of_substr(s, c, i);
		splited[j] = ft_substr(s, i, size);
		if (splited[j] == NULL)
			return (NULL);
		i = i + size;
		j++;
	}
	splited[j] = 0;
	return (splited);
}
