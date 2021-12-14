/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:40:46 by jlowe             #+#    #+#             */
/*   Updated: 2021/10/09 16:40:55 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_int(int n)
{
	if (n >= 0)
		return (n + 48);
	else
		return (n * -1 + 48);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		len;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = ft_int_len(n);
	itoa = (char *)ft_calloc((11 + sign), sizeof(char));
	if (!itoa)
		return (NULL);
	if (n == 0)
		itoa[0] = '0';
	if (sign)
		itoa[0] = '-';
	len += sign;
	while (len-- > sign)
	{
		itoa[len] = ft_int(n % 10);
		n /= 10;
	}
	return (itoa);
}
