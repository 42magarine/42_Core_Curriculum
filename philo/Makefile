# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 17:21:11 by mott              #+#    #+#              #
#    Updated: 2024/05/09 18:57:26 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
# CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	=	-Wall -Wextra -Werror -pthread
RM		=	rm -rf

NAME	=	philo
SRCS	=	input.c \
			main.c \
			time.c
OBJS	=	$(SRCS:.c=.o)
HEADERS	=	philo.h

RESET	=	\033[0m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(BLUE) $(CC) $(CFLAGS) $(OBJS) -o $@ $(RESET)"
	@echo "$(YELLOW)Creating executable finished.$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE) $(CC) $(CFLAGS) -c $< -o $@ $(RESET)"
	@echo "$(YELLOW)Creating object files finished.$(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED) $(RM) $(OBJS) $(RESET)"
	@echo "$(YELLOW)Deleting object files finished.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED) $(RM) $(NAME) $(RESET)"
	@echo "$(YELLOW)Deleting executable finished.$(RESET)"

re: fclean
	@$(MAKE) all

run:
	@$(MAKE) all
	@echo "$(YELLOW)./philo 1 800 200 200$(RESET)"
	@./philo 1 800 200 200
# @echo "$(YELLOW)./philo 5 800 200 200$(RESET)"
# @./philo 5 800 200 200
# @echo "$(YELLOW)./philo 5 800 200 200 7$(RESET)"
# @./philo 5 800 200 200 7
# @echo "$(YELLOW)./philo 4 410 200 200$(RESET)"
# @./philo 4 410 200 200
# @echo "$(YELLOW)./philo 4 310 200 100$(RESET)"
# @./philo 4 310 200 100

.PHONY: all clean fclean re run

# https://www.gnu.org/software/make/manual/make.html
# https://github.com/Nuno-Jesus/Make-A-Make
# $@ automatic variable that holds the name of the target
# $< automatic variable that holds the name of the first prerequisite
# $^ automatic variable that holds the names of all the prerequisites
