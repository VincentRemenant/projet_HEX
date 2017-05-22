#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"


/*Struture de l'élement groupe contenant une liste de vertex*/
typedef struct groupe_s{
  int nb_node;
  int * chaine;
}* groupe_t;
/*Structure d'un joueur, contenant une liste de groupe*/
struct joueur_s{
  char couleur;
  int nb_groupe;
  groupe_t * groupes;
};

/*crée un groupe*/
groupe_t creer_groupe(){
  groupe_t groupe = (groupe_t) malloc(sizeof(struct groupe_s));
  groupe->chaine = malloc(sizeof(int));
  groupe->nb_node=0;
  return groupe;
}
/*crée un joueur*/
joueur_t creer_joueur(char couleur){
  joueur_t joueur =(joueur_t)  malloc(sizeof(struct joueur_s));
  joueur->nb_groupe = 0;
  joueur->groupes = malloc(sizeof(groupe_t));
  joueur->couleur =  couleur;
  return joueur;
}
void detruire_joueur(joueur_t * joueur){
  free((*joueur)->groupes);
  free(*joueur);
}
/*créer un groupe et retourne son indice dans la liste des groupes*/
int ajouterUnGroupe(joueur_t * joueur){
  (*joueur)->groupes[(*joueur)->nb_groupe] = creer_groupe();
  return (*joueur)->nb_groupe++;
}
/*ajoute un vertex au groupe en paramètre*/
void ajouterVertex(groupe_t * groupe, int vertex){
  (*groupe)->chaine[(*groupe)->nb_node++] = vertex;
}
/*Place un jeton coloré sur le plateau du jeu*/
int placerJeton(graphe_t * graphe,joueur_t * joueur, int vertex){
  if(getCouleur(*graphe, vertex) == VIDE){
    changerCouleur(graphe, (*joueur)->couleur , vertex);
    for (int i  = 0  ; i< (*joueur)->nb_groupe ; i++){
      groupe_t * groupe = &((*joueur)->groupes[i]);
      for(int j = 0 ; j < (*groupe)->nb_node ;j++ ){
        if( estAdjacent(*graphe, (*groupe)->chaine[j], vertex,(*joueur)->couleur )){
          ajouterVertex(groupe, vertex);
          return 0;
        }
      }
    }

    int g = ajouterUnGroupe(joueur);
    ajouterVertex(&((*joueur)->groupes[g]), vertex);
    return 0;
  }
  return 1;

}
char estTermine(joueur_t joueur1 , joueur_t joueur2){
    int res = 0;
    for (int i1  = 0  ; i1< joueur1->nb_groupe ; i1++){
      groupe_t  groupe1 = joueur1->groupes[i1];
      for(int j1 = 0; j1 < groupe1->nb_node ;j1++){
        if(groupe1->chaine[j1] >=0 && groupe1->chaine[j1]<4)
          res++;
      }
    }
    if(res==2)
      return joueur1->couleur;
    res=0;
    for (int i2  = 0  ; i2< joueur2->nb_groupe ; i2++){
      groupe_t  groupe2 = joueur2->groupes[i2];
      for(int j2 = 0; j2 < groupe2->nb_node ;j2++){
        if(groupe2->chaine[j2] >=0 && groupe2->chaine[j2]<4)
          res++;
      }
    }
    if(res==2)
      return joueur2->couleur;

    return '.';


}
char getCouleurJoueur(joueur_t joueur){
  return joueur->couleur;
}
