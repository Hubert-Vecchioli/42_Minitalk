CLIENT_SRCS             = ./src/client.c
CLIENT_OBJS             =  ${CLIENT_SRCS:.c=.o}
NAME                    = client


SERVER_SRCS             = ./src/server.c ./src/server_utils.c
SERVER_OBJS             =  ${SERVER_SRCS:.c=.o}
NAME_SERVER             = server


all : ${NAME}

.c.o:
	cc -Wall -Wextra -Werror -I ./include/ -c $< -o ${<:.c=.o}

${NAME} : $(CLIENT_OBJS)
	cc -Wall -Wextra -Werror $(CLIENT_OBJS) -o ${NAME} 

${NAME_SERVER} : $(SERVER_OBJS)
	cc -Wall -Wextra -Werror $(SERVER_OBJS) -o $(NAME_SERVER)

clean :
	rm -f ${CLIENT_OBJS} $(SERVER_OBJS)

fclean : clean
	rm -f ${NAME} $(NAME_SERVER)

re : fclean all

.PHONY: all bonus clean fclean re
