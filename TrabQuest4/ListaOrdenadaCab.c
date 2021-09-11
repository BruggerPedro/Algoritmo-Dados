#include <stddef.h>
#include "lista.h"

struct no{
int info; //Dado a guardar
struct no * prox;
};

/* BASICAS               *         PEDIDAS NO EXERCICIO
1 - cria_lista OK        *
2- lista_vazia OK        *
3- lista_cheia OK        *
4- insere OK             *
5- remove OK             *
6- esvazia                *
7- apaga_lista             *
8- get_elem_pos             */


// BASICAS:
Lista cria_lista(){
    Lista cab;
    cab = (Lista) malloc(sizeof(struct no));

    if(cab != NULL){ // Se a alocação funcionou:
     cab->prox = NULL; // "cabeça aponta pra NULL"
     cab->info = 0; //Vamos guardar o tamanho da lista
    }
    return cab; // Retorno já com a cabeça
}

int lista_vazia(Lista lst){
    if(lst->prox == NULL)
        return 1; //Lista vazia
    else
        return 0; //Lista aponta pra algo, logo, não é vazia
}

int lista_cheia(Lista *li){
return 0;
}
// lista_cheia (Na teoria, não existe como "encher" uma lista dinamica, [exceto pela limitação de espaço na memoria])


int insere_ord(Lista *lst, int elem){
    // Aloca um novo nó
    Lista N = (Lista) malloc(sizeof(struct no)); // N aloca um novo campo de lista

    if (N == NULL){ return 0;} //Falha: Não conseguiu alocar o Nó

    N->info = elem; //Insere o conteudo (valor de elem)



    // Percorrimento da lista (elem > 1° nó da lista)

    Lista aux = *lst; //Faz aux apontar para 1° nó

    while(aux->prox != NULL && aux->prox->info < elem) // Se existir proximo E Info proximo for menor que o elemento
     aux = aux->prox; //Avança

    // Insere o novo elemento na lista
    N->prox = aux->prox; // Prox do N receberá o prox de Aux
    aux->prox = N; //Prox de aux agora aponta pra N
    lst->info++; //Utiliza o info do cabeçalho pra contador e o incrementa
    return 1; //Sucesso
}

int remove_ord(Lista *lst, int elem){
    if(lista_vazia(lst) == 1) // Se lista for vazia
    return 0; //falha

    Lista aux = *lst; //Ponteiro auxiliar para o 1°  nó


    // Percorrimento até final de lista, achar elem ou nó maior
    while(aux->prox != NULL && aux->prox->info < elem) // Enquanto existir proximo E info do proximo for menor que elem
   aux = aux->prox;

    if (aux->prox == NULL || aux->prox->info > elem) // Se não existir proximo OU info do prox for MAIOR que elem
        return 0; //Falha

    // Remove elemento da lista
    Lista aux2 = aux->prox; //Aponta nó a ser removido
    aux->prox = aux2->prox; //Retira nó da lista
    free(aux2); //Libera memória alocada
    (*lst)->info--; // Decrementar a quantidade de nós.
    return 1;
}



