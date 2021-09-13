#ifndef LISTADOUBLE_H_INCLUDED
#define LISTADOUBLE_H_INCLUDED

typedef struct no * Lista; //"Apelidando" a struct lista para Lista (sendo um ponteiro pra struct).

// Operações Basicas:
Lista cria_lista();
int get_elem_pos(Lista lst, int pos);
void apaga_lista(Lista *lst);

// Operações complementares:
int remove_elemento(Lista *lst, int elem);
int remove_maior(Lista *lst, int *elem);
int insere_elemento(Lista *lst, int elem);
Lista inverte(Lista* lst);

#endif //LISTADOUBLE_H_INCLUDED
