/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:43:55 by jlowe             #+#    #+#             */
/*   Updated: 2021/10/09 16:44:48 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	if (dstsize - 1 > j && dstsize > 0)
	{
		while (src[i] && ((j + i) < (dstsize - 1)))
		{
			dst[i + j] = src[i];
			i++;
		}
		dst[i + j] = '\0';
	}
	if (j >= dstsize)
		j = dstsize;
	return (ft_strlen(src) + j);
}
