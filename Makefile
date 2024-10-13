NAME		:= webserv
CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++17
HEADERS 	:= -I ./include

# Directories
SRC_DIR := src
OBJ_DIR := obj

COLOR_RESET			=	\033[0m
COLOR_CYAN			=	\033[36m
COLOR_GREEN			=	\033[32m
COLOR_RED			=	\033[31m
COLOR_YELLOW		=	\033[33m

SRCS	:= $(wildcard $(SRC_DIR)/*.cpp)
OBJS	:= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 13:55:42 by mott              #+#    #+#              #
#    Updated: 2024/10/13 13:39:32 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	+=	-Iinclude
# CPPFLAGS	+=	-g -fsanitize=address
# CPPFLAGS	+=	-std=c++98
CPPFLAGS	+=	-std=c++17
RM			=	rm -rf
NAME		=	webserv

SRCDIR		=	src
BUILDDIR	=	build

SRCS		=	$(wildcard $(SRCDIR)/*.cpp)
OBJS		=	$(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))
DEPS		=	$(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.d,$(SRCS))

RESET	=	\x1b[0m
RED		=	\x1b[31m
YELLOW	=	\x1b[33m
BLUE	=	\x1b[34m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $@
	@echo -e "$(YELLOW) $(CPP) $(CPPFLAGS) $(OBJS) -o $@ $(RESET)"

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	@$(CPP) $(CPPFLAGS) -MMD -MP -c $< -o $@
	@echo -e "$(BLUE) $(CPP) $(CPPFLAGS) -MMD -MP -c $< -o $@ $(RESET)"

-include $(DEPS)

$(BUILDDIR):
	@mkdir -p $@

clean:
	@$(RM) $(BUILDDIR)
	@echo -e "$(RED) $(RM) $(BUILDDIR) $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo -e "$(RED) $(RM) $(NAME) $(RESET)"

re: fclean all

.PHONY: all clean fclean re
