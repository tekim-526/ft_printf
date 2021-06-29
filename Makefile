# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tekim <tekim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 21:25:03 by tekim             #+#    #+#              #
#    Updated: 2021/06/22 14:29:54 by tekim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT		= libft

LIBFT_LIB	= libft.a

SOURCES		= ft_printf.c    \
			  print_c.c      \
			  print_num.c    \
			  print_s.c      \
			  printf_side.c  \

INCLUDES	= ft_printf.h

OBJECTS		= $(SOURCES:.c=.o)

RM			= rm -f

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $(<:.c=.o) -I$(INCLUDES)

$(NAME): $(OBJECTS)
		make all -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
		ar crs $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make clean -C $(LIBFT)

re: fclean all
