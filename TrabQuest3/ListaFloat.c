#include <stddef.h>
#include "ListaFloat.h>

struct no{
	float info; //Número
	struct no *prox;
};

/* BASICAS
1 - cria_lista
2- lista_vazia
3- lista_cheia
4- insere
5- remove
6- esvazia
7- apaga_lista
8- get_elem_pos */

Lista cria_lista(){
return NULL; //Cria uma lista e retorna o endereço de uma lista apontando pra NULL
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1; //Lista vazia
    else
        return 0; //Lista aponta pra algo, logo, não é vazia
}

// lista_cheia (Na teoria, não existe como "encher" uma lista dinamica, [exceto pela limitação de espaço na memoria])

int insere_elem(Lista *lst, int elem){
    // Aloca um novo nó
    Lista N = (Lista) malloc(sizeof(struct no)); // N aloca um novo campo de lista

    if (N == NULL){ return 0;} //Falha: Não conseguiu alocar o Nó

    N->info = elem; //Insere o conteudo (valor de elem)
    N->prox = *lst; //Aponta para o 1° nó atual da lista
    *lst = N;       // Faz a lista apontar para o novo nó
    return 1;       // Inserido
}

int remove_elem(Lista *lst, int elem){
    if(lista_vazia(lst) == 1) //Se lista estiver vazia
        return 0; //Falha

    Lista aux = *lst; //Ponteiro auxiliar para o 1° nó

    // Trata elemento = primeiro Nó da lista

    if(elem == (*lst)->info){
        *lst = aux->prox; //Lista aponta para o segundo nó
        free(aux); // libera memória alocada
        return 1; //  Sucesso
    }

    // Percorrimento até achar o elem ou final da lista

    while(aux->prox != NULL && aux->prox->info != elem) //Enquanto existir proximo E info do proximo for diferente do elemento
        aux = aux->prox; // seguimos apontando ao proximo da lista

    if(aux->prox == NULL) //Trata final da lista
        return 0; //Falha

    //Remove elemento != do 1° nó da lista

    Lista aux2 = aux -> prox; // Aponta nó a ser removido
    aux->prox = aux2->prox; // retira nó da lista
    free(aux2); //Libera memória alocada
    return 1;
}
