/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:31:41 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 16:14:04 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

char	**ft_clear_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

int	count_int(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

int	*conv_int(char **input, int n)
{
	int	i;
	int	*data;

	data = (int *)malloc(sizeof(int) * n);
	if (!data)
	{
		ft_clear_split(input);
		ft_error();
	}
	i = 0;
	while (i < n)
	{
		data[i] = ft_atoi(input[i]);
		i++;
	}
	return (data);
}

void	ft_print_stack(t_stack *stack)
{
	t_list	*list;

	list = stack->begin;
	while (list)
	{
		ft_putstr_fd("x=", 1);
		ft_putnbr_fd(list->x, 1);
		ft_putstr_fd(" key=", 1);
		ft_putnbr_fd(list->key, 1);
		ft_putstr_fd(" i=", 1);
		ft_putnbr_fd(list->i, 1);
		ft_putchar_fd('\n', 1);
		list = list->next;
	}
}
