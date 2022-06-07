#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

#define TRUE   (1)
#define FALSE  (0)
#define SUCESSO 0

int lst_equal(Lista *l1, Lista *l2){
    Lista *p1;
    Lista *p2;

    int tam1 = 0, tam2 = 0;

    for(p1 = l1; p1 != NULL; p1=p1->prox){
        tam1++;
    }
    for (p2 = l2; p2 != NULL; p2=p2->prox){
        tam2++;
    }
    
    if(tam1 != tam2){
        return FALSE;
    } else {
        while (p1 != NULL)
        {
            if(p1->info == p2->info){
                p1 = p1->prox;
                p2 = p2->prox;
            } else {
                return FALSE;
            }
        }
        
    }
    
    return TRUE;
}

int main(int agrc, char** argv) {
    Lista* l;
    Lista* m;
    l = lst_cria();
    m = lst_cria();

    if(lst_equal(l, m)){
        (void)printf("As listas sao iguais.");
    }
    else{
        (void)printf("As listas sao diferentes.");
    }
    return SUCESSO;
}