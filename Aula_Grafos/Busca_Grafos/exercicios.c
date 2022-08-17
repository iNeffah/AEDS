#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

// Cores branco cinza e preto do vertice são definidos como 0 1 e 2
#define W       0
#define G       1
#define B       2
#define SUCESSO 0
#define NULO   -1

typedef struct info_BL {
    int *d; // distancias
    int *p; // predecessores
    int *colors; // cores
    FilaL *queue; // Fila para adjacentes
} Info_BL;

// Funcao de Busca em Largura
// Pegar info -> a cada loop pegar um vertice do grafo e inserir na arvore usando como base o predec -> retornar arvore -> imprimir caminhos
Arv *BFS(Lista **grafo, int origem, int n_vertices) {
    Info_BL info;
    Lista *aux1, *aux2;
    FilaL *vert_f = fila_cria_l(); // auxiliar para salvar os elementos a fila retirados
    Arv *caminhos = arv_criavazia();
    int distance = 0, n_adj = 0, v_count = 0; // para calculo da distância: numero de repetições do while = d

    info.d = (int *) malloc(n_vertices * sizeof(int));
    info.p = (int *) malloc(n_vertices * sizeof(int));
    info.colors = (int *) calloc(n_vertices, sizeof(int)); // calloc para setar todos os vertices de branco
    info.queue = fila_cria_l();
    printf("a");
    fila_insere_l(info.queue, origem);
    while (!(fila_vazia_l(info.queue))) {
        printf("b");
        for (aux1 = info.queue->ini; aux1 != NULL; aux1 = aux1->prox) { // Passa por cada vertice dentro da fila
            printf("c");
            info.colors[aux1->vertice] = G; // Coloca a cor do vertice
            info.d[aux1->vertice] = distance; // Coloca a distancia do vertice
            printf("d");
            // Atribuindo predecessor
            if (distance == 0) { // Se estiver na origem o predecessor eh nulo
                info.p[aux1->vertice] = NULO;
            }
            printf("e");
            // Pega o vertice visitado e coloca ele de precessor para seus adjacentes
            for (aux2 = grafo[aux1->vertice]; aux2 != NULL; aux2=aux2->prox) {
                info.p[aux2->vertice] = aux1->vertice;
            }
            printf("f");
            fila_insere_l(vert_f, fila_retira_l(info.queue)); // retira o vertice visitado da fila e insere no auxiliar vert_f
        }
        printf("g");
        // Insere elementos adjascentes aos elementos da fila na fila
        for (aux1 = vert_f->ini; aux1 != NULL; aux1 = aux1->prox) {
            for (aux2 = grafo[aux1->vertice]; aux2 != NULL; aux2=aux2->prox) {
                fila_insere_l(info.queue, aux2->vertice);
            }
        }
        printf("h");
        // Passa pelo grafo para colorir de preto vertices que já tiveram seus adjascentes visitados.
        for(int i=0; i<n_vertices; i++){
            for (aux2 = grafo[i]; aux2 != NULL; aux2=aux2->prox) {
                n_adj++;
                if ((info.colors[aux2->vertice] == G) || (info.colors[aux2->vertice] == B)) {
                    v_count++;
                }
            }
            if (v_count == n_adj) {
                info.colors[i] = B;
            }
        }
        printf("i");
        distance++;
    }

    for (int i=0; i<n_vertices; i++) {
        arv_insere(caminhos, i, info.p, NULO);
    }
    return caminhos;
}

int main(int argc, char **argv) {
    int n_vertices, *adj, n_adj, j, origem;
    Lista **lst_adj;
    Arv *caminhos;

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
    printf("Escolha um vertice de origem para a busca: ");
    scanf("%d", &origem);
    caminhos = BFS(lst_adj, origem, n_vertices);
    for (int i=0; i<n_vertices; i++) {
        arv_imprime(caminhos, i);
        printf("\n");
    }

    for(j=0; j<n_vertices; j++) {
        lst_libera(lst_adj[j]);
    }
    free(lst_adj);
    free(adj);
    return SUCESSO;
}
