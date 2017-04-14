CC= gcc
CFLAGS= -Wall -pedantic -std=c99
EXEC= hex
OBJ= main.o menu.o

all:	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

menu.o: menu.c menu.h
main.o: main.c menu.h
