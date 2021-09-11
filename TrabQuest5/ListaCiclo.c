#include <stdio.h>
#include "ListaCiclo.h"

/* BASICAS            *           PEDIDAS NO EXERCICIO
1 - cria lista OK     *           - Inserir no inicio OK
2-  lista vazia OK    *           - Inserir na posiçao
3-  get elem pos OK   *           - Remover no fim
4-  apaga lista OK    *           - Remover vogais
5-                    *
6-                    *
7-                    *
8-                    */

struct no
{
    char info;
    struct no * prox;
};

Lista cria_lista() {
    return NULL;
}

int lista_vazia (Lista lst) {
    if (lst == NULL)  {
        return 1;
    }
    else {
         return 0;
    }
}

int insere_inicio(Lista *lst, char elem)
{
    Lista N = (Lista) malloc(sizeof(struct no));

    if (N == NULL) {
            return 0;
    }
    N->info = elem; // Insere o conteúdo (valor do elem)
    if (lista_vazia(*lst) == 1)
    {
        N->prox = N; // Faz o novo nó apontar para ele mesmo
        *lst = N; // Faz a lista apontar para o novo nó, que é o primeiro
    }
    else
    {
        N->prox = (*lst)->prox; // Faz o novo nó apontar para o antigo nó
        (*lst)->prox= N; // Faz o último nó apontar para o novo nó
    }
    return 1;
}

char get_elem_pos(Lista lst, int pos)
{
    if (lst == NULL)
        return 0;
    else
    {
        Lista aux = lst->prox;
        for(int i = 1; i<pos; i++)
            {
                if(aux->prox != lst || i==pos-1)
                    aux=aux->prox;
                else
                    return 0;
            }
        return aux->info;
    }
}

void apaga_lista(Lista *lst)
{
    Lista aux = *lst;
    while ((*lst)->prox != *lst)//enquanto o próximo elemento não for  último
        {
            (*lst) = (*lst)->prox; //Para percorrer a lista
            free(aux);
            aux = *lst;
        }
        free(*lst);
        lst=NULL;
}
