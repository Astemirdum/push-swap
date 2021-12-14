/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:44:05 by jlowe             #+#    #+#             */
/*   Updated: 2021/10/09 19:00:22 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	size_t			n;
	unsigned int	i;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	map = (char *)malloc((n + 1) * sizeof(*s));
	if (!map)
		return (NULL);
	i = 0;
	while (i < n)
	{
		map[i] = f(i, s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
