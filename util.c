#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "util.h"

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

/* Une autre fonction de saisie dynamique

char *saisir() {
    size_t taillbuff = 10;
    char *buffer = malloc(taillbuff);
    if (buffer == NULL) return NULL;
    char *p;
    for (p = buffer; *p = getchar() != '\n' && *p != EOF; p++)
        if (p-buffer == taillbuff-1) {
            p = realloc(buffer, taillbuff *= 2);
            if (p == NULL) {
                free(buffer);
                return NULL;
            } else buffer = p;
            p += taillbuff/2-1;
        }
    *p = 0;
    p = realloc(buffer,p-buffer+1);
    if (p == NULL) {
        free(buffer);
        return NULL;
    } else return p;
}
*/
