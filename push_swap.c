/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:48:32 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/23 10:05:45 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_push_swap(int *data, int n)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_prepare_stacks(data, n, &stack_a, &stack_b);
	if (n == 2)
		ft_r(stack_a, 'a');
	else if (n == 3)
		ft_sort_3(stack_a);
	else if (n < 6)
		ft_sort_5(stack_a, stack_b);
	else
		sort_radix(stack_a, stack_b);
	ft_clear_stack(stack_a);
	ft_clear_stack(stack_b);
	free(data);
}

t_list	*ft_get_last(t_stack *stack_a, int n)
{
	int		i;
	t_list	*end;

	i = 0;
	end = stack_a->begin;
	while (i < n - 1)
	{
		end = end->next;
		i++;
	}
	return (end);
}

t_stack	*ft_init_stack_a(int *data, int n)
{
	t_stack	*stack_a;

	stack_a = ft_init_stack(n);
	if (!stack_a)
		return (NULL);
	stack_a->begin = ft_create_list(data, n);
	if (!stack_a->begin)
	{
		free(data);
		ft_clear_stack(stack_a);
		ft_error();
	}
	stack_a->end = ft_get_last(stack_a, n);
	return (stack_a);
}

static void	ft_stack_b(t_stack **stack_b, t_stack **stack_a,
		int *sorted_data, int *data)
{
	*stack_b = ft_init_stack(0);
	if (!*stack_b)
	{
		free(sorted_data);
		ft_clear_stack(*stack_a);
		ft_clear(data);
	}
}

void	ft_prepare_stacks(int *data, int n, t_stack **stack_a,
		t_stack **stack_b)
{	
	int	*sorted_data;

	*stack_a = ft_init_stack_a(data, n);
	if (!stack_a)
		ft_clear(data);
	sorted_data = ft_sort(data, n);
	if (!sorted_data)
		ft_clear(data);
	if (!ft_sorted_check(sorted_data, n, *stack_a))
	{
		ft_clear_stack(*stack_a);
		free(sorted_data);
		ft_clear(data);
	}
	ft_make_key_data(data, sorted_data, n);
	set_key(*stack_a, data);
	ft_stack_b(stack_b, stack_a, sorted_data, data);
	free(sorted_data);
}
