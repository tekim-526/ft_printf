# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimts <kimts@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 21:25:03 by tekim             #+#    #+#              #
#    Updated: 2021/06/17 21:42:49 by kimts            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SOURCES		= ft_printf.c    \
			  print_c.c      \
			  print_num.c    \
			  print_s.c      \
			  printf_side.c  \
			  printf_side2.c \

INCLUDES	= ft_printf.h

OBJECTS		= $(SOURCES:.c=.o)

RM			= rm -f

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $@

$(NAME): $(OBJECTS)
		ar rc $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
