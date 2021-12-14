/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:00:05 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 16:02:06 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_create_el(int x, int key, int i)
{
	t_list	*el;

	el = (t_list *)malloc(sizeof(t_list));
	if (!el)
		return (NULL);
	el->x = x;
	el->i = i;
	el->next = NULL;
	el->prev = NULL;
	el->key = key;
	return (el);
}

t_list	*ft_create_list(int *data, int n)
{
	int		i;
	t_list	*list;
	t_list	*ptr;
	t_list	*prev;

	list = ft_create_el(data[0], 0, 0);
	if (!list)
		return (NULL);
	ptr = list;
	prev = NULL;
	i = 1;
	while (i < n)
	{
		ptr->next = ft_create_el(data[i], 0, i);
		if (!ptr->next)
			return (NULL);
		ptr->prev = prev;
		prev = ptr;
		ptr = ptr->next;
		i++;
	}
	ptr->prev = prev;
	return (list);
}

t_stack	*ft_init_stack(int n)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->begin = NULL;
	stack->end = NULL;
	stack->len = n;
	return (stack);
}

int	ft_stack_len(t_stack *stack)
{
	t_list	*list;
	int		n;

	n = 0;
	list = stack->begin;
	while (list)
	{
		list = list->next;
		n++;
	}
	return (n);
}

void	ft_swap_stack(t_stack *stack)
{
	int		tmp;
	t_list	*f;
	t_list	*s;

	f = stack->begin;
	s = stack->begin->next;
	tmp = f->x;
	f->x = s->x;
	s->x = tmp;
	tmp = f->key;
	f->key = s->key;
	s->key = tmp;
	f->i = 0;
	s->i = 1;
}
