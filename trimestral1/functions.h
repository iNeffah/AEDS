typedef struct lista{
	int dado;
	struct lista *prox;
} lista_t;

typedef struct fila{
    lista_t *primeiro;
    lista_t *ultimo;
} fila_t;

typedef struct pilha{
    lista_t *topo;
} pilha_t;

fila_t *fila_cria_l();
void fila_insere_l(fila_t *f, int dado);
char *fila_retira_l(fila_t *f);
int fila_vazia_l(fila_t *f);
void fila_libera_l(fila_t *f);

pilha_t *pilha_t_cria();
void pilha_t_push(pilha_t *p, int dado);
char pilha_t_pop(pilha_t *p);
int pilha_t_vazia(pilha_t *p);
void pilha_t_libera(pilha_t *p);