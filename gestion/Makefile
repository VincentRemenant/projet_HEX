CC= gcc
CFLAGS= -Wall -pedantic -std=c99
EXEC= test_graphe
OBJ= test_graphe.o graphe.o

all:	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)


graphe.o: graphe.c graphe.h pile/pile_dynamique.c pile/pile.h
pile_dynamique.o: pile/pile_dynamique.c pile/pile.h
test_graphe.o: test_graphe.c graphe.h

clean :
		rm -rf *.o
		rm $(EXEC)
