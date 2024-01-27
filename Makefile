# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 14:56:48 by mott              #+#    #+#              #
#    Updated: 2024/01/27 15:17:15 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRCS = ./src/push_swap.c \
       ./src/list.c \
	   ./src/init.c

OBJS = $(SRCS:.c=.o)

HEADER = ./include/push_swap.h

LIBFT = ./Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./Libft -lft

%.o: %.c $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C ./Libft

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C ./Libft

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C ./Libft

re: fclean all

.PHONY: all clean fclean re

# https://www.gnu.org/software/make/manual/make.html
# $@ automatic variable that holds the name of the target
# $< automatic variable that holds the name of the first prerequisite
# $^ automatic variable that holds the names of all the prerequisites
