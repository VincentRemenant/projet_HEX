#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "util.h"
#include "menu.h"

// Ajout de couleurs dans une prochaine version

void menu() {
    char *choix;
    printf("Jeu de Hex\n");
    do {
        printf(">>> ");
        choix = saisir();
        if (strcmp(choix,"new") == 0) nouvellePartie();
        else if (strcmp(choix,"save") == 0) sauvegarder();
        else if (strcmp(choix,"load") == 0) charger();
        else if (strcmp(choix,"how") == 0) afficherRegles();
        else if (strcmp(choix,"set") == 0) parametres();
        else if (strcmp(choix,"exit") == 0)
            printf("Ce fut un plaisir de jouer avec vous, à bientôt !\n");
        else if (strcmp(choix,"help") == 0) {
            printf("new  : Commence une nouvelle partie\n");
            printf("save : Enregistre une partie en cours\n");
            printf("load : Reprend une partie enregistrée\n");
            printf("how  : Affiche les règles du jeu de hex\n");
            printf("set  : Permet d'accèder au paramètres\n");
            printf("exit : Quitte le jeu\n");
        } else if (strcmp(choix,"") == 0)
            /* rien */;
        else
            printf("Cette commande n'est pas reconnue : faites \"help\" pour obtenir la liste des commandes\n");
    } while (strcmp(choix,"exit") != 0);
    free(choix);
}

void nouvellePartie() {

}

void sauvegarder() {

}

void charger() {

}

void afficherRegles() {
    printf("Au début de partie, un tablier vide, sépare deux joueurs. Ce tablier représente un losange formé par des hexagones réguliers. Chaque joueur est représenté par une couleur. Les joueurs possèdent des pions à leur couleur qu'ils disposent tour à tour sur une case de leur choix et un par un. Le tablier se remplit ainsi progressivement.\n");
    printf("L'objectif d'un joueur, est de relier les deux côtés opposés du losange symbolisés par sa couleur. Si la configuration des pions de sa couleur permet la création d'une ligne continue reliant un côté de sa couleur à l'autre, le joueur a gagné et le jeu s'arrête.\n");
}

void parametres() {

}
