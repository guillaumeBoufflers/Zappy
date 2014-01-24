##
## Makefile for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy
##
## Made by antoine knockaert
## Login   <knocka_a@epitech.net>
##
## Started on  Fri Jul 12 19:36:54 2013 antoine knockaert
## Last update Fri Jul 12 19:53:45 2013 antoine knockaert
##

DIR_CLIENT=	client
DIR_GRAPHIC=	graphic
DIR_SERVER=	server

NAME_CLIENT=	zappy_client
NAME_GRAPHIC=	zappy_graphic
NAME_SERVER=	zappy_server

all:		$(NAME_CLIENT) $(NAME_GRAPHIC) $(NAME_SERVER)

$(NAME_CLIENT):
		cd $(DIR_CLIENT) && make
		cp $(DIR_CLIENT)/$(NAME_CLIENT) .

$(NAME_GRAPHIC):
		cd $(DIR_GRAPHIC) && make
		cp $(DIR_GRAPHIC)/$(NAME_GRAPHIC) .


$(NAME_SERVER):
		cd $(DIR_SERVER) && make
		cp $(DIR_SERVER)/$(NAME_SERVER) .

clean:
		cd $(DIR_CLIENT) && make clean
		cd $(DIR_GRAPHIC) && make clean
		cd $(DIR_SERVER) && make clean

fclean:		clean
		cd $(DIR_CLIENT) && make fclean
		cd $(DIR_GRAPHIC) && make fclean
		cd $(DIR_SERVER) && make fclean
		rm -f $(NAME_CLIENT)
		rm -f $(NAME_GRAPHIC)
		rm -f $(NAME_SERVER)

re:		fclean all
