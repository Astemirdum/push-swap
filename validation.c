/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:33:37 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 17:44:34 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ch_dupl(char **input)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while (input[i + 1])
	{
		len = ft_strlen(input[i]);
		j = i + 1;
		while (input[j])
		{	
			if (len == ft_strlen(input[j]))
			{
				if (ft_strncmp(input[i], input[j], len) == 0)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	ch_ints(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		if (input[i][0] == '-')
		{
			j = 1;
			if (!input[i][1])
				return (1);
		}
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_max_border(int len, int i, char **input)
{
	if (len > 10)
		return (1);
	else if (len == 10)
	{
		if (ft_strncmp(input[i], "2147483647", 10) > 0)
			return (1);
	}
	return (0);
}

static int	ch_max_int(char **input)
{
	int		i;
	size_t	len;

	i = 0;
	while (input[i])
	{
		len = ft_strlen(input[i]);
		if (input[i][0] == '-')
		{
			if (len > 11)
				return (1);
			else if (len == 11)
			{
				if (ft_strncmp(input[i], "-2147483648", 11) > 0)
					return (1);
			}
		}
		else
			if (ft_max_border(len, i, input))
				return (1);
		i++;
	}	
	return (0);
}

int	validation(char **input)
{
	if (!input[0])
		return (1);
	if (ch_ints(input))
		return (1);
	if (ch_dupl(input))
		return (1);
	if (ch_max_int(input))
		return (1);
	return (0);
}
