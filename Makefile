OBJS = src/main.c src/pseudoku/pseudokugen.c src/pseudoku/pseudokudel.c src/pseudoku/pseudokucmp.c src/gui/guiwrapper.c src/gui/guiseed.c src/gui/guidifficulty.c src/gui/guimainmenu.c src/gui/guigame.c
CFLAG = -Wall -Werror -g
CC = gcc
INCLUDE =
LIBS = -lncurses
# This is used for formatting.
FM = astyle
FFLAG = -s2 -n

pseudoku:${OBJ}
	${CC} ${CFLAG} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

# Unironically, the idea for doing this as a way to induce formatting
# came to me in a dream the night before I did this. I feel so smart.
format:${OBJ}
	${FM} ${OBJS} ${FFLAG} 

clean:
	rm pseudoku
