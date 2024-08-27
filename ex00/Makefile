# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 14:08:44 by mott              #+#    #+#              #
#    Updated: 2024/08/27 13:16:53 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror
# CPPFLAGS	+=	-std=c++98
CPPFLAGS	+=	-std=c++17
RM			=	rm -rf
NAME		=	megaphone

SRCS		=	megaphone.cpp
OBJS		=	$(SRCS:.cpp=.o)

RESET	=	\x1b[0m
RED		=	\x1b[31m
YELLOW	=	\x1b[33m
BLUE	=	\x1b[34m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $@
	@echo "$(YELLOW) $(CPP) $(CPPFLAGS) $(OBJS) -o $@ $(RESET)"

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	@echo "$(BLUE) $(CPP) $(CPPFLAGS) -c $< -o $@ $(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED) $(RM) $(OBJS) $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED) $(RM) $(NAME) $(RESET)"

re: fclean all

t1: all
	./$(NAME) "shhhhh... I think the students are asleep..."

t2: all
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."

t3: all
	./$(NAME)

.PHONY: all clean fclean re t1 t2 t3
