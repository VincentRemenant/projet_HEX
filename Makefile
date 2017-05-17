.PHONY: clean

CC = gcc
SYS = -Wall -pedantic -std=c99

BINDIR = bin
OBJDIR = obj

OBJ = main.o menu.o util.o graphe.o
EXEC = hex

all:	$(OBJ)
		rm -rf $(BINDIR) $(OBJDIR)
		mkdir $(BINDIR) $(OBJDIR)
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
	rm -rf $(BINDIR) $(OBJDIR)
