#include <stdio.h>
#include "ListaDouble.h"


/* BASICAS              *           PEDIDAS NO EXERCICIO
1 - cria lista   ok     *           - Remover todos ok
2-  lista vazia    ok               - Remover maior ok
3 - Lista cheia    ok                - Inserir na posição ok
4 - insere  ok          *           - Inverter OK
5 - remove ok
6 - esvazia ok
7 - apaga lista  ok
8 - get elem pos  ok    *
                        *
*/

/*lista_cheia, insere, remove, esvazia_lista, apaga_lista, get_elem_pos*/

struct no{
    double info; // Elemento
    struct no *ant;
    struct no *prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia (Lista lst) {
       if (lst == NULL)
        return 1;
       else
        return 0;
}
// _______________________________________________________________________________________________________________

/* Na teoria, não existe como "encher" uma lista dinamica, [exceto pela limitação de espaço na memoria])*/


//int lista_cheia(Lista *li){
//return 0;
//}
// _______________________________________________________________________________________________________________

int insere_elemento(Lista *lst, int elem)
{
    // Aloca um novo nó e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL)
        { return 0; }
    // Falha: nó não alocado
    N->info = elem; // Insere o conteúdo (valor do elem)
    N->ant = NULL; // Não tem antecessor do novo nó
    N->prox = *lst; // Sucessor do novo nó recebe mesmo end. da lista
    if (lista_vazia(*lst) == 0) // Se lista NÃO vazia
    (*lst)->ant = N; // Faz o antecessor do 1o nó ser o novo nó
    *lst = N; // Faz a lista apontar para o novo nó
    return 1;
}

int remove_elemento(Lista *lst, int elem)
{
    if (lista_vazia(*lst)==1) // Trata lista vazia
            return 0;
    Lista aux = *lst; // Faz aux apontar para 1o nó
    while (aux->prox != NULL && aux->info != elem)
            aux = aux->prox;
    if (aux->info != elem)
        return 0; // Elemento não está na lista

    if (aux->prox != NULL) // Se o proximo elemento existir
        (aux)->prox->ant = aux->ant;  // ant do proximo recebe o ant do aux

    if (aux->ant != NULL) // Se o elemento anterior existir
        (aux)->ant->prox = aux->prox; // proximo do anterior recebe o prox do aux

    if (aux == *lst) *lst = aux->prox;
    free(aux);
    return 1;
}

void apaga_lista(Lista *lst)
{
    Lista aux = *lst;
    while ((*lst)->prox != NULL)//ENQUANTO o próximo elemento não for  último
        {
            (*lst) = (*lst)->prox; //Percorre a lista
            free(aux);//Aumenta o contador
            aux = *lst;
        }
        free(*lst);
        lst=NULL;
}

int esvazia_lista(Lista *lst){

    if(lst == NULL) { // Se o ponteiro estiver apontando NULL, a lista está vazia
      return 0;
      }

    Lista aux = *lst; //Ponteiro auxiliar aponta para o começo da lista
    Lista aux2 = NULL;


    if( ((*lst)->prox == NULL) && (*lst)->ant == NULL){ // Verifica se é nó unico
      (*lst) = NULL;
      free(aux);
      return 1; // Sucesso
    }

    while(aux->prox != NULL){
    aux2 = aux->prox;
    free(aux);
    aux = aux2;
    }

    // Aux está no ultimo nó
    (*lst) = NULL;
      free(aux);

    return 1; // Sucesso

}

int get_elem_pos(Lista lst, int pos)
{
    if (lst == NULL)
        return 0;
    else
    {
        Lista aux = lst;
        for(int i = 1; i<pos; i++)
            {
                if(aux->prox != NULL)
                    aux=aux->prox;
                else
                    return 0;
            }
        return aux->info;
    }
}

// Remover todos
int remove_todos(Lista *lst, double *elem){

if(lst == NULL) { // Se o ponteiro estiver apontando NULL, a lista está vazia
      return 0;
}


Lista aux = *lst;

// Nó unico
if( ((*lst)->prox == NULL) && (*lst)->ant == NULL){ // Verifica se é nó unico

if(aux->info == elem){ // Elemento passado é exatamente o presente no nó
   remove_elemento(*lst,elem);
}else{ // Se o elemento for diferente
 return 1;
}
}

do{

  if(aux->info != elem){ // Verificação, se a info do aux é diferente
  aux = aux->prox; //Movimentar o aux
}

// Achou um nó com o elemento
remove_elemento(*lst,elem);
aux = aux->prox;

}while (aux->prox != NULL) // Repete até entrar no ultimo nó

// Ultimo nó
if(aux->info == elem){ // Elemento passado é exatamente o presente no nó
   remove_elemento(*lst,elem);
   return 1;
}else{ // Se o elemento for diferente
 return 1;
}


int remove_maior(Lista *lst, double *elem){

    if(lst == NULL || lista_vazia(*lst)== 1){
        return 0;
    }

    Lista maior = NULL;

    if ((*lst)->prox == NULL) // Verifica se existe apenas um nó
    {
        free(*lst);
        return 1;
    }

    // +1 no

    maior = *lst;
    Lista aux = (*lst)->prox; //aux está a frente do ponteiro "maior"


    while (aux->prox != NULL)
    {
        if(aux->info>maior->info)
            maior = aux;
        aux=aux->prox;
    }

    if(aux->info > maior->info)
            maior = aux;
    if (maior->prox != NULL)
        (maior)->prox->ant = maior->ant;
    if (maior->ant != NULL)
        (maior)->ant->prox = maior->prox;
    if (maior == *lst) *lst = maior->prox;

    // Chegando aqui, temos o maior no (Ponteiro maior)
    *elem = maior->info;

    free(maior);
    return 1;
}

int insere_posicao(Lista *lst, int pos, char elem){

    if(lst == NULL){
    return 0;
    }

   // Inserir na lista vazia
    if (lista_vazia(*lst) == 1){   // Se a lista estiver vazia
    return 0; // Quer inserir na posição de uma lista vazia
    }

   Lista aux = *lst;

   // Inserir na lista com apenas 1 nó
   if(aux->prox == NULL && aux->ant == NULL){
    if(pos == 1){
           insere_elemento(*lst,elem);
        }else{
         return 0; // Falha
        }
   }

   int tam = 1; // Recebe a quantidade de nós da lista

   while(aux->prox != NULL){
    tam++;
   }
   //Temos a quantidade de nós da lista

   if(pos > tam){
    return 0; //Quer inserir em uma posição que nao existe
   }

   int cont = 1;
   aux = aux->prox;

   while(cont<pos){
    cont++;
    aux = aux->prox;
   }

   // Aux aponta para o nó a ser "Substituido"
   aux->info = elem;
   return 1;
}


Lista inverte(Lista* lst){
    if(lst == NULL || lista_vazia(*lst)== 1){
        return 0;
    }

    Lista *l2;
     Lista aux = *lst;
         // Se tiver um nó
    if(aux->prox == NULL && aux->ant == NULL){ //Verificação se possui apenas um nó
    insere_elemento(*l2,aux->info);
    return l2;
    }

    // Temos +1 nó


    while(aux->prox != NULL){
        insere_elemento(*l2,aux->info);
        aux = aux->prox;
    }

    // Aux está na ultima posição
    insere_elemento(*l2,aux->info);
    return l2;

}
