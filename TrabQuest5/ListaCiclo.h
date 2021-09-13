#ifndef LISTACICLO_H_INCLUDED
#define LISTACICLO_H_INCLUDED

typedef struct no * Lista;

Lista cria_lista();
int lista_vazia (Lista lst);
int insere_inicio(Lista *lst, char elem);
char get_elem_pos(Lista lst, int pos);
void apaga_lista(Lista *lst);

#endif // LISTACICLO_H_INCLUDED
