/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:42:53 by jlowe             #+#    #+#             */
/*   Updated: 2021/10/09 16:44:56 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		*((char *)dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}
