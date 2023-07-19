# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:36:32 by aascedu           #+#    #+#              #
#    Updated: 2023/03/29 14:22:42 by aascedu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = src/main.c \
		src/parsing.c \
		src/philo.c \
		src/utils.c \
		src/start.c \
		src/eating.c \
		src/sleeping.c \
		src/thinking.c \
		src/end.c

HEADER = inc/philo.h

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g3 -I./inc
SANITIZE = -fsanitize=address -g3
RM = rm -rf

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all : 
	make $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

debug : $(OBJS)
	$(CC) $(CFLAGS) $(SANITIZE) $^ -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re debug
