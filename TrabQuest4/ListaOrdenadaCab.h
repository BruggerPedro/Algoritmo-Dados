#ifndef LISTAORDENADACAB_H_INCLUDED
#define LISTAORDENADACAB_H_INCLUDED

typedef struct no *Lista; //sempre do tipo ponteiro ao criar TAD

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista *li); // É necessario permitir ao usuario usar a função lista_cheia, mesmo sabendo que na teoria nao existe dinamica cheia?
int insere_ord(Lista *lst, int elem);
int remove_ord(Lista *lst, int elem);
int esvazia_lista(Lista *lst);
void apaga_lista(Lista *lst);
int get_elem_pos(Lista *lst, int pos, float *elem);


int tamanho_lista(Lista *lst, int *tam);
int remove_pos(Lista *lst, int pos, int *valor);
Lista inverter_lista(Lista *l1);
Lista intercala(Lista *l1,Lista *l2);


void libera(Lista x);

#endif // LISTAORDENADACAB_H_INCLUDED
