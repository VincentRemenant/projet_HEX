#include <stdlib.h>
#include <stdio.h>
#include "jeu.h"
int main(void){
  joueur_t joueur = creer_joueur('o');
  detruire_joueur(&joueur);
  return 0;
}
