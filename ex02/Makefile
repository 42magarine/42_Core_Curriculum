# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 12:17:43 by mott              #+#    #+#              #
#    Updated: 2024/09/29 13:50:37 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror
# CPPFLAGS	+=	-std=c++98
CPPFLAGS	+=	-std=c++17
RM			=	rm -rf
NAME		=	convert

SRCS		=	main.cpp \
				Base.cpp
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

.PHONY: all clean fclean re

# -MMD	Dependency generation without system headers
# -MP	Create phony targets for each dependency
