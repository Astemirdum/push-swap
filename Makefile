# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 15:59:32 by jlowe             #+#    #+#              #
#    Updated: 2021/11/15 16:39:50 by jlowe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c push_swap.c utils.c validation.c check_sorted.c stack_utils.c stack_utils1.c\
		swaps_p.c swaps_s.c swaps_r.c swaps_rev_r.c redix_sort.c clear_up.c small_sort.c

HEAD = header.h

OBJS = ${SRCS:.c=.o}

LIBFT = libft.a

LIBA = -L ./libft -lft

LIBFT_H = ./libft/libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c ${LIBFT_H} ${HEAD}
	${CC} ${CFLAGS} -c $< -o $@

all:		${LIBFT} ${NAME}

${LIBFT}: 	${LIBFT_H}
			@make -C ./libft

${NAME}: ${HEAD} ${OBJS} Makefile
		${CC} ${CFLAGS} ${SRCS} ${LIBA} -o ${NAME}

clean:	
		make -C ./libft
		rm -f ${OBJS}

fclean: clean
		make fclean -C ./libft
		rm -f ${NAME}

re:		fclean all

.PHONY: re clean fclean all
