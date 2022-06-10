#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "functions.h"

#define SUCESSO 0
#define TRUE 1
#define FALSE 0
typedef uint8_t bool_t;

int main(int argc, char **argv) {
    int dado, comando, n;
	FILE *f;
    bool_t isPilha, isFila, isFilaP;
	fila_t* fila = fila_cria_l();
	lista_t* filaP = lst_cria();
	pilha_t* pilha = pilha_l_cria();
	isPilha = isFila = isFilaP = TRUE;

	f = fopen("entrada.txt", "r");
	if (f == NULL) {
		printf ("Erro ao abrir o arquivo!\n");
	}

	while (!feof(f)) {
        fscanf(f, "%d", &n);
        for (int i=0; i<n; i++) {
            fscanf(f, "%d %d", &comando, &dado);
            printf("%d %d\n", comando, dado);
            if (comando == 1) {
                pilha_l_push(pilha, dado);
                fila_insere_l(fila, dado);
                lst_insere_ordenado(filaP, dado);
            } else {
                if (pilha->prim->info != dado) {
                    isPilha = FALSE;
                } else {
                    printf("a");
                    pilha_l_pop(pilha);
                }

                if (fila->ini->info != dado) {
                    isFila = FALSE;
                } else {
                    fila_retira_l(fila);
                }

                if (filaP->info != dado){
                    isFilaP = FALSE;
                } else {
                    lst_retira(filaP, dado);
                }
            }
        }

        if ((isPilha == FALSE) && (isFila == FALSE) && (isFilaP == FALSE)) {
            printf("impossible\n");
        } else if (pilha && fila) {
            printf("not sure\n");
        } else if (pilha && filaP) {
            printf("not sure\n");
        } else if (fila && filaP) {
            printf("not sure\n");
        } else if (pilha) {
            printf("stack\n");
        } else if (fila) {
            printf("queue\n");
        } else if (filaP) {
            printf("priority queue\n");
        }
        fila_libera_l(fila);
        lst_libera(filaP);
        pilha_l_libera(pilha);
	}
    fclose(f);
    return SUCESSO;
}