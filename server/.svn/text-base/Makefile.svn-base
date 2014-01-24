NAME=		zappy_server

CC= 		gcc

RM=		rm -f

INCLUDES=	-I ../common/headers/		\
		-I headers/			\

CFLAGS=		-g -W -Wall -Wextra -ansi -pedantic -lm $(INCLUDES)

SRC=		core/main.c			\
		core/execute_action_client.c	\
		core/fdset.c			\
		core/handle_clients_awaiting.c	\
		core/handle_client_write.c	\
		core/handle_clients.c		\
		core/handle_new_connexion.c	\
		core/handle_signal.c		\
		core/server_loop.c		\
		core/close_client_connexion.c	\
		core/notification_graphical.c	\
		core/graphic_initialization.c	\
		src/team.c			\
		src/add_list.c			\
		src/del_list.c			\
		src/free_client.c		\
		src/gest_response.c		\
		src/map.c			\
		src/win.c			\
		actions/ia/voir.c		\
		actions/ia/expulse.c		\
		actions/ia/inventaire.c		\
		actions/ia/prend.c		\
		actions/ia/take_end.c		\
		actions/ia/pose.c		\
		actions/ia/avance.c		\
		actions/ia/gauche.c		\
		actions/ia/droite.c		\
		actions/ia/broadcast.c		\
		actions/ia/slot.c		\
		actions/ia/elevation_beg.c	\
		actions/ia/elevation_end.c	\
		actions/ia/fork.c		\
		actions/graphic/bct_mct.c	\
		actions/graphic/msz.c		\
		actions/graphic/pin.c		\
		actions/graphic/plv.c		\
		actions/graphic/ppo.c		\
		actions/graphic/sgt.c		\
		actions/graphic/sst.c		\
		actions/graphic/tna.c		\
		actions/graphic/pnwa.c		\
		utils/my_sprintf.c		\
		utils/log.c			\
		utils/xwrite.c			\
		utils/buffer.c			\
		utils/freetab.c			\
		utils/afftab.c			\
		utils/tablen.c			\
		utils/obj.c			\
		utils/str_to_wordtab.c		\
		utils/is_alph.c			\
		utils/is_alphnum.c		\
		utils/is_num.c			\
		utils/calc.c			\
		utils/calc_pos.c		\
		utils/xmalloc.c			\
		utils/enum_utils.c		\
		utils/time.c			\
		utils/print_time.c		\
		utils/client_by_id.c		\
		init/init_argc.c		\
		init/init_commands.c		\
		init/init_ptrs.c		\
		init/init_server.c		\
		init/init_elevation.c		\
		init/init_ssocket.c		\
		init/base_init.c


OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

count:
		cat $(SRC) | wc -l