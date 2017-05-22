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

/*Structure de l'élement constituant le graphe*/
typedef struct adjliste_node_s * adjliste_node_t;
/*structure du graphe*/
typedef struct graphe_s * graphe_t;
/*Crée un graphe , on passe ne paramètre le nombre de sommet que contient le graphe*/
graphe_t creer_graph(int N);
/*libère la mémoire */
void detruire_graphe(graphe_t * graphe);
bool estVide(graphe_t g);
bool estPlein(graphe_t g);
/*Ajoue un sommet au graphe, avec comme paramètre le graphe , le n° du vertex et le nombre d'adjacence possible*/
void ajouterSommet(graphe_t * graphe, int vertex, int nb_liens);
/*Fonction liant deux sommets*/
void ajouterArrete(graphe_t * graphe, int vertex1 , int vertex2);
/*change la couleur d'un vertex*/
void changerCouleur(graphe_t * g ,char couleur, int vertex);
/*Getter sur la couleur d'un vecteur passé en paramètre*/
char getCouleur(graphe_t graphe, int vertex);
/*Getter sur le nombre de vertex maximum du graphe*/
int getNombreSommet(graphe_t graphe);
/*Vérifie l'adjacence entre deux vertex, retourne vrai si ils sont adjacents et de même couleur*/
bool estAdjacent(graphe_t graphe, int vertex1,int vertex2, char couleur);
/*Affiche toutes les listes d'adjacence du graphe pour chaque vertex*/
void afficherGraphe(graphe_t graphe);

#endif
