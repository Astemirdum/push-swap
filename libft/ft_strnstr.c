/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:44:12 by jlowe             #+#    #+#             */
/*   Updated: 2021/10/09 16:44:44 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	needle_len = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] && needle[j] && needle[j] == haystack[i + j] \
			&& i + j < len)
				j++;
			if (j == needle_len)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
