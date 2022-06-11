// Prova Trimestral 1      Joao Pedro Neffa e Leandro Rodrigues Marques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "functions.h"

#define SUCESSO 0
#define TRUE 1
#define FALSE 0
typedef uint8_t bool_t; // Usado uint8_t como tipo bool pois gasta menos espaco q um int normal

int main(int argc, char **argv) {
    int dado, comando, n;
	FILE *f;
    bool_t isPilha, isFila, isFilaP; // variaveis que assumem valor 0 se nao for a estrutura e 1 se forem
	fila_t* fila = fila_cria_l();
	lista_t* filaP = lst_cria();
	pilha_t* pilha = pilha_l_cria();

	f = fopen("entrada.txt", "r");
	if (f == NULL) {
		printf ("Erro ao abrir o arquivo!\n");
        return 0;
	}

	while (fscanf(f, "%d", &n) != EOF) { // enquanto o que for lido do arquivo nao for um EOF (end of file)
        isPilha = isFila = isFilaP = TRUE; // valor base das variaveis

        for (int i=0; i<n; i++) {
            fscanf(f, "%d %d", &comando, &dado);

            if (comando == 1) { // Insercao
                pilha_l_push(pilha, dado);
                fila_insere_l(fila, dado);
                filaP = lst_insere(filaP, dado);

            // Remocao: compara o dado retirado com a ordem do que deve ser retirado primeiro de uma estrutura
            // Se nao for correspondente, valor de isPilha, isFila ou isFilaP sao colocados em 0.
            } else {
                if (pilha->prim->info == dado) { // Topo deve ser retirado primeiro (LIFO)
                    (void)pilha_l_pop(pilha);
                } else {
                    isPilha = FALSE;
                }

                if (fila->ini->info == dado) { // Inicio da fila deve ser retirado primeiro (FIFO)
                    (void)fila_retira_l(fila);
                } else {
                    isFila = FALSE;
                }

                if (lst_maior_elemento(filaP) == dado){ // Maior da fila deve ser retirado primeiro
                    filaP = lst_retira(filaP, dado);
                } else {
                    isFilaP = FALSE;
                }
            }
        }

        /* Checagem das variaveis isPilha, isFila e isFilaP se sao true (1) ou false (0)
        todas tres variaveis = 0 -> impossible (nao eh nenhuma estrutura)
        duas variaveis = 1 -> not sure (podem ser duas estruturas ao mesmo tempo)
        uma variavel = 1 -> stack (pilha), queue (fila) ou priority queue (fila de prioridade)
        */
        if ((isPilha == FALSE) && (isFila == FALSE) && (isFilaP == FALSE)) {
            printf("impossible\n");
        } else if (isPilha && isFila) {
            printf("not sure\n");
        } else if (isPilha && isFilaP) {
            printf("not sure\n");
        } else if (isFila && isFilaP) {
            printf("not sure\n");
        } else if (isPilha) {
            printf("stack\n");
        } else if (isFila) {
            printf("queue\n");
        } else if (isFilaP) {
            printf("priority queue\n");
        }
        fila_libera_l(fila);
        lst_libera(filaP);
        pilha_l_libera(pilha);
	}
    fclose(f);
    return SUCESSO;
}