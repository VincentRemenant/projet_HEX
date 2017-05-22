#Ne pas faire attention aux commentaires
CFLAGS=-pedantic -Wall -std=c99 #-g -DNDEBUG
#LDFLAGS=-lm
.PHONY : all clean
all:  test_jeu

test_jeu : test_jeu.o jeu.o graphe.o
		$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
test_jeu.o : test_jeu.c
		$(CC) $(CFLAGS) -o test_jeu.o -c test_jeu.c
jeu.o : jeu.c
		$(CC) $(CFLAGS) -o jeu.o -c jeu.c
graphe.o : ../struct/graphe.c
		$(CC) $(CFLAGS) -o graphe.o -c ../struct/graphe.c

clean :
		rm -rf *.o
