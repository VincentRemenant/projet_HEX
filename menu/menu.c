#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "menu.h"
#include "../util/util.h"
#include "../struct/graphe.h"

// Ajout de couleurs dans une prochaine version

void menu(void) {
    char *choix;
    int taille = 11, difficulte = 0;
    printf("Jeu de Hex\n");
    do {
        printf(">>> ");
        choix = saisir();
        if (strcmp(choix,"nouveau") == 0) nouvellePartie();
        else if (strcmp(choix,"sauver") == 0) /* sauvegarder(graphe_t plateau); */;
        else if (strcmp(choix,"charger") == 0) charger();
        else if (strcmp(choix,"regles") == 0) afficherRegles();
        else if (strcmp(choix,"options") == 0) parametres(&taille, &difficulte);
        else if (strcmp(choix,"quitter") == 0)
            printf("Ce fut un plaisir de jouer avec vous, à bientôt !\n");
        else if (strcmp(choix,"aide") == 0) {
            printf("nouveau : Commence une nouvelle partie\n");
            printf("sauver  : Enregistre une partie en cours\n");
            printf("charger : Reprend une partie enregistrée\n");
            printf("regles  : Affiche les règles du jeu de Hex\n");
            printf("options : Permet d'accèder au paramètres\n");
            printf("quitter : Quitte le jeu\n");
        } else if (strcmp(choix,"") == 0)
            /* rien */;
        else
            printf("Cette commande n'est pas reconnue : faites \"aide\" pour obtenir la liste des commandes\n");
    } while (strcmp(choix,"quitter") != 0);
    free(choix);
}

void nouvellePartie(void) {
    // jeu @Vincent
}

void sauvegarder(graphe_t plateau) {
    // @Romain
}

void charger(void) {
    // @Romain
    // jeu @Vincent
}

void afficherRegles(void) {
    printf("Au début de partie, un tablier vide, sépare deux joueurs. Ce tablier représente un losange formé par des hexagones réguliers. Chaque joueur est représenté par une couleur. Les joueurs possèdent des pions à leur couleur qu'ils disposent tour à tour sur une case de leur choix et un par un. Le tablier se remplit ainsi progressivement.\n");
    printf("L'objectif d'un joueur, est de relier les deux côtés opposés du losange symbolisés par sa couleur. Si la configuration des pions de sa couleur permet la création d'une ligne continue reliant un côté de sa couleur à l'autre, le joueur a gagné et le jeu s'arrête.\n");
}

void parametres(int *taille, int *difficulte) {
    char *choix;
    do {
        printf("Saisissez la taille de grille désirée : ");
        choix = saisir();
        *taille = atoi(choix);
    } while (*taille < 5 || *taille > 50);
    printf("La taille est désormais de %d.\n",*taille);
    do {
        printf("Choix de la difficulté : \n");
        printf("Saisissez \"joueur\" pour jouer contre un ami ou \"facile\" pour une IA facile.\n");
        printf("Saisissez la difficulté désirée : ");
        choix = saisir();
        if (strcmp(choix,"joueur") == 0) {
            *difficulte = 0;
            printf("Le jeu est maintenant réglé en joueur contre joueur.\n");
        }
        else if (strcmp(choix,"facile") == 0) {
            *difficulte = 1;
            printf("Le jeu est maintenant réglé contre une IA facile.\n");
        }
        else printf("Choix non valide.\n");
    } while (strcmp(choix,"joueur") != 0 && strcmp(choix,"facile") != 0);
}
