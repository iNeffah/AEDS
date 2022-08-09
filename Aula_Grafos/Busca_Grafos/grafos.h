struct lista{
    int vertice;
	struct lista *prox;
};
typedef struct lista Lista;

struct filal{
	Lista *ini;
	Lista *fim;
};
typedef struct filal FilaL;

typedef struct pilha_lst{
	Lista *prim;
} PilhaL;

FilaL *fila_cria_l();
void fila_insere_l(FilaL *f, int vert);
int fila_retira_l(FilaL *f);
int fila_vazia_l(FilaL *f);
void fila_libera_l(FilaL *f);

PilhaL *pilha_lst_cria();
void pilha_lst_push(PilhaL *p, int v);
int pilha_lst_pop(PilhaL *p);
int pilha_lst_vazia(PilhaL *p);
void pilha_lst_libera(PilhaL *p);