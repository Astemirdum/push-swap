/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:42:46 by jlowe             #+#    #+#             */
/*   Updated: 2021/10/09 16:44:57 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (i < n)
		{
			if ((unsigned char)c == ((unsigned char *)s)[i])
			{
				return ((void *)(s + i));
			}
			i++;
		}
	}
	return (NULL);
}
