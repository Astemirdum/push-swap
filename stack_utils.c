/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:45:56 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 16:35:19 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_inc_index(t_stack *stack)
{
	t_list	*list;

	if (stack)
	{
		list = stack->begin;
		while (list)
		{
			list->i++;
			list = list->next;
		}
	}
}

static void	ft_decr_index(t_stack *stack)
{
	t_list	*list;

	if (stack)
	{
		list = stack->begin;
		while (list)
		{
			list->i--;
			list = list->next;
		}
	}
}

void	ft_add_front(t_stack *stack, int x, int key)
{
	t_list	*begin;

	begin = ft_create_el(x, key, 0);
	if (!begin)
	{
		ft_clear_stack(stack);
		exit(1);
	}
	if (stack->begin)
	{
		begin->next = stack->begin;
		stack->begin->prev = begin;
		ft_inc_index(stack);
	}
	stack->begin = begin;
	if (stack->len == 0)
		stack->end = begin;
	stack->len++;
}

void	ft_delfirst(t_stack *stack)
{
	t_list	*start;
	t_list	*first;

	if (stack && stack->begin)
	{
		first = stack->begin;
		start = stack->begin->next;
		if (start)
			start->prev = NULL;
		ft_decr_index(stack);
		free(first);
		stack->begin = start;
		stack->len--;
		if (stack->len == 0)
			stack->end = NULL;
	}
}
