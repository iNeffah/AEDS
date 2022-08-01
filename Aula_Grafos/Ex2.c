#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#define SUCESSO 0

void grau_vertices_l (Lista **lista, int n_vertices) {
    int grau;
    Lista *l3;
    for(int i=0; i<n_vertices; i++){
        for(l3 = lista[i]; l3 != NULL; l3=l3->prox) {
            grau++;
        }
        printf("Grau vertice %d: %d\n", i, grau);
        i++;
        grau = 0;
    }
}
int main(int argc, char **argv) {
    int n_vertices, *adj, n_adj, j;
    Lista **lst_adj;

    printf("Quantidade de vertices do grafo: ");
    scanf("%d", &n_vertices);
    getchar();
    lst_adj = (Lista**) malloc (n_vertices * sizeof(Lista*));
    adj = NULL;

    for (int i=0; i<n_vertices; i++) {
        lst_insere(lst_adj, i);
        printf("Quantidade de vertices adjacentes ao vertice %d: ", i);
        scanf("%d", &n_adj);
        getchar();
        lst_adj[i] = (Lista*) malloc(n_adj * sizeof(Lista));
        adj = (int*) realloc(adj, n_adj * sizeof(int));

        printf("Insira os valores adjacentes ao vertice %d: ", i);
        for (j=0; j<n_adj; j++) {
            scanf("%d", &adj[j]);
            getchar();
            lst_insere(lst_adj[i], adj[j]);
        }
    }
    printf("a");
    grau_vertices_l(lst_adj, n_vertices);
    printf("a");
    return SUCESSO;
}