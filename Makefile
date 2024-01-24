# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 13:29:46 by mott              #+#    #+#              #
#    Updated: 2024/01/17 18:10:32 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRCS = ft_atoi.c \
       ft_bzero.c \
       ft_calloc.c \
       ft_isalnum.c \
       ft_isalpha.c \
       ft_isascii.c \
       ft_isdigit.c \
       ft_isprint.c \
       ft_itoa.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_memset.c \
       ft_putchar_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_putstr_fd.c \
       ft_split.c \
       ft_strchr.c \
       ft_strdup.c \
       ft_striteri.c \
       ft_strjoin.c \
       ft_strlcat.c \
       ft_strlcpy.c \
       ft_strlen.c \
       ft_strmapi.c \
       ft_strncmp.c \
       ft_strnstr.c \
       ft_strrchr.c \
       ft_strtrim.c \
       ft_substr.c \
       ft_tolower.c \
       ft_toupper.c \
       ft_lstadd_back.c \
       ft_lstadd_front.c \
       ft_lstclear.c \
       ft_lstdelone.c \
       ft_lstiter.c \
       ft_lstlast.c \
       ft_lstmap.c \
       ft_lstnew.c \
       ft_lstsize.c \
       ft_printf/ft_printf.c \
       ft_printf/ft_printf_flags.c \
       ft_printf/ft_printf_process.c \
       ft_printf/ft_printf_utils.c \
       get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
       get_next_line/get_next_line_bonus.c \
       get_next_line/get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

HEADER = libft.h \
         ft_printf/ft_printf.h \
         get_next_line/get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
