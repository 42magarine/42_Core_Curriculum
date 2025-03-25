CPP			=	g++
CPPFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	+=	-std=c++98

NAME		=	exam
SRCS		=	main.cpp \
				Warlock.cpp \
				ASpell.cpp \
				ATarget.cpp \
				Fwoosh.cpp \
				Dummy.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)
