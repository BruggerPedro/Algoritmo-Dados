#ifndef LISTACICLO_H_INCLUDED
#define LISTACICLO_H_INCLUDED

typedef struct no * Lista;

Lista cria_lista();
int lista_vazia (Lista lst);
int insere_final(Lista *lst, char elem);
int remove_inicio(Lista *lst, char *elem);
int esvazia_lista(Lista *lst);
void apaga_lista(Lista *lst);
char get_elem_pos(Lista lst, int pos);
int insere_inicio(Lista *lst, char elem);
int insere_posicao(Lista *lst,int pos, char elem);
int remover_fim(Lista *lst,char *elem);
int remove_vogais(Lista *lst);

#endif // LISTACICLO_H_INCLUDED
