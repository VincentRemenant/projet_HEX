#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "menu.h"

void menu() {
    char choix[5];
    printf("Jeu de HEX\n");
    do {
        printf(">>> ");
        scanf("%s",choix);
        if (strcmp(choix,"new") == 0) nouvellePartie();
        if (strcmp(choix,"save") == 0) sauvegarder();
        if (strcmp(choix,"load") == 0) charger();
        if (strcmp(choix,"how") == 0) afficherRegles();
        if (strcmp(choix,"set") == 0) parametres();
        if (strcmp(choix,"quit") == 0) {
            printf("\n\tCe fut un plaisir de jouer avec vous, à la prochaine !\n\n");
        }
        if (strcmp(choix,"help") == 0) {
            printf("\n\tnew  : Commence une nouvelle partie\n");
            printf("\tsave : Enregistre une partie\n");
            printf("\tload : Reprend en cours une partie enregistrée\n");
            printf("\thow  : Affiche les règles du jeu\n");
            printf("\tset  : Permet d'accèder au paramètres\n");
            printf("\tquit : Quitte le jeu de Hex\n\n");
        }
    } while (strcmp(choix,"quit") != 0);
}

void nouvellePartie() {

}

void sauvegarder() {

}

void charger() {

}

void afficherRegles() {

}

void parametres() {

}
