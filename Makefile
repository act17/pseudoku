OBJS = src/main.c src/pseudoku/pseudokugen.c
CFLAG = -Wall -Werror -g
CC = gcc
INCLUDE =
LIBS =

pseudoku:${OBJ}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	rm pseudoku