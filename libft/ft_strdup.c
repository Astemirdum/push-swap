/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:43:46 by jlowe             #+#    #+#             */
/*   Updated: 2021/10/09 16:44:50 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	n;
	size_t	i;

	if (!s1)
		return (NULL);
	n = ft_strlen(s1);
	copy = (char *)malloc((n + 1) * sizeof(*s1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
