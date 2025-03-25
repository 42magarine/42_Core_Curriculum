# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 12:17:43 by mott              #+#    #+#              #
#    Updated: 2024/10/21 19:30:22 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror
# CPPFLAGS	+=	-std=c++98
CPPFLAGS	+=	-std=c++17
RM			=	rm -rf
NAME		=	RPN

SRCS		=	main.cpp \
				RPN.cpp
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

t1: all
	@printf "$(YELLOW)Running test: \"8 9 * 9 - 9 - 9 - 4 - 1 +\"\n$(RESET)"
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +" || true
	@printf "$(YELLOW)Running test: \"7 7 * 7 -\"\n$(RESET)"
	@./$(NAME) "7 7 * 7 -" || true
	@printf "$(YELLOW)Running test: \"1 2 * 2 / 2 * 2 4 - +\"\n$(RESET)"
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - +" || true
	@printf "$(YELLOW)Running test: \"(1 + 1)\"\n$(RESET)"
	@./$(NAME) "(1 + 1)" || true

t2: all
	@printf "$(YELLOW)Running test: \"3 4 +\"\n$(RESET)"
	@./$(NAME) "3 4 +" || true
	@printf "$(YELLOW)Running test: \"5 1 2 + 4 * + 3 -\"\n$(RESET)"
	@./$(NAME) "5 1 2 + 4 * + 3 -" || true
	@printf "$(YELLOW)Running test: \"3 0 /\"\n$(RESET)"
	@./$(NAME) "3 0 /" || true
	@printf "$(YELLOW)Running test: \"3 4 a +\"\n$(RESET)"
	@./$(NAME) "3 4 a +" || true
	@printf "$(YELLOW)Running test: \"3 4 + 5\"\n$(RESET)"
	@./$(NAME) "3 4 + 5" || true


.PHONY: all clean fclean re t1 t2

# -MMD	Dependency generation without system headers
# -MP	Create phony targets for each dependency
