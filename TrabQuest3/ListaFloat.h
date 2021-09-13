#ifndef LISTAFLOAT_H_INCLUDED
#define LISTAFLOAT_H_INCLUDED

typedef struct no *Lista;  // "Apelidando" a struct lista para Lista (sendo um ponteiro pra struct).

// Operações Basicas:
Lista cria_lista();
int lista_vazia(Lista lst);
// É necessario permitir ao usuario usar a função lista_cheia, mesmo sabendo que na teoria nao existe dinamica cheia?
//int lista_cheia(Lista *li);
int insere_elem(Lista *lst, float elem);
int remove_elem(Lista *lst, float elem);
void apaga_lista(Lista *lst);
int esvazia_lista(Lista *lst);
int get_elem_pos(Lista lst, int pos, float *elem);


// Operações complementares:
int tamanho_lista(Lista *lst, int *tam);
int remove_menor(Lista *lst, float *menor);
int listas_iguais(Lista *l1, Lista *l2);
Lista intercala_listas(Lista *l1, Lista *l2);
void libera(Lista x);

#endif // LISTAFLOAT_H_INCLUDED
