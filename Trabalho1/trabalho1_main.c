#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhas.h"

#define SUCESSO 0

void organiza_vagoes(int qnt_vagoes, char* lado_a, char* lado_b) {
    Pilha_lst *vagoes = pilha_lst_cria();
    char instruções[30];
    int i, j;

    for (i=0; i < qnt_vagoes; i++) {
        pilha_lst_push(vagoes, lado_a[i]);
        for (j=0; j< qnt_vagoes; j++) {
            
            if (lado_a[j] != lado_b[i]) {

            }
        }
    }


}

int main(int argc, char** argv) {







    return SUCESSO;
}