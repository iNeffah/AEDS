#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#define SUCESSO 0
#define N_SERV 10

int main(int argc, char **argv) {
    int n_vertices[N_SERV], *adj, n_adj, j;
    Lista *lst_serv[N_SERV];
    adj = NULL;

    for (int i=0; i<n_vertices; i++) {
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
    grau_vertices_l(lst_serv, n_vertices);

    for(j=0; j<n_vertices; j++) {
        lst_libera(lst_serv[j]);
    }
    free(lst_serv);
    free(adj);
    return SUCESSO;
}
}