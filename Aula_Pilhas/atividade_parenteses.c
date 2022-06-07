#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhas.h"

#define SUCESSO 0

int verifica_parenteses(char *sequencia) {
    Pilha_lst *p = pilha_lst_cria();    // Pilha para parenteses abertos
    int i;

    for (i = 0; i < strlen(sequencia); i++) {
        if (sequencia[i] == '(') {
            pilha_lst_push(p, sequencia[i]); // quando tem um parenteses aberto empilha.
        }
        else if (sequencia[i] == ')') {
            if (pilha_lst_vazia(p)) {
                break; // se a pilha estiver vazia não tem correspondente para o parenteses fechado
            } else {
                pilha_lst_pop(p); // quando tem um parentesis fechado desempilha o ultimo parenteses aberto empilhado
            }
        }
        else {break;}
    }
    if ((pilha_lst_vazia(p)) && (sequencia[i] == '\n')){ // Se nao houver mais parentesis a serem fechados ou sem abrir...
        pilha_lst_libera(p);
        return 1; // ...retorna 1. Sequencia bem formada.
    }
    pilha_lst_libera(p);
    return 0; // se nao retorna 0. Sequencia mal formada.
}

int main(int argc, char** argv) {
    char sequencia[100];
    int bem_formada;

    printf("Digite uma sequencia de parenteses:  ");
    fgets(sequencia, 100, stdin);

    bem_formada = verifica_parenteses(sequencia);
    if (bem_formada == 1) {
        printf("Sequencia bem formada\n");
    }
    else {
        printf("Sequencia mal formada\n");
    }

    return SUCESSO;
}