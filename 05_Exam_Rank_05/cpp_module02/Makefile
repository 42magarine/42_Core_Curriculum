CPP			=	g++
CPPFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	+=	-std=c++98

NAME		=	exam
SRCS		=	main.cpp \
				Warlock.cpp \
				ASpell.cpp \
				ATarget.cpp \
				Fwoosh.cpp \
				Dummy.cpp \
				Fireball.cpp \
				Polymorph.cpp \
				BrickWall.cpp \
				SpellBook.cpp \
				TargetGenerator.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)
