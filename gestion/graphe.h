#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdbool.h>

typedef struct graphe_s * graphe_t;

graphe_t creer_graph();
bool estAdjacent(graphe_t sommet1,graphe_t sommet2);
bool estConnecte(graphe_t sommet1,graphe_t sommet2);
int getDistance(graphe_t sommet1, graphe_t sommet2);


#endif
