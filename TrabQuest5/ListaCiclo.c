#include <stdio.h>
#include "ListaCiclo.h"

/* BASICAS            *           PEDIDAS NO EXERCICIO
1 - cria lista OK     *           - Inserir no inicio OK
2-  lista vazia OK    *           - Inserir na posiçao OK
3-  lista_cheia OK    *           - Remover no fim OK
4-  insere_final OK   *           - Remover vogais  OK
5-  remove_inicio OK  *
6-  esvazia_lista OK  *
7- apaga lista OK     *
8- get elem pos OK    */

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

// _______________________________________________________________________________________________________________

/* Na teoria, não existe como "encher" uma lista dinamica, [exceto pela limitação de espaço na memoria])*/


//int lista_cheia(Lista *li){
//return 0;
//}
// _______________________________________________________________________________________________________________

int insere_final(Lista *lst, char elem){
// Alocar um novo nó e preencher campo info
Lista N = (Lista) malloc(sizeof(struct no));
if (N==NULL){ return 0; } //Falha na alocação do nó

N->info = elem; // Insere o conteudo

// Se lista vazia:
 if(lista_vazia(*lst) == 1){
    N->prox = N; //Faz o novo nó apontar pra ele msm
    *lst = N; //Lista apontará para o novo nó(último nó)
 }

 // Caso já exista elementos na lista:
 else{
    N->prox = (*lst)->prox; //Novo nó apontará para o primeiro nó (começo)
    (*lst)->prox = N; //Faz o ultimo nó apontar para o novo nó
    *lst = N; //Lista aponta para o novo nó (Ultima posição)
 }
 return 1;
}

int remove_inicio(Lista *lst, char *elem){

// Se lista estiver vazia:
if (lista_vazia(*lst) == 1)
    return 0; // Falha


Lista aux = (*lst)->prox; //Faz aux apontar para o 1° nó
*elem = aux->info; //Retorna valor do nó a ser removido

if(*lst == (*lst)->prox) //Se a lista tiver apenas um elemento
    *lst = NULL; //Fazemos a lista apontar pra nada (Já que excluiremos o unico nó)

else // Trata lista + de 1 elemento
    (*lst)->prox = aux -> prox; //Lista aponta para o "segundo" elemento
    free(aux); //Libera o primeiro elemento
return 1; //Sucesso


}

