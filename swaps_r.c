/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:08:19 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 16:12:20 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_put_type(char t)
{
	if (t == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	ft_r(t_stack *stack, char t)
{
	t_list	*last;
	t_list	*sec;
	t_list	*first;

	if (stack && stack->begin && stack->begin->next)
	{
		last = stack->begin;
		first = stack->begin;
		sec = first->next;
		sec->prev = NULL;
		while (last->next)
		{
			last = last->next;
			last->i--;
		}
		last->next = first;
		first->next = NULL;
		first->prev = last;
		first->i = last->i + 1;
		stack->begin = sec;
		stack->end = first;
		ft_put_type(t);
	}
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->begin && stack_a->begin->next
		&& stack_b && stack_b->begin && stack_b->begin->next)
	{
		ft_r(stack_a, 'a');
		ft_r(stack_b, 'b');
		ft_putstr_fd("rr\n", 1);
	}
}
