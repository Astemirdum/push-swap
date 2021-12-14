/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:44:25 by jlowe             #+#    #+#             */
/*   Updated: 2021/10/09 16:44:40 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			s_len;
	char			*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > (unsigned int)s_len)
		return (ft_strdup(""));
	sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i + (size_t)start] && i < len)
	{
		sub[i] = s[i + (size_t)start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
