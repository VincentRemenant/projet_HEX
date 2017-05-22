/*************************************************************
* menu.h - Différentes fonctions du menu de jeu de hex       *
* Dépendance : TAD graphe, fonctions d'util.h                *
* Dernière modification : 22/05/2017                         *
* Auteur : Romain Roy                                        *
**************************************************************/

#include "../struct/graphe.h"

void menu();

graphe_t nouvellePartie(int taille);

int sauvegarder(graphe_t plateau);

graphe_t charger();

void afficherRegles();

void parametres(int *largeur);

graphe_t jouer(graphe_t plateau, int tour);
