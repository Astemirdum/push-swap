/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:42:26 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 16:43:37 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_clear_stack(t_stack *stack)
{
	t_list	*tmp;

	if (stack)
	{
		while (stack->begin)
		{
			tmp = stack->begin;
			stack->begin = stack->begin->next;
			free(tmp);
		}
		free(stack);
		stack = NULL;
	}
}

void	ft_clear(int *data)
{
	free(data);
	exit(1);
}
