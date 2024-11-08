CC = cc
SRC_DIR = srcs/
INCLUDES_DIR = includes/
C_FLAGS = -Wall -Wextra -Werror
SRCS = ${SRC_DIR}utils/*.c ${SRC_DIR}main.c ${SRC_DIR}board.c ${SRC_DIR}game_engine.c
NAME = MasterMind

all : ${NAME}

${NAME} :
	${CC} ${C_FLAGS} -I${INCLUDES_DIR} ${SRCS} -o ${NAME} -g

clean :
	rm ${NAME}

re : clean all
