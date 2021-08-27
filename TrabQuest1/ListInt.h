#ifndef LISTAINT_H_INCLUDED
#define LISTAINT_H_INCLUDED


typedef struct lista *Lista; //sempre do tipo ponteiro ao criar TAD
typedef struct listaIntercala *ListaIntercala;

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst, int elem);
int remove_elem(Lista lst,int elem);
int apaga_lista(Lista *end_lst);
int esvazia_lista(Lista lst);
int get_elem_pos(Lista lst, int pos, int *elem);
int remove_negativos(Lista x);
int remove_pares(Lista x);
int tamanho_lista(Lista x, float *tamanho);


int intercala_listas(Lista l1, Lista l2);

#endif // LISTAINT_H_INCLUDED
