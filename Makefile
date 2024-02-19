# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 13:19:37 by mott              #+#    #+#              #
#    Updated: 2024/02/19 20:20:45 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LDFLAGS = -ldl -lglfw -pthread -lm
NAME = so_long
BONUS = so_long_bonus

SRCS = ./src/so_long.c \
       ./src/game.c \
       ./src/map.c \
       ./src/map_valid.c \
       ./src/png.c \

SRCS_B = ./src_b/so_long_bonus.c \
         ./src_b/game_bonus.c \
         ./src_b/map_bonus.c \
         ./src_b/map_valid_bonus.c \
         ./src_b/png_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

HEADER = ./include/so_long.h
HEADER_B = ./include/so_long_bonus.h

LIBFT = ./Libft/libft.a
LIBMLX42 = ./MLX42/build/libmlx42.a

X = "\033[0m"
R = "\033[31m"
G = "\033[32m"
Y = "\033[33m"
B = "\033[34m"

all: $(LIBFT) $(LIBMLX42) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX42) $(LDFLAGS) -o $@
	@echo $(B)$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX42) $(LDFLAGS) -o $@$(X)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(Y)$(CC) $(CFLAGS) -c $< -o $@$(X)

$(LIBFT):
	@$(MAKE) -C ./Libft

$(LIBMLX42):
	@cmake ./MLX42 -B ./MLX42/build
	@cmake --build ./MLX42/build

bonus: $(LIBFT) $(LIBMLX42) $(BONUS)

$(BONUS): $(OBJS_B)
	@$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT) $(LIBMLX42) $(LDFLAGS) -o $@
	@echo $(B)$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT) $(LIBMLX42) $(LDFLAGS) -o $@$(X)

%.o: %.c $(HEADER_B)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(Y)$(CC) $(CFLAGS) -c $< -o $@$(X)

clean:
	@rm -f $(OBJS) $(OBJS_B)
	@echo $(R)rm -f $(OBJS) $(OBJS_B)$(X)
	@rm -rf ./MLX42/build
	@echo $(R)rm -rf ./MLX42/build$(X)
	@$(MAKE) clean -C ./Libft

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@echo $(R)rm -f $(NAME) $(BONUS)$(X)
	@$(MAKE) fclean -C ./Libft

re: fclean all

.PHONY: all bonus clean fclean re

# https://github.com/codam-coding-college/MLX42.git
# https://www.gnu.org/software/make/manual/make.html
# $@ automatic variable that holds the name of the target
# $< automatic variable that holds the name of the first prerequisite
# $^ automatic variable that holds the names of all the prerequisites
