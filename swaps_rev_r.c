/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_rev_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:03:14 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 16:09:16 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_rev_r(t_stack *stack, char t)
{
	t_list	*last;
	t_list	*first;

	if (stack && stack->begin && stack->begin->next)
	{
		last = stack->begin;
		first = stack->begin;
		while (last->next)
		{
			last->i++;
			last = last->next;
		}
		last->prev->next = NULL;
		stack->end = last->prev;
		last->next = first;
		last->prev = NULL;
		last->i = 0;
		stack->begin = last;
		if (t == 'a')
			ft_putstr_fd("rra\n", 1);
		else
			ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->begin && stack_a->begin->next
		&& stack_b && stack_b->begin && stack_b->begin->next)
	{
		ft_rev_r(stack_a, 'a');
		ft_rev_r(stack_b, 'b');
		ft_putstr_fd("rrr\n", 1);
	}
}
