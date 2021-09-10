#ifndef LISTAFLOAT_H_INCLUDED
#define LISTAFLOAT_H_INCLUDED

typedef struct no *Lista; //sempre do tipo ponteiro ao criar TAD

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista li);
int insere_elem(Lista *lst, float elem);
int remove_elem(Lista *lst, float elem);
int esvazia_lista(Lista *lst);
int tamanho_lista(Lista *lst, int *tam);
void apaga_lista(Lista *lst);


#endif // LISTAFLOAT_H_INCLUDED
