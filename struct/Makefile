#Ne pas faire attention aux commentaires
CFLAGS=-pedantic -Wall -std=c99 #-g -DNDEBUG
#LDFLAGS=-lm
.PHONY : all clean
all: test_pile test_graphe

test_graphe : test_graphe.o graphe.o pile_dynamique.o
		$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
test_graphe.o : test_graphe.c
		$(CC) $(CFLAGS) -o test_graphe.o -c test_graphe.c
graphe.o : graphe.c
		$(CC) $(CFLAGS) -o graphe.o -c graphe.c

test_pile : test_pile.o pile_dynamique.o
		$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
test_pile.o : test_pile.c
		$(CC) $(CFLAGS) -o test_pile.o -c test_pile.c
pile_dynamique.o : pile_dynamique.c
		$(CC) $(CFLAGS) -o pile_dynamique.o -c pile_dynamique.c



clean :
		rm -rf *.o
