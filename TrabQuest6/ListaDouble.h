#ifndef LISTADOUBLE_H_INCLUDED
#define LISTADOUBLE_H_INCLUDED

typedef struct no * Lista; //"Apelidando" a struct lista para Lista (sendo um ponteiro pra struct).

// Operações Basicas:
Lista cria_lista();
int lista_vazia (Lista lst);
// É necessario permitir ao usuario usar a função lista_cheia, mesmo sabendo que na teoria nao existe dinamica cheia?
//int lista_cheia(Lista *li);
int insere_elemento(Lista *lst, double elem);
int remove_elemento(Lista *lst, double elem);
int esvazia_lista(Lista *lst);
void apaga_lista(Lista *lst);
int get_elem_pos(Lista lst, int pos);

// Operações complementares:
int remove_todos(Lista *lst, double *elem);
int remove_maior(Lista *lst, double *elem);
int insere_posicao(Lista *lst, int pos, double elem);
Lista inverte(Lista* lst);
void libera(Lista x);


#endif //LISTADOUBLE_H_INCLUDED
