#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#define SUCESSO 0
#define N_SERV 10

int main(int argc, char **argv) {
    int lst_adj[N_SERV][N_SERV];
    int *vet_serv;
    
    for (int i=0; i<N_SERV; i++) {
        printf("Servidores ligados ao servidor %d: ", i);
        vet_serv = (int*) malloc(N_SERV * sizeof(int));
        for (j=0; j<n_adj; j++) {
            scanf("%d", adj[j]);
            lst_insere(lst_adj[j], adj[j]);
        }
    }
    return SUCESSO;
}