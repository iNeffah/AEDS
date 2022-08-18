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

struct arv{
	int info;
	struct arv *esq;
	struct arv *dir;
};
typedef struct arv Arv;

Lista* lst_cria();
Lista* lst_insere(Lista *l, int i);
int lst_vazia(Lista *l);
void lst_libera(Lista *l);

FilaL *fila_cria_l();
void fila_insere_l(FilaL *f, int vert);
int fila_retira_l(FilaL *f);
int fila_vazia_l(FilaL *f);
void fila_libera_l(FilaL *f);

Arv* arv_criavazia(void);
Arv* arv_libera(Arv* a);
int arv_vazia(Arv* a);
Arv* arv_insere(Arv *a, int i, int p, int ant);
void arv_imprime(Arv* a, int fim);
int arv_pertence(Arv* a,int v);