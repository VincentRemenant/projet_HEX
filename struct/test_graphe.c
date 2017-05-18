
#include <stdio.h>
#include "graphe.h"

int main(){
    printf("Début\n");
    graphe_t graphe = creer_graph(5);
    printf("ajout sommet\n");
    for(int i = 0 ; i <5 ; i++){
      ajouterSommet(&graphe, i, 6);
    }
    printf("ajout arrete\n");
    ajouterArrete(&graphe,0, 4);
    ajouterArrete(&graphe,0, 2);
    ajouterArrete(&graphe,0, 1);
    ajouterArrete(&graphe,1, 2);
    ajouterArrete(&graphe,2, 3);
    ajouterArrete(&graphe,4, 1);
    ajouterArrete(&graphe,3, 4);
    // ajouterSommet(&graphe, 0,1);
    // ajouterSommet(&graphe, 0, 4);
    // ajouterSommet(&graphe, 1, 2);
    // ajouterSommet(&graphe, 1, 3);
    // ajouterSommet(&graphe, 1, 4);
    // ajouterSommet(&graphe, 2, 3);
    // ajouterSommet(&graphe, 3, 4);
    afficherGraphe(graphe);

    changerCouleur(&graphe, 1 , 1);
    printf("couleur vertex n°1 : %d\n", getCouleur(graphe,1));
    afficherGraphe(graphe);
    detruire_graphe(&graphe);


}
