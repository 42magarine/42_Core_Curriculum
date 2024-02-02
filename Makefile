# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 14:56:48 by mott              #+#    #+#              #
#    Updated: 2024/02/02 17:50:09 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap

SRCS = ./src/push_swap.c \
       ./src/find.c \
       ./src/init.c \
       ./src/move.c \
       ./src/op_one.c \
       ./src/op_two.c \
       ./src/op_three.c \
       ./src/sort.c \
       ./src/stack_utils.c \

OBJS = $(SRCS:.c=.o)

HEADER = ./include/push_swap.h

LIBFT = ./Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(BLUE)$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./Libft -lft  $@$(DEFAULT)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./Libft -lft

%.o: %.c $(HEADER) $(LIBFT)
	@echo "$(YELLOW)$(CC) $(CFLAGS) -c $< -o $@$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C ./Libft

clean:
	@echo "$(RED)rm -f $(OBJS) $@$(DEFAULT)"
	@rm -f $(OBJS)
	@$(MAKE) clean -C ./Libft

fclean: clean
	@echo "$(RED)rm -f $(NAME) $@$(DEFAULT)"
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./Libft

re: fclean all

.PHONY: all clean fclean re

DEFAULT = \033[0m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m

# https://www.gnu.org/software/make/manual/make.html
# $@ automatic variable that holds the name of the target
# $< automatic variable that holds the name of the first prerequisite
# $^ automatic variable that holds the names of all the prerequisites
