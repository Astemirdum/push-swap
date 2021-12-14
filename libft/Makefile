# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlowe <jlowe@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 18:02:10 by jlowe             #+#    #+#              #
#    Updated: 2021/10/28 16:01:24 by jlowe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= ft_atoi.c ft_itoa.c    ft_putendl_fd.c ft_strlcat.c  ft_substr.c ft_bzero.c \
				ft_putnbr_fd.c  ft_strlcpy.c    ft_tolower.c \
				ft_calloc.c      ft_memchr.c ft_putstr_fd.c ft_strlen.c  \
				ft_toupper.c  ft_isalnum.c  ft_memcmp.c ft_split.c \
				ft_strmapi.c ft_isalpha.c    ft_memcpy.c \
				ft_strchr.c     ft_strncmp.c ft_isascii.c \
				ft_memmove.c  ft_strdup.c        ft_strnstr.c \
				ft_isdigit.c  ft_memset.c      ft_striteri.c    ft_strrchr.c \
				ft_isprint.c   ft_putchar_fd.c    ft_strjoin.c      ft_strtrim.c

OBJS		= $(SRCS:.c=.o)

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror 

CC			= gcc

LIB 		= libft.h

NAME		= libft.a

all: 		${NAME}

$(NAME): 	${OBJS} ${LIB} Makefile
			ar rcs ${NAME} ${OBJS}

%.o : %c	${NAME}
			${CC} ${CFLAGS} -c $< -o $@
clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus