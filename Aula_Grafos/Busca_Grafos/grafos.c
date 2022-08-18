#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

// Funcoes de lista
Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista *l, int i){
	Lista *novo=(Lista *)malloc(sizeof(Lista));
	novo->vertice=i;
	novo->prox=l;
	return novo;
}

int lst_vazia(Lista *l){
	if(l==NULL)
		return 1;

	else
		return 0;
}

void lst_libera(Lista *l){
	Lista *p=l;
	while(p!=NULL){
		Lista *t=p->prox;
		free(p);
		p=t;
	}
}

// Funções de Fila para Busca em Largura
FilaL *fila_cria_l(){
	FilaL *f = (FilaL *) malloc(sizeof(FilaL));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere_l(FilaL *f, int v){
	Lista *n = (Lista *) malloc(sizeof(Lista));
	n->vertice=v;
	n->prox = NULL;
	if(f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;
}

int fila_retira_l(FilaL *f){
	Lista *t;
	int v;
	if(fila_vazia_l(f)){
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->vertice;
	f->ini = t->prox;
	if(f->ini==NULL) f->fim = NULL;
	free(t);
	return v;
}

int fila_vazia_l(FilaL *f){
	return (f->ini == NULL);
}

void fila_libera_l(FilaL *f){
	Lista *q = f->ini;
	while(q!=NULL){
		Lista *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

// Funcoes de arvore para retorno da busca
Arv* arv_criavazia(){return NULL;}

Arv* arv_libera(Arv* a){
	if(!arv_libera(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
	}
	return NULL;
}

int arv_vazia(Arv* a){
	return (a == NULL);	
}

Arv* arv_insere(Arv *a, int i, int p, int ant) {
    if ((arv_vazia(a)) && (p == ant)) {
        a = (Arv*) malloc(sizeof(Arv));
        a->info = i;
        a->esq = a->dir = NULL;   
    }
    else if ((p != ant) && (arv_vazia(a))) {
		return a;
    } else {
		ant = a->info;
		if(a->esq == NULL || arv_pertence(a->esq, p))
		{
			a->esq = arv_insere(a->esq, i, p, ant);
		}
		else
		{
			a->dir = arv_insere(a->dir, i, p, ant);
		}
    } return a;
}

void arv_imprime(Arv* a, int fim){
	if((!arv_vazia(a)) && (a->info != fim)){
		printf("%d->",a->info);
		if(arv_pertence(a->esq, fim))
		{
			arv_imprime(a->esq, fim);
		}
		else
		{
			arv_imprime(a->dir, fim);
		}
	} else if (!arv_vazia(a)){
		printf("%d",a->info);
	}
}

int arv_pertence(Arv* a,int v){
	if(arv_vazia(a))	return 0;
	else return a->info == v || arv_pertence(a->esq,v) || arv_pertence(a->dir,v);
}