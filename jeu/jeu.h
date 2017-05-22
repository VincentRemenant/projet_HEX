#ifndef JEU_H
#define JEU_H

#include "../struct/graphe.h"
typedef struct joueur_s * joueur_t;
joueur_t creer_joueur(char couleur);
void detruire_joueur(joueur_t * joueur);
void placerJeton(graphe_t * graphe,joueur_t * joueur, int vertex);
char estTermine(joueur_t joueur1 , joueur_t joueur2);

#endif
