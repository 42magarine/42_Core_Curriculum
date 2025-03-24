# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 16:14:13 by mott              #+#    #+#              #
#    Updated: 2024/01/24 12:50:53 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
# SAN_LDFLAGS = -L../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next -I ../LeakSanitize
NAME = pipex
NAME_BONUS = pipex_bonus

SRCS = pipex.c pipex_utils.c
SRCS_BONUS = pipex_bonus.c pipex_utils_bonus.c pipex_heredoc_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

HEADER = pipex.h
HEADER_BONUS = pipex_bonus.h
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft
# $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(SAN_LDFLAGS) -L./libft -lft

%.o: %.c $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C ./libft

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L./libft -lft
# $(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(SAN_LDFLAGS) -L./libft -lft

%.o: %.c $(HEADER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	@$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all bonus clean fclean re

# https://www.gnu.org/software/make/manual/make.html
# $@ automatic variable that holds the name of the target
# $< automatic variable that holds the name of the first prerequisite
# $^ automatic variable that holds the names of all the prerequisites
