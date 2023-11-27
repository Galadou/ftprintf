# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmersch <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 21:17:44 by gmersch           #+#    #+#              #
#    Updated: 2023/11/25 21:22:43 by gmersch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP		= gcc
CFLAGS		= -Wall -Werror -Wextra
NAME		= libftprintf.a
INCLUDES	= ftprintf.h

SRC		= ft_printf.c\
		write_data_type.c\
		hexa.c\
		ft_more_fonction.c\
		ft_more_fonction_2.c


OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(COMP) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re all
