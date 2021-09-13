
#ifndef LISTAORDENADACAB_H_INCLUDED
#define LISTAORDENADACAB_H_INCLUDED

typedef struct no *Lista;  // "Apelidando" a struct lista para Lista (sendo um ponteiro pra struct).

// Operações Basicas:
Lista cria_lista();
int lista_vazia(Lista lst);
// É necessario permitir ao usuario usar a função lista_cheia, mesmo sabendo que na teoria nao existe dinamica cheia?
//int lista_cheia(Lista *li);
int insere_ord(Lista *lst, int elem);
int remove_ord(Lista *lst, int elem);
int esvazia_lista(Lista *lst);
void apaga_lista(Lista *lst);
int get_elem_pos(Lista *lst, int pos, float *elem);

// Operações complementares:
int tamanho_lista(Lista *lst, int *tam);
int remove_pos(Lista *lst, int pos, int *valor);
Lista inverter_lista(Lista *l1);
Lista intercala(Lista *l1,Lista *l2);
void libera(Lista x);

#endif // LISTAORDENADACAB_H_INCLUDED
