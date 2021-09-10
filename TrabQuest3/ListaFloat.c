#include <stddef.h>
#include "ListaFloat.h"
/*
Implementar o TAD lista não ordenada de números reais (float) usando alocação
dinâmica/encadeada SEM cabeçalho. Além das operações vistas em sala, o TAD também
deve contemplar:
 Tamanho: retorna o número de elementos da lista.
 Remover menor: remove e retorna o menor número da lista. No caso de empate, deve-se
remover a última ocorrência encontrada.
 Iguais: recebe duas listas ordenadas e verifica se elas são iguais.
 Intercalar: recebe duas listas ordenadas e retorna uma nova lista com os elementos das
duas listas de entrada intercalados. As listas originais não devem ser alteradas.
*/
struct no{
	float info; //Número
	struct no *prox;
};
/* BASICAS                    *         PEDIDAS NO EXERCICIO
1 - cria_lista OK             *         1 - tamanho OK
2- lista_vazia OK             *         2 - remover menor EM ANDAMENTO
3- lista_cheia OK             *         3 - iguais
4- insere OK                  *         4 - intercalar
5- remove OK                  *
6- esvazia OK                 *
7- apaga_lista OK             *
8- get_elem_pos               */
Lista cria_lista(){
return NULL; //Cria uma lista e retorna o endereço de uma lista apontando pra NULL
}
int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1; //Lista vazia
    else
        return 0; //Lista aponta pra algo, logo, não é vazia
}

int lista_cheia(Lista li){

    return 0;

}
// lista_cheia (Na teoria, não existe como "encher" uma lista dinamica, [exceto pela limitação de espaço na memoria])
int insere_elem(Lista *lst, float elem){
    // Aloca um novo nó
    Lista N = (Lista) malloc(sizeof(struct no)); // N aloca um novo campo de lista
    if (N == NULL){ return 0;} //Falha: Não conseguiu alocar o Nó
    N->info = elem; //Insere o conteudo (valor de elem)
    N->prox = *lst; //Aponta para o 1° nó atual da lista
    *lst = N;       // Faz a lista apontar para o novo nó
    return 1;       // Inserido
}
int remove_elem(Lista *lst, float elem){
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

int esvazia_lista(Lista *lst){

    if(lst == NULL) {
      return 0;
      }

    Lista aux = *lst;

    while(*lst != NULL){
        (*lst) = (*lst)->prox;
        free(aux);
        aux = *lst;
    }
    free(aux);

    return 1;

}

int tamanho_lista(Lista *lst, int *tam){

    if(lst == NULL) {
        return 0;
        }

    int contador = 0;
    if(lista_vazia(*lst) == 1){
        *tam = contador;

        return 1;
    }
    Lista aux = *lst;
    while(aux->prox != NULL){
        contador++;
        aux = aux->prox;
    }

    *tam = contador + 1;

    return 1;

}


void apaga_lista(Lista *lst){

    if(lst != NULL){

        Lista aux = *lst;

        while(*lst != NULL){
            (*lst) = (*lst)->prox;
            free(aux);
            aux = *lst;
        }
        free(aux);
        free(lst);
    }
}

/*
int remove_menor(Lista *lst, float *menor){

    if(lst == NULL || lista_vazia(*lst) == 1) return 0;

    *menor = (*lst)->info;
    if((*lst)->prox == NULL){// Se a lista tiver apenas um elemento
        return 1;
    }
    Lista aux = *lst;
    while(aux->prox != NULL){
        if(aux->info < (*menor)) *menor = aux->info;
        aux = aux->prox;
    }

    if(aux->info < (*menor)) *menor = aux->info;//VERIFICANDO A ULTIMA POSICAO

    return 1;
 // tá incompleto, tô apenas dizendo qual é o menor mas preciso remover ele
}
*/
