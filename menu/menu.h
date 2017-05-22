/*************************************************************
* menu.h - Différentes fonctions du menu de jeu de hex       *
* Dépendance : TAD graphe                                    *
* Dernière modification : 22/05/2017                         *
* Auteur : Romain Roy                                        *
**************************************************************/

#include "../struct/graphe.h"

void menu(void);

void nouvellePartie(void);

void sauvegarder(graphe_t plateau);

int charger(char *fichier);

void afficherRegles(void);

void parametres(int *largeur, int *difficulte);
