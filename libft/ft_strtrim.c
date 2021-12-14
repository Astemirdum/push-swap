/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:44:20 by jlowe             #+#    #+#             */
/*   Updated: 2021/10/09 16:44:43 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrim_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (set[k])
	{
		while (s1[i] && set[k] == s1[i])
		{
			k = -1;
			i++;
		}
		k++;
	}
	return (i);
}

static size_t	ft_strtrim_end(char const *s1, char const *set, size_t start)
{
	size_t	i;
	size_t	k;
	size_t	m;

	m = 1;
	i = ft_strlen(s1);
	k = 0;
	while (set[k])
	{
		while (i > start && set[k] == s1[i - m])
		{
			k = -1;
			i--;
		}
		k++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	trim_len;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = ft_strtrim_start(s1, set);
	end = ft_strtrim_end(s1, set, start);
	trim_len = end - start;
	trim = (char *)malloc(sizeof(*s1) * (trim_len + 1));
	if (!trim)
		return (NULL);
	i = 0;
	while (i < trim_len)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
