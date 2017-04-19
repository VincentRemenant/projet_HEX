CC= gcc
CFLAGS= -Wall -pedantic -std=c99
EXEC= hex
OBJ= main.o menu.o util.o

all:	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

util.o: util.c util.h
menu.o: menu.c menu.h util.h
main.o: main.c menu.h

clean :
		rm -rf *.o
		rm $(EXEC)
