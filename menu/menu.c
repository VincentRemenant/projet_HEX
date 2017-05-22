#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "menu.h"
#include "../util/util.h"
#include "../struct/graphe.h"

// Ajout de couleurs dans une prochaine version

void menu(void) {
    char *choix;
    graphe_t plateau;
    int taille = 11, difficulte = 0;
    plateau = creer_graph(taille);
    printf("Jeu de Hex\n");
    do {
        printf(">>> ");
        choix = saisir();
        if (strcmp(choix,"nouveau") == 0) nouvellePartie(taille, difficulte);
        else if (strcmp(choix,"sauver") == 0) sauvegarder(plateau);
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

void nouvellePartie(int taille, int difficulte) {
    graphe_t plateau;
    /* Création du plateau de jeu vide */
    plateau = creer_graph(taille);
    for (int i=0; i<taille*taille+4; i++) {
        ajouterSommet(&plateau, i, 6);
        changerCouleur(&plateau, VIDE, i);
    }
    /* Ajout des arrêtes, d'abord les 4 côtés */
    for (int i=0; i<4; i++) ajouterSommet(&plateau, i, taille);
    for (int i=4; i<taille*taille+3; i+=taille) ajouterArrete(&plateau, i, 0);
    for (int i=4; i<taille+4; i++) ajouterArrete(&plateau, i, 1);
    for (int i=3+taille; i<taille*taille+4; i+=taille) ajouterArrete(&plateau, i, 2);
    for (int i=taille*taille+5-taille; i<taille*taille+4; i++) ajouterArrete(&plateau, i, 3);
    for (int i=4; i<taille*taille+4-taille; i++) {
        ajouterArrete(&plateau, i, i+1);
        ajouterArrete(&plateau, i, i+taille);
    }
    // lancer partie
}

int sauvegarder(graphe_t plateau) {
    printf("Saisissez le nom du fichier de sauvegarde : ");
    char *choix = saisir();
    char *fichier = calloc(0, sizeof(char));
    strcat(fichier,"saves/");
    strcat(fichier,choix);
    strcat(fichier,".txt");
    FILE *f;
    if ((f = fopen(fichier, "w")) == NULL) {
        perror(fichier);
        return 1;
    }
    int taille = getNombreSommet(plateau);
    fprintf(f, "\\hex\n\\dim %d\n\\board", taille);
    for (int i=4; i<taille*taille+4; i++) {
        if (i%taille == 4) fprintf(f, "\n");
        fprintf(f, "%c ", getCouleur(plateau, i));
    }
    fprintf(f, "\n\\endboard\n\\endhex\n");
    fclose(f);
    return 0;
}

int charger(void) {
    printf("Saisissez le nom du fichier de sauvegarde à charger : ");
    char *choix = saisir();
    char *fichier = calloc(0,sizeof(char));
    strcat(fichier,"saves/");
    strcat(fichier,choix);
    strcat(fichier,".txt");
    FILE *f; int taille, i; char pion;
    if ((f = fopen(fichier, "r")) == NULL) {
        perror(fichier);
        return 1;
    }
    /* Récupération de la taille de la grille */
    fseek(f, 10, SEEK_SET);
    fscanf(f, "%d", &taille);
    graphe_t plateau = creer_graph(taille*taille+4);
    /* Récupération de la disposition des pions */
    fseek(f, 10, SEEK_CUR);
    for (i=0; i<4; i++) ajouterSommet(&plateau, i, taille);
    i = 4;
    do {
        fscanf(f, "%c", &pion);
        if (pion == NOIR || pion == BLANC || pion == VIDE) {
            ajouterSommet(&plateau, i, 6);
            changerCouleur(&plateau, pion, i++);
        }
    } while (!estPlein(plateau));
    /* Ajout des arrêtes, d'abord les 4 côtés */
    for (i=4; i<taille*taille+3; i+=taille) ajouterArrete(&plateau, i, 0);
    for (i=4; i<taille+4; i++) ajouterArrete(&plateau, i, 1);
    for (i=3+taille; i<taille*taille+4; i+=taille) ajouterArrete(&plateau, i, 2);
    for (i=taille*taille+5-taille; i<taille*taille+4; i++) ajouterArrete(&plateau, i, 3);
    for (i=4; i<taille*taille+4-taille; i++) {
        ajouterArrete(&plateau, i, i+1);
        ajouterArrete(&plateau, i, i+taille);
    }
    fclose(f);
    free(fichier);
    // lancer partie
    return 0;
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
