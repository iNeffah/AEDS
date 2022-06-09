typedef struct lista{
	int info;
	struct lista *prox;
} lista_t;

typedef struct fila{
    lista_t *ini;
    lista_t *fim;
} fila_t;

typedef struct pilha{
    lista_t *prim;
} pilha_t;

fila_t *fila_cria_l();
void fila_insere_l(fila_t *f, int dado);
int fila_retira_l(fila_t *f);
int fila_vazia_l(fila_t *f);
void fila_libera_l(fila_t *f);

pilha_t *pilha_l_cria();
void pilha_l_push(pilha_t *p, int dado);
int pilha_l_pop(pilha_t *p);
int pilha_l_vazia(pilha_t *p);
void pilha_l_libera(pilha_t *p);