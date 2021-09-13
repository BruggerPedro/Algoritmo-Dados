#ifndef LISTACICLO_H_INCLUDED
#define LISTACICLO_H_INCLUDED

typedef struct no * Lista; //"Apelidando" a struct lista para Lista (sendo um ponteiro pra struct).

// Operações Basicas:
Lista cria_lista();
int lista_vazia (Lista lst);
// É necessario permitir ao usuario usar a função lista_cheia, mesmo sabendo que na teoria nao existe dinamica cheia?
//int lista_cheia(Lista *li);
int insere_final(Lista *lst, char elem);
int remove_inicio(Lista *lst, char *elem);
int esvazia_lista(Lista *lst);
void apaga_lista(Lista *lst);
char get_elem_pos(Lista lst, int pos);

// Operações complementares:
int insere_inicio(Lista *lst, char elem);
int insere_posicao(Lista *lst,int pos, char elem);
int remover_fim(Lista *lst,char *elem);
int remove_vogais(Lista *lst);
void libera(Lista x);

#endif // LISTACICLO_H_INCLUDED
