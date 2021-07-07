SRCS_CLIENT = minitalk_utils.c ${shell find "./Client" -name "*.c"}
SRCS_SERVER = minitalk_utils.c ${shell find "./Server" -name "*.c"}
OBJS_C = ${SRCS_CLIENT:.c=.o}
OBJS_S = ${SRCS_SERVER:.c=.o}
NAME_S = ./Server/server
NAME_C = ./Client/client
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : ${NAME_S} ${NAME_C}

${NAME_S} : ${OBJS_S}
	${CC} ${SRCS_SERVER} -o ${NAME_S} 

${NAME_C} : ${OBJS_C}
	${CC} ${SRCS_CLIENT} -o ${NAME_C}

clean :
		${RM} ${OBJS_S} ${OBJS_C}

fclean : clean
		${RM} ${NAME_C} ${NAME_S}

re : fclean all

.PHONY : all clean fclean re
