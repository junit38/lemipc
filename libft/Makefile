#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmery <jmery@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 15:56:49 by jmery             #+#    #+#              #
#    Updated: 2013/12/19 15:46:46 by jmery            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIB = srcs/

FLAG = -Wall -Wextra -Werror

NAME = libft.a

OBJ = 	$(LIB)ft_memset.o \
		$(LIB)ft_bzero.o \
		$(LIB)ft_memcpy.o \
		$(LIB)ft_memccpy.o \
		$(LIB)ft_memmove.o \
		$(LIB)ft_memchr.o \
		$(LIB)ft_memcmp.o \
		$(LIB)ft_strlen.o \
		$(LIB)ft_strdup.o \
		$(LIB)ft_strcpy.o \
		$(LIB)ft_strncpy.o \
		$(LIB)ft_strcat.o \
		$(LIB)ft_strncat.o \
		$(LIB)ft_strlcat.o \
		$(LIB)ft_strrchr.o \
		$(LIB)ft_strstr.o \
		$(LIB)ft_strchr.o \
		$(LIB)ft_strnstr.o \
		$(LIB)ft_strcmp.o \
		$(LIB)ft_strncmp.o \
		$(LIB)ft_atoi.o \
		$(LIB)ft_isalpha.o \
		$(LIB)ft_isdigit.o \
		$(LIB)ft_isalnum.o \
		$(LIB)ft_isascii.o \
		$(LIB)ft_isprint.o \
		$(LIB)ft_toupper.o \
		$(LIB)ft_tolower.o \
		$(LIB)ft_recursive_power.o \
		$(LIB)ft_strisequal.o \
		$(LIB)ft_isupper.o \
		$(LIB)ft_islower.o \
		$(LIB)ft_memalloc.o \
		$(LIB)ft_memdel.o \
		$(LIB)ft_strnew.o \
		$(LIB)ft_strdel.o \
		$(LIB)ft_strclr.o \
		$(LIB)ft_striter.o \
		$(LIB)ft_striteri.o \
		$(LIB)ft_strmap.o \
		$(LIB)ft_strmapi.o \
		$(LIB)ft_strequ.o \
		$(LIB)ft_strnequ.o \
		$(LIB)ft_strsub.o \
		$(LIB)ft_strjoin.o \
		$(LIB)ft_itoa.o \
		$(LIB)ft_strtrim.o \
		$(LIB)ft_strsplit.o \
		$(LIB)ft_putchar.o \
		$(LIB)ft_putstr.o \
		$(LIB)ft_putendl.o \
		$(LIB)ft_putnbr.o \
		$(LIB)ft_putchar_fd.o \
		$(LIB)ft_putstr_fd.o \
		$(LIB)ft_putendl_fd.o \
		$(LIB)ft_putnbr_fd.o \
		$(LIB)ft_lstnew.o \
		$(LIB)ft_lstdelone.o \
		$(LIB)ft_lstdel.o \
		$(LIB)ft_lstadd.o \
		$(LIB)ft_lstiter.o \
		$(LIB)ft_lstmap.o \
		$(LIB)ft_cleanline.o \
		$(LIB)ft_isend.o \
		$(LIB)ft_getend.o \
		$(LIB)ft_putnchar.o \
		$(LIB)ft_putnstr.o \
		$(LIB)ft_create_elem.o \
		$(LIB)ft_list_push_back.o \
		$(LIB)ft_list_push_front.o \
		$(LIB)ft_list_push_back.o \
		$(LIB)ft_list_last.o \
		$(LIB)ft_getstrstr.o \
		$(LIB)ft_putcharerr.o \
		$(LIB)ft_putstrerr.o \
		$(LIB)ft_getnstr.o


SRCS = $(OBJ:.o=.c)

all : $(NAME)

$(NAME) :$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAG) -c $< -o $@ -I includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

