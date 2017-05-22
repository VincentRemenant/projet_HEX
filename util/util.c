#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "util.h"

#define NB_CHAR_LIGNE 80

char *saisir() {
    long taille = 0;
    char *chaine = calloc(0,sizeof(char));
    char caractere;
    while ((caractere = getc(stdin)) != '\n') {
        taille++;
        chaine = realloc(chaine,taille);
        chaine[taille-1] = caractere;
    }
    return chaine;
}

int lireFichier(char *fichier) {
    FILE *f;
    char ligne[NB_CHAR_LIGNE];
    if ((f = fopen(fichier, "rt")) == NULL) {
        perror(fichier);
        exit(1);
    }
    while (fgets(ligne, NB_CHAR_LIGNE, f) != NULL)
        printf("%s", ligne);
    fclose(f);
    return 0;
}
