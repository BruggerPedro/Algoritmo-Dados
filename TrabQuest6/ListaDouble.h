#ifndef LISTADOUBLE_H_INCLUDED
#define LISTADOUBLE_H_INCLUDED

typedef struct no * Lista;
Lista cria_lista();
int insere_elemento(Lista *lst, int elem);
int remove_elemento(Lista *lst, int elem);
int remove_maior(Lista *lst, int *elem);
void apaga_lista(Lista *lst);
Lista inverte(Lista* lst);

#endif //LISTADOUBLE_H_INCLUDED
