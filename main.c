/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:58:54 by jlowe             #+#    #+#             */
/*   Updated: 2021/11/15 15:39:50 by jlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	int		*data;
	char	**input;
	int		n;

	if (argc != 2)
		ft_error();
	input = ft_split(argv[1], ' ');
	if (validation(input))
	{
		ft_clear_split(input);
		ft_error();
	}
	n = count_int(input);
	data = conv_int(input, n);
	ft_clear_split(input);
	ft_push_swap(data, n);
	return (0);
}
