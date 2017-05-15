#include <stdlib.h>
#include <stdio.h>
#include "graphe.h"

#define NOIR 1
#define BLANC 0
#define TRANSPARENT 2


struct adjliste_node_s{
  int vertex;
  adjliste_node_t suivant;
};
struct adjliste_s{
  int nb_membres;
  adjliste_node_t tete;
};

struct graphe_s{
  int nb_vertices;
  int couleur;
  adjliste_t adjListe;
};

adjliste_node_t creer_node(int v){
    adjliste_node_t node = (adjliste_node_t)malloc(sizeof(struct adjliste_node_s));
    if(!node)
        return NULL;

    node->vertex = v;
    node->suivant = NULL;

    return node;
}
graphe_t creer_graph(int N){
    int i;
    graphe_t g = (graphe_t)malloc(sizeof(struct graphe_s));
    if(!g)
        return NULL;
    g->nb_vertices = N;
    g->couleur = TRANSPARENT;

    /* Créer une liste de sommet adjacent*/
    g->adjListe = (adjliste_t)malloc((4+(N*N)) * sizeof(struct adjliste_s));
    if(!g->adjListe)
        return NULL;
    for(i = 0; i < N; i++)
    {
        g->adjListe[i].tete = NULL;
        g->adjListe[i].nb_membres = 0;
    }
    return g;
}

void detruire_graphe(graphe_t * graphe){
    if(*graphe)
    {
        if((*graphe)->adjListe)
        {
            int v;
            /*libère les noeuds*/
            for (v = 0; v < (*graphe)->nb_vertices; v++)
            {
                adjliste_node_t adjListe = (*graphe)->adjListe[v].tete;
                while (adjListe)
                {
                    adjliste_node_t tmp = adjListe;
                    adjListe = adjListe->suivant;
                    free(tmp);
                }
            }
            /*libère la liste d'adjacence*/
            free((*graphe)->adjListe);
        }
        /*libère le graphe*/
        free(*graphe);
    }
}

void ajouterSommet(graphe_t * graphe, int src, int dest){

    /* Add an edge from src to dst in the adjacency list*/
    adjliste_node_t node = creer_node(dest);
    node->suivant = (*graphe)->adjListe[src].tete;
    (*graphe)->adjListe[src].tete = node;
    (*graphe)->adjListe[src].nb_membres++;

    node = creer_node(src);
    node->suivant = (*graphe)->adjListe[dest].tete;
    (*graphe)->adjListe[dest].tete = node;
    (*graphe)->adjListe[dest].nb_membres++;


}

void afficherGraphe(graphe_t graphe)
{
    int i;
    for (i = 0; i < graphe->nb_vertices; i++)
    {
        adjliste_node_t adjListe = graphe->adjListe[i].tete;
        printf("\n%d: ", i);
        while (adjListe)
        {
            printf("%d->", adjListe->vertex);
            adjListe = adjListe->suivant;
        }
        printf("FIN\n");
    }
}
