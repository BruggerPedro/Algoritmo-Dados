#ifndef LISTACHAR_H_INCLUDED
#define LISTACHAR_H_INCLUDED


typedef struct lista *Lista; //sempre do tipo ponteiro ao criar TAD


Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst, char elem[]);
int remove_elem(Lista lst,char elem[]);
int esvazia_lista(Lista lst);
int apaga_lista(Lista *end_lst);
int get_elem_pos(Lista lst, int pos, char *elem[]);


int tamanho_lista(Lista x, int *tamanho);
Lista intercala_listas(Lista l1, Lista l2);
void libera(Lista x);

#endif // LISTACHAR_H_INCLUDED
