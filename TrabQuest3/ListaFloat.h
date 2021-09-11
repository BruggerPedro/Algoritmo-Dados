#ifndef LISTAFLOAT_H_INCLUDED
#define LISTAFLOAT_H_INCLUDED

typedef struct no *Lista; //sempre do tipo ponteiro ao criar TAD


Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista *li); // É necessario permitir ao usuario usar a função lista_cheia, mesmo sabendo que na teoria nao existe dinamica cheia?
int insere_elem(Lista *lst, float elem);
int remove_elem(Lista *lst, float elem);
int esvazia_lista(Lista *lst);
void apaga_lista(Lista *lst);
int get_elem_pos(Lista *lst, int pos, float *elem);

int tamanho_lista(Lista *lst, int *tam);
int remove_menor(Lista *lst, float *menor);
int listas_iguais(Lista *l1, Lista *l2);
Lista intercala_listas(Lista *l1, Lista *l2);

void libera(Lista x);

#endif // LISTAFLOAT_H_INCLUDED
