#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

// Cores branco cinza e preto do vertice são definidos como 0 1 e 2
#define w 0
#define g 1
#define b 2

typedef struct info_BL {
    int *d; // distancias
    int *p; // predecessores
    int *colors; // cores
    FilaL *queue; // Fila para adjacentes
} Info_BL;

void BFS(Lista **grafo, int origem, int n_vertices) {
    Info_BL info;
    info.d = (int *) malloc(n_vertices * sizeof(int));
    info.p = (int *) malloc(n_vertices * sizeof(int));
    info.colors = (int *) malloc(n_vertices * sizeof(int));
    info.queue = fila_cria_l();

}