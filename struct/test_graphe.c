
#include <stdio.h>
#include "graphe.h"

int main(){
    printf("Début\n");
    graphe_t graphe = creer_graph(5);
    printf("Vérification si graphe vide : %d\n",estVide(graphe) );
    printf("ajout sommet\n");

    ajouterSommet(&graphe, 0, 2);
    ajouterSommet(&graphe, 1, 3);
    ajouterSommet(&graphe, 2, 2);
    ajouterSommet(&graphe, 3, 1);
    ajouterSommet(&graphe, 4, 2);
    printf("Vérification si graphe plein : %d\n", estPlein(graphe) );
    printf("ajout arrete\n");
    ajouterArrete(&graphe,0, 4);//0->4  4->0
    ajouterArrete(&graphe,0, 2);//0->2  2->0
    ajouterArrete(&graphe,1, 2);//1->2  2->1
    ajouterArrete(&graphe,1, 3);//1->3  3->1
    ajouterArrete(&graphe,1, 4);//1->4  4->1


    afficherGraphe(graphe);
    printf("changement de couleur du vertex 1 en noir\n");
    changerCouleur(&graphe, NOIR , 1);
    printf(" couleur vertex n°1 : %c \n", getCouleur(graphe,1));
    afficherGraphe(graphe);
    detruire_graphe(&graphe);


}
