#ifndef LISTACHAR_H_INCLUDED
#define LISTACHAR_H_INCLUDED


typedef struct lista *Lista; // "Apelidando" a struct lista para Lista (sendo um ponteiro pra struct).

// Operações Basicas:
Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst, char elem[]);
int remove_elem(Lista lst,char elem[]);
int apaga_lista(Lista *end_lst);
int esvazia_lista(Lista lst);
int get_elem_pos(Lista lst, int pos, char *elem);

// Operações complementares:
int remove_todas(Lista lst, char letra);
int remove_maior(Lista lst);
int tamanho_lista(Lista x, int *tamanho);
Lista concatena_listas(Lista l1, Lista l2);
void libera(Lista x);

#endif // LISTACHAR_H_INCLUDED
