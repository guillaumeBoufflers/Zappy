NAME=		zappy_graphic

CXX= 		g++

RM=		rm -f

INCLUDES=	-I ../common/headers/		\
		-I headers/

CPPFLAGS=	-lsfml-graphics -lsfml-window -lsfml-system -W -Wall -Wextra  $(shell pkg-config --cflags --libs gtk+-3.0) $(INCLUDES) -g

SRC=		src/main.cpp		\
				src/AObject.cpp		\
				src/APlayer.cpp		\
				src/Player.cpp		\
				src/Object.cpp		\
				src/GameMap.cpp		\
				src/Game.cpp		\
				src/Parser.cpp		\
				src/Egg.cpp		\
				src/Hud.cpp		\
				../common/src/tools.cpp \
				../common/src/Network.cpp \
				../common/src/Task.cpp \
				../common/src/Broadcast.cpp

OBJ=		$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
