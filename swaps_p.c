/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:55:26 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 16:08:30 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b && stack_b->begin)
	{
		ft_add_front(stack_a, stack_b->begin->x, stack_b->begin->key);
		ft_delfirst(stack_b);
		ft_putstr_fd("pa\n", 1);
	}
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		ft_add_front(stack_b, stack_a->begin->x, stack_a->begin->key);
		ft_delfirst(stack_a);
		ft_putstr_fd("pb\n", 1);
	}
}
