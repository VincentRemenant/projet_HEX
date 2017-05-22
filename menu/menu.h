/*************************************************************
* menu.h - Différentes fonctions du menu de jeu de hex       *
* Dépendance : TAD graphe, fonctions d'util.h                *
* Dernière modification : 22/05/2017                         *
* Auteur : Romain Roy                                        *
**************************************************************/

#include "../struct/graphe.h"

void menu(void);

void nouvellePartie(int taille, int difficulte);

int sauvegarder(graphe_t plateau);

int charger(void);

void afficherRegles(void);

void parametres(int *largeur, int *difficulte);
