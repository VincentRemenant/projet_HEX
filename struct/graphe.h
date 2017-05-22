/*************************************************************
* jeu.h - Struture du plateau du jeu de hex (graphe)         *
* Dépendance : aucune                                        *
* Dernière modification : 22/05/2017                         *
* Auteur : Vincent REMENANT                                  *
**************************************************************/


#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdbool.h>
#define NOIR '*'
#define BLANC 'o'
#define VIDE '.'


typedef struct adjliste_node_s * adjliste_node_t;
typedef struct graphe_s * graphe_t;
graphe_t creer_graph(int N);
void detruire_graphe(graphe_t * graphe);
bool estVide(graphe_t g);
bool estPlein(graphe_t g);
void ajouterSommet(graphe_t * graphe, int vertex, int nb_liens);
void ajouterArrete(graphe_t * graphe, int vertex1 , int vertex2);
void changerCouleur(graphe_t * g ,char couleur, int vertex);
char getCouleur(graphe_t graphe, int vertex);
int getNombreSommet(graphe_t graphe);
bool estAdjacent(graphe_t graphe, int vertex1,int vertex2, char couleur);
void afficherGraphe(graphe_t graphe);

#endif
