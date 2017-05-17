<<<<<<< HEAD
.PHONY: clean

=======
>>>>>>> f3da017a0a5583b53efcf220a5c7850b08538603
CC = gcc
SYS = -Wall -pedantic -std=c99

BINDIR = bin
OBJDIR = obj

OBJ = main.o menu.o util.o graphe.o
EXEC = hex

all:	$(OBJ)
<<<<<<< HEAD
		rm -rf obj bin
		mkdir obj bin
=======
>>>>>>> f3da017a0a5583b53efcf220a5c7850b08538603
		$(CC) -o $(BINDIR)/$(EXEC) $(OBJ)
		mv *.o $(OBJDIR)/

graphe.o: struct/graphe.c
	$(CC) -o graphe.o -c struct/graphe.c $(SYS)
util.o: util/util.c
	$(CC) -o util.o -c util/util.c $(SYS)
menu.o: menu/menu.c menu/menu.h util/util.h struct/graphe.h
	$(CC) -o menu.o -c menu/menu.c $(SYS)
main.o: main.c menu/menu.h
	$(CC) -o main.o -c main.c $(SYS)

clean :
	rm -f $(OBJDIR)/*.o
	rm $(BINDIR)/*
