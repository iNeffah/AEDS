#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

#define SUCESSO 0

int josephus_problem(int n_pessoas, int n_passos) {
    Lista *lista_josephus = lst_cria(), *tmp;
    int i, j, sobrevivente;

    for (i=1; i<=n_pessoas; i++) {
        lista_josephus = lst_insere_ordenado(lista_josephus, i);
    }

    lcirc_transforma(lista_josephus);

    for (i = n_pessoas; i > 1; i--) {
        for (j=1; j < n_passos; j++){
            lista_josephus = lista_josephus->prox;
        }
        tmp = lista_josephus->prox;
        lista_josephus->prox = lista_josephus->prox->prox;
        lista_josephus = lista_josephus->prox;
        free (tmp);
    }
    sobrevivente = lista_josephus->info;
    lcirc_libera(lista_josephus);
    return sobrevivente;
}

int main(int argc, char** argv) {
    int num_pessoas, num_passos, sobrevivente;
    printf("Insira o numero de pessoas: ");
    scanf(" %d", &num_pessoas);
    printf("Insira o numero de passos (a cada x passos uma pessoa sera morta): ");
    scanf(" %d", &num_passos);

    sobrevivente = josephus_problem(num_pessoas, num_passos);
    printf("%d sobreviveu", sobrevivente);

    return SUCESSO;
}