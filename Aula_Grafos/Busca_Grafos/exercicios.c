#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

#define SUCESSO 0
#define NULO   -1

int vert_predecessor(Lista ** grafo, int vertice, int n_vertices) {
    for (int i = 0; i < n_vertices; i++) {
        for (Lista *l = grafo[i]; l != NULL; l = l->prox) {
            if (l->vertice == vertice) {
                return i;
            }
        }
    }
    return -1;
}

// Funcao de Busca em Largura
Arv *BFS(Lista **grafo, int origem, int n_vertices, Arv *caminhos, FilaL *queue) {
    if (arv_pertence(caminhos, origem) == 0) { // Ve se o vertice ja esta na arvore
        if (queue == NULL) {
            queue = fila_cria_l();
        }
        
        // Insere os vertices adjacentes na fila
        for (Lista* l = grafo[origem]; l != NULL; l = l->prox) {
            if (arv_pertence(caminhos, l->vertice) == 0) {
                fila_insere_l(queue, l->vertice);
            }
        }

        caminhos  = arv_insere(caminhos, origem, vert_predecessor(grafo, origem, n_vertices), NULO);

        while (!fila_vazia_l(queue)) {
            caminhos = BFS(grafo, fila_retira_l(queue), n_vertices, caminhos, queue);
        }
    }
    return caminhos;
}

Arv *DFS(Lista **grafo, int origem, int n_vertices, Arv *caminhos) {
    if (arv_pertence(caminhos, origem) == 0) {
        caminhos = arv_insere(caminhos, origem, vert_predecessor(grafo, origem, n_vertices), NULO);

        for (Lista* l = grafo[origem]; l != NULL; l = l->prox) {
            if (arv_pertence(caminhos, l->vertice) == 0) {
                caminhos = DFS(grafo, l->vertice, n_vertices, caminhos);
            }
        }
        return caminhos;
    }
}

int main(int argc, char **argv) {
    int n_vertices, *adj, n_adj, j, origem;
    Lista **grafo;
    Arv *caminhos;

    printf("Quantidade de vertices do grafo: ");
    scanf("%d", &n_vertices);
    getchar();
    grafo = (Lista**) malloc (n_vertices * sizeof(Lista*));
    adj = NULL;

    for (int i=0; i<n_vertices; i++) {
        printf("Quantidade de vertices adjacentes ao vertice %d: ", i);
        scanf("%d", &n_adj);
        getchar();
        grafo[i] = lst_cria();
        adj = (int*) realloc(adj, n_adj * sizeof(int));

        printf("\nInsira os valores adjacentes ao vertice %d: ", i);
        for (j=0; j<n_adj; j++) {
            scanf("%d", &adj[j]);
            getchar();
            grafo[i] = lst_insere(grafo[i], adj[j]);
        }
    }
    printf("\nEscolha um vertice de origem para a busca: ");
    scanf("%d", &origem);
    caminhos = BFS(grafo, origem, n_vertices, caminhos, NULL);

    printf("---------------Busca em Largura---------------\n");
    for (int i=0; i<n_vertices; i++) {
        arv_imprime(caminhos, i);
        printf("\n");
    }

    printf("-------------Busca em Profundidade-------------\n");
    for (int i=0; i<n_vertices; i++) {
        arv_imprime(caminhos, i);
        printf("\n");
    }

    for(j=0; j<n_vertices; j++) {
        lst_libera(grafo[j]);
    }
    free(grafo);
    free(adj);
    return SUCESSO;
}
