#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#define SUCESSO 0

void grau_vertices_l (Lista **lista, int n_vertices) {
    int grau = 0;
    Lista *l2;
    for(int i=0; i<n_vertices; i++){
        printf("c");
        for (l2 = lista[i]; l2 != NULL; l2=l2->prox) {
            grau++;
            printf("d");
        }
        printf("Grau vertice %d: %d\n", i, grau);
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
        printf("Quantidade de vertices adjacentes ao vertice %d: ", i);
        scanf("%d", &n_adj);
        getchar();
        lst_adj[i] = lst_cria();
        adj = (int*) realloc(adj, n_adj * sizeof(int));

        printf("Insira os valores adjacentes ao vertice %d: ", i);
        for (j=0; j<n_adj; j++) {
            scanf("%d", &adj[j]);
            getchar();
            lst_adj[i] = lst_insere(lst_adj[i], adj[j]);
        }
    }
    grau_vertices_l(lst_adj, n_vertices);

    for(j=0; j<n_vertices; j++) {
        lst_libera(lst_adj[j]);
    }
    free(lst_adj);
    free(adj);
    return SUCESSO;
}