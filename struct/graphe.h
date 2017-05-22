#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdbool.h>
#define NOIR '*'
#define BLANC 'o'
#define VIDE '.'


typedef struct adjliste_node_s * adjliste_node_t;
typedef struct adjliste_s * adjliste_t;
typedef struct graphe_s * graphe_t;
graphe_t creer_graph(int N);
void detruire_graphe(graphe_t * graphe);
void ajouterSommet(graphe_t * graphe, int vertex, int nb_liens);
void ajouterArrete(graphe_t * graphe, int vertex1 , int vertex2);
void changerCouleur(graphe_t * g ,char couleur, int vertex);
char getCouleur(graphe_t graphe, int vertex);
// bool estAdjacent(graphe_t sommet1,graphe_t sommet2);
// bool estConnecte(graphe_t sommet1,graphe_t sommet2);
// int getDistance(graphe_t sommet1, graphe_t sommet2);
void afficherGraphe(graphe_t graphe);

#endif
