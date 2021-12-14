/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:48:04 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 17:21:32 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_max_int(t_stack *stack)
{
	int		max_int;
	int		i;
	t_list	*list;

	max_int = 0;
	list = stack->begin;
	if (list)
		max_int = stack->begin->x;
	i = 0;
	while (i < stack->len)
	{
		if (max_int < list->x)
			max_int = list->x;
		list = list->next;
		i++;
	}
	return (max_int);
}

int	ft_min_int(t_stack *stack)
{
	int		min_int;
	int		i;
	t_list	*list;

	min_int = 0;
	list = stack->begin;
	if (list)
		min_int = stack->begin->x;
	i = 0;
	while (i < stack->len)
	{
		if (min_int > list->x)
			min_int = list->x;
		list = list->next;
		i++;
	}
	return (min_int);
}

static void	ft_med(t_stack *stack_a, int min, int max)
{
	if (stack_a->begin->x != max && stack_a->begin->x != min)
	{
		if (min == stack_a->end->x)
			ft_rev_r(stack_a, 'a');
		else
			ft_s(stack_a, 'a');
	}
}

void	ft_sort_3(t_stack *stack_a)
{
	int	max;
	int	min;

	max = ft_max_int(stack_a);
	min = ft_min_int(stack_a);
	if (min == stack_a->begin->x && max == stack_a->end->x)
		return ;
	if (min == stack_a->begin->x)
	{
		ft_rev_r(stack_a, 'a');
		ft_s(stack_a, 'a');
	}
	else if (max == stack_a->begin->x)
	{
		if (min == stack_a->end->x)
		{
			ft_s(stack_a, 'a');
			ft_rev_r(stack_a, 'a');
		}
		else
			ft_r(stack_a, 'a');
	}
	ft_med(stack_a, min, max);
}

void	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;

	max = ft_max_int(stack_a);
	min = ft_min_int(stack_a);
	while (stack_a->len > 3)
	{
		while (min != stack_a->begin->x && max != stack_a->begin->x)
			ft_r(stack_a, 'a');
		ft_pb(stack_a, stack_b);
	}
	ft_sort_3(stack_a);
	while (stack_b->len != 0)
		ft_pa(stack_a, stack_b);
	if (max == stack_a->begin->x)
		ft_r(stack_a, 'a');
	else if (min == stack_a->begin->x && stack_a->len == 5)
	{
		ft_s(stack_a, 'a');
		ft_r(stack_a, 'a');
	}
}
