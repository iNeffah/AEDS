#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#define SUCESSO 0

void grau_vertices_m (int ** matriz, int n_vertices) {
    int grau;
    for (int i=0; i<n_vertices; i++) {
        for (int j=0; j<n_vertices; j++) {
            if (matriz[i][j] != 0) {
                grau++;
            }
        }
        printf("Grau vertice %d: %d\n", i, grau);
        grau = 0;
    }
}

int main(int argc, char **argv) {
    int **matriz_adj, n_vertices, *adj, n_adj, j;

    printf("Quantidade de vertices do grafo: ");
    scanf("%d", &n_vertices);
    getchar();
    matriz_adj = (int**) malloc (n_vertices * sizeof(int*));
    adj = NULL;

    for (int i=0; i<n_vertices; i++) {
        printf("Quantidade de vertices adjacentes ao vertice %d: ", i);
        scanf("%d", &n_adj);
        getchar();

        printf("Insira os valores adjacentes ao vertice %d: ", i);
        adj = (int*) realloc(adj, n_adj * sizeof(int));
        for (j=0; j<n_adj; j++) {
            scanf("%d", &adj[j]);
            getchar();
        }

        matriz_adj[i] = (int*) malloc (n_vertices * sizeof(int));
        for (j=0; j<n_vertices; j++) {
            for (int e=0; e<n_adj; e++) {
                if (j == adj[e]) {
                    matriz_adj[i][j] = 1;
                    break;
                } else {
                    matriz_adj[i][j] = 0;
                }
            }
        }
    }
    grau_vertices_m(matriz_adj, n_vertices);
    return SUCESSO;
}
