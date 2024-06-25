# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 17:02:41 by mott              #+#    #+#              #
#    Updated: 2024/06/25 14:32:17 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
# CFLAGS	=	-Wall -Wextra -Werror
# CFLAGS	+=	-Ofast
# CFLAGS	+=	-fsanitize=address -g
LDFLAGS	=	-ldl -lglfw -pthread -lm
RM		=	rm -rf

NAME	=	cub3D
SRCS	=	./src/main.c \
			./src/parser/parse_map.c \
			./src/parser/parse_textures.c \
			./src/parser/map_validation.c \
			./src/utils/bools.c \
			./src/utils/error.c \
			./src/utils/free.c \
			./src/utils/debug.c \
			./src/engine/draw_game.c \
			./src/engine/draw_minimap.c \
			./src/engine/init.c \
			./src/engine/mouse.c \
			./src/engine/key.c \
			./src/engine/ray.c
OBJS	=	$(SRCS:.c=.o)
HEADERS	=	./include/cub3D.h

LIBFT	=	./Libft/libft.a
MLX42	=	./MLX42/build/libmlx42.a

RESET	=	\x1b[0m
RED		=	\x1b[31m
YELLOW	=	\x1b[33m
BLUE	=	\x1b[34m

all: $(LIBFT) $(MLX42) $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(LDFLAGS) -o $@
	@echo "$(BLUE) $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(LDFLAGS) -o $@ $(RESET)"
	@echo "$(YELLOW)Creating executable finished.$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE) $(CC) $(CFLAGS) -c $< -o $@ $(RESET)"
	@echo "$(YELLOW)Creating object file finished.$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./Libft

$(MLX42):
	@cmake ./MLX42 -B ./MLX42/build
	@cmake --build ./MLX42/build

clean:
	@$(RM) $(OBJS)
	@echo "$(RED) $(RM) $(OBJS) $(RESET)"
	@echo "$(YELLOW)Deleting object files finished.$(RESET)"

	@$(RM) ./MLX42/build
	@echo "$(RED) $(RM) ./MLX42/build $(RESET)"
	@echo "$(YELLOW)Deleting MLX42 files finished.$(RESET)"

	@$(MAKE) clean -C ./Libft

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED) $(RM) $(NAME) $(RESET)"
	@echo "$(YELLOW)Deleting executable finished.$(RESET)"

	@$(MAKE) fclean -C ./Libft

re: fclean
	@$(MAKE) all

.PHONY: all clean fclean re
