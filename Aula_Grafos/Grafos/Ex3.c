#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#define SUCESSO 0
#define N_SERV 10

void verifica_comunicacao(Lista ** servidores) {
    Lista *l2;
    int contagem = 0, *adj, j=0;
    for(int i=0; i<N_SERV; i++){
        for (l2 = servidores[i]; l2 != NULL; l2=l2->prox) {
            contagem++;
            adj[j] = l2->info;
            j++;
        }
        if (contagem < N_SERV) {
            printf("Falha de comunicação com o servidor %d", i);
        }
        j=0;
        contagem=0;
    }
}

int main(int argc, char **argv) {
    int *adj, n_adj, j;
    Lista *lst_serv[N_SERV];
    adj = NULL;

    for (int i=0; i<N_SERV; i++) {
        printf("Quantidade servidores ligados ao servidor %d: ", i);
        scanf("%d", &n_adj);
        getchar();
        lst_serv[i] = lst_cria();
        adj = (int*) realloc(adj, n_adj * sizeof(int));

        printf("Servidores adjacentes ao servidor %d: ", i);
        for (j=0; j<n_adj; j++) {
            scanf("%d", &adj[j]);
            getchar();
            lst_serv[i] = lst_insere(lst_serv[i], adj[j]);
        }
    }
    verifica_comunicacao(lst_serv);

    for(j=0; j<N_SERV; j++) {
        lst_libera(lst_serv[j]);
    }
    free(adj);
    return SUCESSO;
}