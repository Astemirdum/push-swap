/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:47:47 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 15:41:10 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	*ft_copy_data(int *data, int n)
{
	int	i;
	int	*copy;

	copy = (int *)malloc(sizeof(int) * n);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = data[i];
		i++;
	}
	return (copy);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ft_sort(int *data, int n)
{
	int	*copy;
	int	i;
	int	j;

	copy = ft_copy_data(data, n);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (copy[i] > copy[j])
				ft_swap(copy + i, copy + j);
			j++;
		}
		i++;
	}
	return (copy);
}

int	ft_sorted_check(int *sorted_data, int n, t_stack *stack)
{
	int		i;
	t_list	*list;

	i = 0;
	list = stack->begin;
	while (i < stack->len)
	{
		if (sorted_data[i] != list->x)
			return (1);
		list = list->next;
		i++;
	}
	if (n != i)
		return (1);
	return (0);
}
