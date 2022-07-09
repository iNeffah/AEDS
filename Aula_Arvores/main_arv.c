#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#define SUCESSO 0

Arv* arv_insere_ordenado(Arv *a, int i) {
    if (arv_vazia(a)) {
        a = (Arv*) malloc(sizeof(Arv));
        a->info = i;
        a->esq = a->dir = NULL;   
    }
    else if (i < a->info) {
        a->esq = arv_insere_ordenado(a->esq, i);
    } else {
        a->dir = arv_insere_ordenado(a->dir, i);
    } return a;
}

int arv_conta_folhas(Arv *a) {
    if(arv_vazia(a)) {
        return 0;
    }
    else if((a->esq == NULL) && (a->dir == NULL)) {
        return 1;
    } else {
        return arv_conta_folhas(a->esq) + arv_conta_folhas(a->dir);
    }
}

int arv_conta_nos1filho(Arv *a) {
    if(arv_vazia(a)) {
        return 0;
    }
    else if((a->esq != NULL) && (a->dir != NULL)) {
        return arv_conta_nos1filho(a->esq) + arv_conta_nos1filho(a->dir);
    } 
    else if ((a->esq == NULL) && (a->dir == NULL)) {
        return 0;
    } else {
        return arv_conta_nos1filho(a->esq) + arv_conta_nos1filho(a->dir) + 1;
    }
}

int arv_conta_nos2filho(Arv *a) {
    if(arv_vazia(a)) {
        return 0;
    }
    else if((a->esq != NULL) && (a->dir != NULL)) {
        return arv_conta_nos2filho(a->esq) + arv_conta_nos2filho(a->dir) + 1;
    } 
    else if ((a->esq == NULL) && (a->dir == NULL)) {
        return 0;
    } else {
        return arv_conta_nos2filho(a->esq) + arv_conta_nos2filho(a->dir);
    }
}

int arv_conta_num(Arv *a, int num) {
    if(arv_vazia(a)) {
        return 0;
    }
    else if(a->info == num) {
        if ((a->esq == NULL) && (a->dir == NULL)) {
            return 1;
        } else {
            return arv_conta_num(a->dir, num) + 1;
        }
    } else {
        return arv_conta_num(a->esq, num) + arv_conta_num(a->dir, num);
    }
}

void arv_histograma(Arv *a, int *vet, int tamanho_vet) {
    if (arv_vazia(a)) {
        printf("arvore vazia");
    } else {
        int contagem;
        for (int i = 0; i < tamanho_vet; i++) {

            for (int e = 0; e < tamanho_vet; e++) {

                if ((vet[i] == vet[e]) && (e < i)) {
                    break;

                } else if (e == tamanho_vet - 1){               
                    contagem = arv_conta_num(a, vet[i]);
                    printf("%d|", vet[i]);
                    for (int j = 0; j < contagem; j++) {
                        printf("*");
                    }
                    printf("\n");
                }
            }
                    
        }
    }
}

int main (int argc, char ** argv) {
    Arv *a = arv_criavazia();
    int i, j;
    
    a = arv_insere_ordenado(a, 3);
    a = arv_insere_ordenado(a, 2);
    a = arv_insere_ordenado(a, 5);
    a = arv_insere_ordenado(a, 1);
    a = arv_insere_ordenado(a, 1);

    arv_imprime_preordem(a);
    arv_imprime_simetrica(a);
    arv_imprime_posordem(a);

    printf("\nFolhas: %d\nNos com 1 filho: %d\nNos com 2 filhos: %d\n", arv_conta_folhas(a), arv_conta_nos1filho(a), arv_conta_nos2filho(a));

    int vet[5] = {3, 2, 5, 1, 1};
    arv_histograma(a, vet, sizeof(vet)/sizeof(vet[0]));

    arv_libera(a);
    return SUCESSO;
}