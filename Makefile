CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c ft_put.c ft_toupper.c ft_printf_bonus.c

OBJS = $(SRCS:.c=.o)

all: build_library $(NAME)

bonus: all

build_library:
	$(MAKE) -C ./libft

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I./libft -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

# run:
# 	cc -Wall -Wextra -Werror main.c ft_printf.c ft_put.c ft_toupper.c ft_printf_bonus.c

.PHONY: all bonus build_library clean fclean re

# $@ represents the target of the current rule.
# $^ represents all the dependencies (prerequisites) of the current rule.
# $< represents only the first prerequisite of the current rule.
