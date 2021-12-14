/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:43:37 by jlowe             #+#    #+#             */
/*   Updated: 2021/10/09 16:44:51 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		n++;
		if (s[i])
			i++;
	}
	return (n);
}

static char	**ft_clear_rows(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	*ft_row(char const *s, size_t i, size_t j)
{
	char	*row;
	size_t	r;

	row = (char *)malloc(sizeof(*s) * (j + 1));
	if (!row)
		return (NULL);
	r = 0;
	while (r < j)
	{
		row[r] = s[i - j + r];
		r++;
	}
	row[r] = '\0';
	return (row);
}

static char	**ft_fillsplit(char const *s, char c, char **split, size_t k)
{
	size_t	j;
	size_t	i;
	char	*row;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		j = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			j++;
		}
		row = ft_row(s, i, j);
		if (!row)
			return (ft_clear_rows(split));
		split[k++] = row;
	}
	split[k] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	n;

	n = ft_count_words(s, c);
	split = (char **)malloc((n + 1) * sizeof(s));
	if (!split)
		return (NULL);
	split = ft_fillsplit(s, c, split, 0);
	return (split);
}
