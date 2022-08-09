#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

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

// Funções de pilha para Busca em Profundidade
PilhaL *pilha_lst_cria(){
	PilhaL *p=(PilhaL *)malloc(sizeof(PilhaL));
	p->prim=NULL;
	return p;
}

void pilha_lst_push(PilhaL *p, int v){
	Lista *l=(Lista *)malloc(sizeof(Lista));
	l->vertice=v;
	l->prox=p->prim;
	p->prim=l;
}

int pilha_lst_pop(PilhaL *p){
	Lista *l;
	int v;
	if(pilha_lst_vazia(p)){
		printf("Pilha vazia\n");
		exit(1);
	}
	l=p->prim;
	v = l->vertice;
	p->prim = l->prox;
	free(l);
	return v;
}

int pilha_lst_vazia(PilhaL *p){
	return (p->prim==NULL);
}

void pilha_lst_libera(PilhaL *p){
	Lista *l=p->prim;
	while(l != NULL){
		Lista *t = l->prox;
		free(l);
		l=t;
	}
	free(p);
}
