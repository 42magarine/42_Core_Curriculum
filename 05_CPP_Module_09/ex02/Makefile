# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 12:17:43 by mott              #+#    #+#              #
#    Updated: 2024/10/30 14:19:59 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror
# CPPFLAGS	+=	-std=c++98
CPPFLAGS	+=	-std=c++17
# CPPFLAGS	+=	-g -fsanitize=address
RM			=	rm -rf
NAME		=	PmergeMe

SRCS		=	main.cpp \
				PmergeMe.cpp
OBJS		=	$(SRCS:.cpp=.o)
DEPS		=	$(SRCS:.cpp=.d)

RESET	=	\x1b[0m
RED		=	\x1b[31m
YELLOW	=	\x1b[33m
BLUE	=	\x1b[34m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $@
	@echo "$(YELLOW) $(CPP) $(CPPFLAGS) $(OBJS) -o $@ $(RESET)"

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -MMD -MP -c $< -o $@
	@echo "$(BLUE) $(CPP) $(CPPFLAGS) -MMD -MP -c $< -o $@ $(RESET)"

-include $(DEPS)

clean:
	@$(RM) $(OBJS) $(DEPS)
	@echo "$(RED) $(RM) $(OBJS) $(DEPS) $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED) $(RM) $(NAME) $(RESET)"

re: fclean all

test: all
	@./$(NAME) `jot -r 3000 1 100000`

.PHONY: all clean fclean re test

# jot -r 3000 1 100000
# shuf -i 1-100000 -n 3000
