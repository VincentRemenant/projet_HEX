#include <stdlib.h>
#include <stdio.h>
#include "graphe.h"

struct adjliste_node_s{
  int vertex;
  char couleur;
  int nb_membres;
  int nb_liens;
  bool visited; /*Pour le parcours du graphe, cet variable indique si ce noeud a déja été visité*/
  adjliste_node_t * suivant;
};

struct graphe_s{
  int nb_vertices;
  adjliste_node_t * adjListe;
};

adjliste_node_t creer_node(int v, int nb_liens){
    adjliste_node_t node = (adjliste_node_t)malloc(sizeof(struct adjliste_node_s));
    if(!node)
        return NULL;
    node->nb_liens = nb_liens;
    node->vertex = v;
    node->suivant = malloc(nb_liens * sizeof(struct adjliste_node_s));
    node->suivant[0]= node;
    node->nb_membres = 1;
    node->visited = false;
    node->couleur = VIDE ;
    return node;
}
graphe_t creer_graph(int N){
    graphe_t g = (graphe_t)malloc(sizeof(struct graphe_s));
    if(!g)
        return NULL;
    g->nb_vertices = N;

    /* Créer une liste de sommet adjacent*/
    g->adjListe = malloc(N * sizeof(struct adjliste_node_s));
    if(!g->adjListe)
        return NULL;
    return g;
}

void detruire_graphe(graphe_t * graphe){
    if(*graphe)
    {
        if((*graphe)->adjListe)
        {
            int v;
            for (v = 0; v < (*graphe)->nb_vertices; v++)
            {
                adjliste_node_t adjListe = (*graphe)->adjListe[v];
                free(adjListe->suivant);
                free(adjListe);
            }
        }
        free((*graphe)->adjListe);
        free(*graphe);

    }
}

bool estVide(graphe_t g){
  return g->adjListe[0]==NULL;
}
bool estPlein(graphe_t g){
  return g->adjListe[(g->nb_vertices)-1]!=NULL;
}

bool estAdjacent(graphe_t graphe, int vertex1,int vertex2, char couleur){
  adjliste_node_t *node = &(graphe->adjListe[vertex1]);
  adjliste_node_t node2 = graphe->adjListe[vertex2];
  adjliste_node_t cur = *node;
  for(int i = 0; cur!=NULL ; i++, cur = cur->suivant[i]){
    if(cur->vertex == vertex2 && cur->couleur == node2->couleur)
      return true;
  }
  return false;
}

int getNombreSommet(graphe_t graphe){
  return graphe->nb_vertices;
}

void ajouterSommet(graphe_t * graphe, int vertex, int nb_liens){
    adjliste_node_t node = creer_node(vertex, nb_liens);
    (*graphe)->adjListe[vertex] = node;
}

void ajouterArrete(graphe_t * graphe, int vertex1 , int vertex2){
    adjliste_node_t  node1 = (*graphe)->adjListe[vertex1];
    adjliste_node_t  node2 = (*graphe)->adjListe[vertex2];
    node1->suivant[node1->nb_membres] = node2;
    node2->suivant[node2->nb_membres] = node1;
    node1->nb_membres++;
    node2->nb_membres++;
}
void changerCouleur(graphe_t * graphe ,char couleur, int vertex){
  ((*graphe)->adjListe[vertex])->couleur = couleur;
}
char getCouleur(graphe_t g, int vertex){
  return (g->adjListe[vertex])->couleur;
}


void afficherGraphe(graphe_t graphe){
    int i;
    printf("numeroVertex # couleur\n");
    for (i = 0; i < graphe->nb_vertices; i++){
        adjliste_node_t adjListe = graphe->adjListe[i];
        printf("liste d'adjacence vertex %d : ", i );
        for(int j = 0 ; j < adjListe->nb_membres; j++){
            printf("%d#%c->", adjListe->suivant[j]->vertex, getCouleur(graphe, adjListe->suivant[j]->vertex));
        }
        printf("Fin_liste\n");
    }
}
