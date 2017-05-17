CC= gcc
CFLAGS= -Wall -pedantic -std=c99
EXEC= test_graphe
OBJ= test_graphe.o graphe.o #main.o menu.o util.o

all:	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

graphe.o: graphe.c graphe.h
#menu.o: menu.c menu.h util.h
test_graphe.o: test_graphe.c graphe.h

clean :
		rm -rf *.o
		rm $(EXEC)
