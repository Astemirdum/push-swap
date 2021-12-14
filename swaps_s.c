/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:04:38 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 16:09:46 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_s(t_stack *stack, char t)
{
	t_list	*list;

	list = stack->begin;
	if (stack && list && list->next)
	{
		ft_swap_stack(stack);
		if (t == 'a')
			ft_putstr_fd("sa\n", 1);
		else
			ft_putstr_fd("sb\n", 1);
	}
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->begin && stack_a->begin->next
		&& stack_b->begin && stack_b->begin->next)
	{
		ft_swap_stack(stack_a);
		ft_swap_stack(stack_b);
		ft_putstr_fd("ss\n", 1);
	}		
}