// Esvazia
int esvazia_lista(Lista *lst){
    if((*lst) == NULL){ // Se o ponteiro estiver apontando NULL, a lista está vazia
        return 0;
    }

    Lista aux = (*lst)->prox; // Ponteiro auxiliar aponta para o começo da lista
    Lista aux2; // Ponteiro auxiliar

    while(aux != (*lst)){ // Enquanto ponteiro for != de NULL
    aux2 = aux->prox; //Aponta ao proximo nó
    free(aux);
    aux = aux2;
    }

    // Estamos no ultimo nó (aux == lst)
    (*lst) = NULL;
    free(aux);
    free(aux2);

    return 1;
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



// EXTRAS

int insere_inicio(Lista *lst, char elem){

    Lista N = (Lista) malloc(sizeof(struct no)); // Aloca o novo nó

    if (N == NULL) //Falha na alocação do nó
    return 0;

    N->info = elem; // Insere o conteúdo (valor do elem)

    if (lista_vazia(*lst) == 1){   // Se a lista estiver vazia

        N->prox = N; // Faz o novo nó apontar para ele mesmo
        *lst = N; // Faz a lista apontar para o novo nó, que é o primeiro

    }else{ // Existe ao menos um elemento na lista:

        N->prox = (*lst)->prox; // Faz o novo nó apontar para antigo começo da lista
        (*lst)->prox = N; // Faz o último nó apontar para o novo nó
    }
    return 1;
}

int insere_posicao(Lista *lst,int pos, char elem){


if (lista_vazia(*lst) == 1){   // Se a lista estiver vazia
 return 0; // Quer inserir na posição de uma lista vazia
}

int tamanho = 0; //Contador de nós da lista.
Lista aux = (*lst)->prox; //Faz aux apontar para o 1° nó

 while(aux != (*lst)){ // Enquanto ponteiro for != de NULL
  tamanho++;
  aux = aux->prox;
}
// chegando aqui, o aux tá na ultima posição, logo, só incrementamos mais uma vez.
tamanho++;

// Temos a quantidade de nós, basta verificar.

if(pos<1 || pos > tamanho){ // Posição for menor que 1 e maior que tamanho
  return 0; //Erro!
}
// Lembrando que posição 1 = primeiro elemento. Entao posição 0 não existe!


int contador = 1; //Localizar a posição a se inserir na lista;
aux = (*lst)->prox; //Faz aux apontar para o 1° nó

while(contador<pos){    //Enquanto estivermos antes de pos
    aux = aux->prox;
    contador++;
}

// Aux aponta para o local a ser inserido.
aux->info = elem; // Atribuimos ao info o elemento desejado.

return 1; // Sucesso
}

int remover_fim(Lista *lst,char *elem){

 // Se lista estiver vazia:
  if (lista_vazia(*lst) == 1)
  return 0; // Falha


Lista aux = (*lst)->prox; //Faz aux apontar para o 1° nó

  if(*lst == (*lst)->prox){ // Apenas um nó
    elem = aux->info; //Retorna valor do nó a ser removido
    *lst = NULL; //Fazemos a lista apontar pra nada (Já que excluiremos o unico nó)
    free(aux);
    return 1;
  }

  // Existe  +1 nó:

  while(aux->prox != (*lst)){ // Enquanto for diferente da "ultima posição"
    aux = aux->prox;
  }

  // Estamos na "penultima" posição;
  aux->prox = (*lst)->prox; // Aux aponta pra onde o "ultimo" apontava
  (*lst) = aux;
  aux = aux->prox; //Avançando aux pra ultima posição.

  free(aux);

  return 1;
}

/*Remover vogais: remove todos os elementos da lista que são vogais.
*/

int remove_vogais(Lista *lst){

  // Se lista estiver vazia:
  if (lista_vazia(*lst) == 1)
  return 0; // Falha

  Lista aux = (*lst)->prox; //Faz aux apontar para o 1° nó
  Lista aux2 = NULL; // Aux2


  char letra; //Só pra armazenar temporariamente a letra.

  if(*lst == (*lst)->prox){ // Apenas um nó
    if ( (aux->info == 'A') ||  (aux->info == 'a') ||
         (aux->info == 'E') ||  (aux->info == 'e') ||
         (aux->info == 'I') ||  (aux->info == 'i') ||
         (aux->info == 'O') ||  (aux->info == 'o') ||
         (aux->info == 'U') ||  (aux->info == 'u') ){

          remove_inicio(*lst,&letra); // Sabendo que só existe um registro, podemos usar a função remove_inicio
         return 1;
         }else{
         return 1; // O char da lista não é vogal, logo, não precisa ser removido
         }
}


// Existe +1 nó:

while(aux != (*lst)){ // Enquanto for diferente da "ultima posição"

 if ( (aux->info == 'A') ||  (aux->info == 'a') ||
         (aux->info == 'E') ||  (aux->info == 'e') ||
         (aux->info == 'I') ||  (aux->info == 'i') ||
         (aux->info == 'O') ||  (aux->info == 'o') ||
         (aux->info == 'U') ||  (aux->info == 'u') ){

    if(aux == (*lst)->prox){ // Se for no primeiro elemento da lista
     remove_inicio(*lst,&letra); // Sabendo que é o primeiro nó podemos usar a função remove_inicio
     aux = aux->prox;
    }

    else{ // Não for a primeira posição

    aux2 = (*lst)->prox; // aux2 aponta ao inicio

    while(aux2->prox != aux || aux2 != aux){ // Percorre até achar a posição a ser removida
        aux2 = aux2->prox;
    }

    aux2->prox = aux->prox; // aux2 aponta pra onde aux apontava
    free(aux); //Exclui o nó
    aux = aux->prox;

    }

 }else{ // Se aux não for vogal
     aux = aux->prox;
 }

}
// Estamos na "ultima" posição;
if ( (aux->info == 'A') ||  (aux->info == 'a') ||
         (aux->info == 'E') ||  (aux->info == 'e') ||
         (aux->info == 'I') ||  (aux->info == 'i') ||
         (aux->info == 'O') ||  (aux->info == 'o') ||
         (aux->info == 'U') ||  (aux->info == 'u') ){

         remover_fim(*lst,&letra); // Sabendo que é o ultimo nó, podemos usar a função

         }
         // Caso ultimo nó não seja vogal, não mexemos nele.
         return 1;

}
