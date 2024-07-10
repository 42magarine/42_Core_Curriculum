# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 14:08:44 by mott              #+#    #+#              #
#    Updated: 2024/07/10 14:37:03 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	+=	-std=c++98
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

.PHONY: all clean fclean re
