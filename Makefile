#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmery <jmery@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 15:56:49 by jmery             #+#    #+#              #
#    Updated: 2014/01/19 19:26:04 by jmery            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIB = srcs

FLAG = -Wall -Wextra -Werror

NAME = lemipc

SRCS = 	$(LIB)/case.c \
		$(LIB)/clean.c \
		$(LIB)/end_game.c \
		$(LIB)/game.c \
		$(LIB)/lemipc.c \
		$(LIB)/map.c \
		$(LIB)/move.c \
		$(LIB)/msg.c \
		$(LIB)/player.c \
		$(LIB)/sem.c \
		$(LIB)/signal.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	gcc $(FLAG) -o $(NAME) $(OBJS) -L. libft/libft.a

%.o: %.c
	gcc $(FLAG) -c $< -o $@ -I includes

clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)

re: fclean all

