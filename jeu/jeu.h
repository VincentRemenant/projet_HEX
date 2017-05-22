/*************************************************************
* jeu.h - Struture général du jeu de hex                     *
* Dépendance : TAD graphe                                    *
* Dernière modification : 22/05/2017                         *
* Auteur : Vincent REMENANT                                  *
**************************************************************/


#ifndef JEU_H
#define JEU_H

#include "../struct/graphe.h"

typedef struct joueur_s * joueur_t;
/*crée un joueur avec sa couleur en parametre*/
joueur_t creer_joueur(char couleur);
/*Détruit un joueur permettant de libérer de la la mémoire*/
void detruire_joueur(joueur_t * joueur);
/*Change la couleur  d'un sommet par la couleur d'un joueur du graphe passé en parametre*/
void placerJeton(graphe_t * graphe,joueur_t * joueur, int vertex);
/*vérifie si les joueurs ont une chaine de vertex gagnante et retourne la couleur gagnante*/
char estTermine(joueur_t joueur1 , joueur_t joueur2);
char getCouleurJoueur(joueur_t joueur);
#endif
