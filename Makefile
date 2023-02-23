# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:37:16 by gade-oli          #+#    #+#              #
#    Updated: 2023/02/23 19:43:32 by gade-oli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.out

RM = rm -f

CC = gcc

SRC = get_next_line.c get_next_line_utils.c main.c

OBJS = $(SRC.c=.o)

all: $(NAME)

$(NAME):  	$(OBJS)
			$(CC) $(SRC) -g -o $(NAME) -D BUFFER_SIZE=5

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
