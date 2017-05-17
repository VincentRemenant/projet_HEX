#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdbool.h>
#define NOIR 1
#define BLANC 0
#define TRANSPARENT 2


typedef struct adjliste_node_s * adjliste_node_t;
typedef struct adjliste_s * adjliste_t;
typedef struct graphe_s * graphe_t;
adjliste_node_t creer_node(int v);
graphe_t creer_graph(int N);
void detruire_graphe(graphe_t * graphe);
void ajouterSommet(graphe_t * graphe, int src, int dest);
void changerCouleur(graphe_t g,int couleur, int vertex);
// bool estAdjacent(graphe_t sommet1,graphe_t sommet2);
// bool estConnecte(graphe_t sommet1,graphe_t sommet2);
// int getDistance(graphe_t sommet1, graphe_t sommet2);
void afficherGraphe(graphe_t graphe);

#endif
