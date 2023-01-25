OBJS = src/main.c src/pseudoku/pseudokugen.c src/pseudoku/pseudokudel.c src/pseudoku/pseudokucmp.c src/gui/guiwrapper.c src/gui/guidifficulty.c src/gui/guimainmenu.c src/gui/guigame.c
CFLAG = -Wall -Werror -g
CC = gcc
INCLUDE =
LIBS = -lncurses

pseudoku:${OBJ}
	${CC} ${CFLAG} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	rm pseudoku
