# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 13:19:37 by mott              #+#    #+#              #
#    Updated: 2024/02/15 15:51:52 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -ldl -lglfw -pthread -lm
NAME = so_long
# BONUS = so_long_bonus

SRCS = ./src/so_long.c \
       ./src/png.c

OBJS = $(SRCS:.c=.o)

HEADER = -I ./include/so_long.h

LIBFT = ./Libft/libft.a
LIBMLX42 = ./MLX42/build/libmlx42.a

X = "\033[0m"
R = "\033[31m"
G = "\033[32m"
Y = "\033[33m"
B = "\033[34m"

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX42)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX42) $(LDFLAGS) -o $(NAME)
	@echo $(B)$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX42) $(LDFLAGS) -o $(NAME)$(X)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
	@echo $(Y)$(CC) $(CFLAGS) $(HEADER) -c $< -o $@$(X)

$(LIBFT):
	@$(MAKE) -C ./Libft

$(LIBMLX42):
	@cmake ./MLX42 -B ./MLX42/build
	@cmake --build ./MLX42/build

# bonus: $(BONUS)

clean:
	@rm -f $(OBJS)
	@echo $(R)rm -f $(OBJS)$(X)
	@rm -rf ./MLX42/build
	@echo $(R)rm -rf ./MLX42/build$(X)
	@$(MAKE) clean -C ./Libft

fclean: clean
	@rm -f $(NAME)
	@echo $(R)rm -f $(NAME)$(X)
	@$(MAKE) fclean -C ./Libft

re: fclean all

.PHONY: all bonus clean fclean re

# https://github.com/codam-coding-college/MLX42.git
# https://www.gnu.org/software/make/manual/make.html
# $@ automatic variable that holds the name of the target
# $< automatic variable that holds the name of the first prerequisite
# $^ automatic variable that holds the names of all the prerequisites
