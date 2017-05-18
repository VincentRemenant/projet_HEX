
#include <stdio.h>
#include "graphe.h"

int main(){
    graphe_t graphe = creer_graph(5);

    ajouterSommet(&graphe, 0, 1);
    ajouterSommet(&graphe, 0, 4);
    ajouterSommet(&graphe, 1, 2);
    ajouterSommet(&graphe, 1, 3);
    ajouterSommet(&graphe, 1, 4);
    ajouterSommet(&graphe, 2, 3);
    ajouterSommet(&graphe, 3, 4);
    afficherGraphe(graphe);

    changerCouleur(&graphe, 1 , 1);
    afficherGraphe(graphe);
    detruire_graphe(&graphe);


}
