#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

fila_t*fila_cria_l(){
	fila_t*f = (fila_t*) malloc(sizeof(fila_t));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere_l(fila_t*f,int dado){
	lista_t *n = (lista_t *) malloc(sizeof(lista_t));
	int i;
	n->info = dado;
	n->prox = NULL;
	if(f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;
}

int fila_retira_l(fila_t*f){
	lista_t *t;
	int v;
	if(fila_vazia_l(f)){
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini==NULL) f->fim = NULL;
	free(t);
	return v;
}

int fila_vazia_l(fila_t*f){
	return (f->ini == NULL);
}

void fila_libera_l(fila_t*f){
	lista_t *q = f->ini;
	while(q!=NULL){
		lista_t *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

pilha_t *pilha_l_cria(){
	pilha_t *p=(pilha_t *)malloc(sizeof(pilha_t));
	p->prim=NULL;
	return p;
}

void pilha_l_push(pilha_t *p, int dado){
	lista_t *l=(lista_t *)malloc(sizeof(lista_t));
	l->info=dado;
	l->prox=p->prim;
	p->prim=l;
}

int pilha_l_pop(pilha_t *p){
	lista_t *l;
	int n;
	if(pilha_l_vazia(p)){
		printf("Pilha vazia\n");
		exit(1);
	}
	l=p->prim;
	n = l->info;
	p->prim = l->prox;
	free(l);
	return n;
}

int pilha_l_vazia(pilha_t *p){
	return (p->prim==NULL);
}

void pilha_l_libera(pilha_t *p){
	lista_t *l=p->prim;
	while(l != NULL){
		lista_t *t = l->prox;
		free(l);
		l=t;
	}
	free(p);
}