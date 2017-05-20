#Ne pas faire attention aux commentaires
CFLAGS=-pedantic -Wall -std=c99 #-g -DNDEBUG
#LDFLAGS=-lm
.PHONY : all clean
all:  test_graphe

test_graphe : test_graphe.o graphe.o
		$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
test_graphe.o : test_graphe.c
		$(CC) $(CFLAGS) -o test_graphe.o -c test_graphe.c
graphe.o : graphe.c
		$(CC) $(CFLAGS) -o graphe.o -c graphe.c


clean :
		rm -rf *.o
