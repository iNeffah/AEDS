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
	char nome_f[30];
	FILE *f;
	int n, i;
	while (TRUE) {
		printf("Coloque o caminho do arquivo .txt: ");
		scanf("%s", nome_f);
		getchar();
		f = fopen(nome_f, "r");
		if (f == NULL) {
			printf ("Erro ao abrir o arquivo!\n");
			continue;
		}
		break;
	}
	while (fscanf(f, "%d", &n) != EOF) {
        if ((n < 1) || (n > 1000)) {
            printf("Numero de comandos deve ser entre 1 e 1000!\n");
            return 0;
        }
		int dado, comando;
		bool_t isPilha, isFila, isFilaP;
		fila_t* fila = fila_cria_l();
		lista_t* filaP = lst_cria();
		pilha_t* pilha = pilha_l_cria();
		isPilha = isFila = isFilaP = TRUE;

        for (i=0; i<n; i++) {
            fscanf(f, "%d %d", &comando, &dado);
            if ((dado < 0) || (dado > 100) || ((comando != 1) && (comando != 2))) {
                printf("Numeros do codigo ou dos dados invalidos! Dados devem ser de 0 a 100 e codigos 1 ou 2.\n");
                return 0;
            }
            if (comando == 1) {
                pilha_l_push(pilha, dado);
                fila_insere_l(fila, dado);
                lst_insere_ordenado(filaP, dado);
            } else {
                if (pilha->prim->info != dado) {
                    isPilha = FALSE;
                } else {pilha_l_pop(pilha);}

                if (fila->ini->info != dado) {
                    isFila = FALSE;
                } else {fila_retira_l(fila);}

                if (filaP->info != dado){
                    isFilaP = FALSE;
                } else {lst_retira(filaP, dado);}
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
        fila_libera_l(filaP);
        pilha_l_libera(pilha);
	}
    fclose(f);
    return SUCESSO;
}