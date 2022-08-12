#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

// Cores branco cinza e preto do vertice são definidos como 0 1 e 2
#define W    0
#define G    1
#define B    2
#define TRUE 1

typedef struct info_BL {
    int *d; // distancias
    int *p; // predecessores
    int *colors; // cores
    FilaL *queue; // Fila para adjacentes
} Info_BL;

void BFS(Lista **grafo, int origem, int n_vertices) {
    Info_BL info;
    Lista *aux, *predec; // Lista p para salvar os precessores
    int distance = 0; // para calculo da distância: numero de repetições do while = d

    info.d = (int *) malloc(n_vertices * sizeof(int));
    info.p = (int *) malloc(n_vertices * sizeof(int));
    info.colors = (int *) calloc(n_vertices, sizeof(int)); // calloc para setar todos os vertices de branco
    info.queue = fila_cria_l();

    // Pegar origem -> colorir de cinza -> colocar adjascentes no queue -> antecessor = null -> distancia = 0
    fila_insere_l(info.queue, origem);
    
    while (TRUE) {
        for (aux = info.queue->ini; aux != NULL; aux = aux->prox) { // Setar os elementos da fila de cinza + colocar distancia
            info.colors[aux->vertice] = G;
            info.d[aux->vertice] = distance;
            if (distance == 0) {
                info.p[aux->vertice] = NULL;
            } else {

            }
        }

    }
}