/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:58:31 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/23 10:08:14 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				len;
	struct s_list	*begin;
	struct s_list	*end;
}				t_stack;

typedef struct s_list{
	int				x;
	int				i;
	int				key;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

void	ft_push_swap(int *data, int n);
void	ft_prepare_stacks(int *data, int n,
			t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_init_stack_a(int *data, int n);
t_list	*ft_get_last(t_stack *stack_a, int n);

void	ft_sort_3(t_stack *stack_a);
void	ft_sort_5(t_stack *stack_a, t_stack *stack_b);
int		ft_max_int(t_stack *stack);
int		ft_min_int(t_stack *stack);

void	ft_make_key_data(int *data, int *sorted_data, int n);
void	set_key(t_stack *stack, int *key_data);
void	sort_radix(t_stack *stack_a, t_stack *stack_b);

void	ft_s(t_stack *stack, char t);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_r(t_stack *stack, char t);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_rev_r(t_stack *stack, char t);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

t_list	*ft_create_el(int x, int key, int i);
t_list	*ft_create_list(int *data, int n);
t_stack	*ft_init_stack(int n);
void	ft_print_stack(t_stack *stack);
void	ft_add_front(t_stack *stack, int x, int key);
void	ft_delfirst(t_stack *stack);
int		ft_stack_len(t_stack *stack);
void	ft_swap_stack(t_stack *stack);

int		validation(char **input);
int		ft_sorted_check(int *sorted_data, int n, t_stack *stack);

void	ft_error(void);
char	**ft_clear_split(char **split);
int		count_int(char **input);
int		*conv_int(char **input, int n);
void	ft_clear_stack(t_stack *stack);
int		*ft_sort(int *data, int n);
void	ft_clear(int *data);

#endif