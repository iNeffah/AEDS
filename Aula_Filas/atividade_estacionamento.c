#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "fila.h"

#define SUCESSO 0
#define TRUE 1

void retira_carro(FilaL *fila, char *placa) {
    Lista *aux;
    char *placa_aux;
    int i = 0;

    if (fila_vazia_l(fila)) {
        (void)printf("fila vazia!\n");
    } else {
        for (aux = fila->ini; aux != NULL && i != 1; aux = aux->prox) {
            if (strcmp(aux->info, placa) != 0) {
                placa_aux = fila_retira_l(fila);
                printf("%s", placa_aux);
                fila_insere_l(fila, placa_aux);
            } else if (strcmp(aux->info, placa) == 0) {
                (void)fila_retira_l(fila);
                i++;
            }
        }
        if (i = 0) {
            printf("Placa invalida.\n");
        }
    }
}


int main (int argc, char ** argv) {
    int op;
    FilaL *carros = fila_cria_l();
    char placa[20];


    while (TRUE) {
        printf("\nBem vindo ao estacionamento. Escolha uma opcao:\n"\
           "- Inserir carro                       (1)\n"\
           "- Retirar carro                       (2)\n"
           "- Imprimir estado do estacionamento   (3)\n"\
           "- Sair                                (4)\n");
        scanf("%d", &op);
        getchar();

        switch (op){
        case 1:
            printf("Insira os numeros da placa do carro. Ex.: 2345\n");
            scanf("%[^\n]s", &placa);
            fila_insere_l(carros, placa);
            break;

        case 2:
            printf("Insira a placa do carro a ser retirado. Ex.: 2345\n");
            scanf("%[^\n]s", &placa);
            retira_carro(carros, placa);
            break;
        
        case 3:
            fila_imprime_l(carros);
            break;

        case 4:
            return SUCESSO;

        default:
        printf("Insira uma opcao valida.\n");
            break;
        }
    }
}