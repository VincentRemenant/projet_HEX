#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "util.h"

char *saisir() {
    long taille = 0;
    char *chaine = calloc(0, sizeof(char));
    char caractere;
    while ((caractere = getc(stdin)) != '\n') {
        taille++;
        chaine = realloc(chaine,taille);
        chaine[taille-1] = caractere;
    }
    return chaine;
}
