#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "ihm.h"
#include "../struct/graphe.h"

void interface(graphe_t plateau) {
    int taille = sqrt(getNombreSommet(plateau));
    printf("\n");
    for (int i=0; i<taille; i++) printf("W ");
    printf("W/B\n");
    for (int i=4; i<taille*taille+4; i++) {
        if (i%taille == 4) {
            for (int j=0; j<i/taille+1; j++) printf(" ");
            printf("B ");
        }
        printf("%c ", getCouleur(plateau,i));
        if (i%taille == 3) printf("B\n");
    }
    for (int j=0; j<taille+1; j++) printf(" ");
    printf("B/");
    for (int i=0; i<taille+1; i++) printf("W ");
    printf("\n");
}
