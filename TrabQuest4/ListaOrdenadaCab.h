#ifndef LISTAORDENADACAB_H_INCLUDED
#define LISTAORDENADACAB_H_INCLUDED

typedef struct no *Lista; //sempre do tipo ponteiro ao criar TAD

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista *li); // É necessario permitir ao usuario usar a função lista_cheia, mesmo sabendo que na teoria nao existe dinamica cheia?
int insere_elem(Lista *lst, float elem);
int remove_elem(Lista *lst, float elem);


#endif // LISTAORDENADACAB_H_INCLUDED
