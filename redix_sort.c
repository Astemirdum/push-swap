/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:49:26 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 15:47:34 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_key(t_stack *stack, int *key_data)
{
	t_list	*list;
	int		i;

	list = stack->begin;
	i = 0;
	while (i < stack->len)
	{
		list->key = key_data[i];
		list = list->next;
		i++;
	}
}

void	ft_make_key_data(int *data, int *sorted_data, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (data[i] == sorted_data[j])
			{
				data[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static int	ft_max_key(t_stack *stack)
{
	int		max_key;
	int		i;
	t_list	*list;

	max_key = 0;
	list = stack->begin;
	if (list)
		max_key = stack->begin->key;
	i = 0;
	while (i < stack->len)
	{
		if (max_key < list->key)
			max_key = list->key;
		list = list->next;
		i++;
	}
	return (max_key);
}

static int	ft_bit_max(t_stack *stack_a)
{
	int	bit_max;
	int	max_int;

	bit_max = 0;
	max_int = ft_max_key(stack_a);
	while ((max_int >> bit_max) != 0)
		bit_max++;
	return (bit_max);
}

void	sort_radix(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	len;
	int	key;
	int	bit_max;

	len = stack_a->len;
	bit_max = ft_bit_max(stack_a);
	i = 0;
	while (i < bit_max)
	{
		j = 0;
		while (j < len)
		{
			key = stack_a->begin->key;
			if (((key >> i) & 1) == 1)
				ft_r(stack_a, 'a');
			else
				ft_pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->len != 0)
			ft_pa(stack_a, stack_b);
		i++;
	}
}
