NAME=		zappy_client

CC= 		g++

RM=		rm -f

INCLUDES=	-I ../common/headers/		\
		-I headers/

CPPFLAGS=	-lpthread -W -Wall -Wextra $(INCLUDES)

SRC=		src/main.cpp \
		src/Game.cpp \
		src/Parse.cpp \
		src/IA.cpp \
		src/PlayerInfo.cpp \
		../common/src/Broadcast.cpp \
		../common/src/Task.cpp \
		../common/src/tools.cpp \
		../common/src/Network.cpp

OBJ=		$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
