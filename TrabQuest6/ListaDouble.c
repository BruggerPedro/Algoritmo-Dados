#include <stddef.h>
#include <stdlib.h>
#include "ListaDouble.h"


struct no{
    double info; // Elemento a ser inserido
    struct no *ant; // Por ser dinamico, agora temos um ponteiro que "aponta" ao nó anterior
    struct no *prox; // Por ser dinamico, agora temos um ponteiro que "aponta" ao proximo nó
};

//_______________________________________________________________________________________________________________

/*
Operação: cria_lista
- Entrada: Sem entrada.
  Pré-Condição: Sem pré-condições.
- Processo: Cria uma lista e retorna o endereço de uma lista apontando pra NULL.
- Saída: NULL
- Pós-condição: Sem pós-condição.
*/

Lista cria_lista(){
    return NULL;
}

// _______________________________________________________________________________________________________________

/*
Operação: lista_vazia;
- Entrada: Endereço de uma lista.
- Pré-Condição: Sem pré-condições.
- Processo: Verifica se a lista está vazia.
- Saída: 0 (Lista não está vazia), 1 (Lista vazia)
- Pós-condição: Sem pós-condição.
*/


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

// _______________________________________________________________________________________________________________

/*
Operação: insere_elem;
- Entrada: Endereço do endereço de uma lista e o elemento (double) a ser inserido.
- Pré-Condição: Lista existir (Endereço ser valido) e elemento ser um double.
- Processo: Insere (de forma não ordenada) o elemento na lista fornecida.
- Saída: 0 (Lista não existe), 1 (Elemento inserido com sucesso).
- Pós-condição: O elemento foi inserido na lista de forma não ordenada.
*/

int insere_elemento(Lista *lst, double elem)
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

/*
Operação: remove_elem;
- Entrada: Endereço do endereço de uma lista e o elemento (double) a ser removido.
- Pré-Condição: Lista existir (Endereço ser valido) e elemento ser um double.
- Processo: Remove o elemento na lista fornecida.
- Saída: 0 (Lista vazia ou elemento não presente na lista), 1 (Elemento removido com sucesso).
- Pós-condição: O elemento foi removido na lista.
*/
int remove_elemento(Lista *lst, double elem)
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

// _______________________________________________________________________________________________________________

/*
Operação: apaga_lista
- Entrada: Endereço do endereço de uma lista
- Pré-Condição: endereço ser válido (primeiro endereço “ponteiro de ponteiro”)
- Processo: liberar a instancia da lista e apagar o seu endereço
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: instancia da lista liberada.
*/

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

// _______________________________________________________________________________________________________________

/*
Operação: esvazia_lista
- Entrada: Endereço do endereço de uma lista
- Pré-Condição: Lista existir (Endereço ser valido)
- Processo: Esvaziar a lista.
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: a instancia da lista no estado de vazia
*/

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

// _______________________________________________________________________________________________________________

/*
Operação: get_elem_pos
- Entrada: Endereço de uma lista, posição a obter o elemento e uma variavel para receber a informação da dita posição.
-  Pré-Condição: Lista existir (Endereço ser valido), a lista não estar vazia e posição ser maior que 0.
- Processo: Através da posição fornecida, busca-se na lista o elemento correspondente aquela posição e o retorna atraves da variavel fornecida.
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: A variavel recebe o valor do elemento presente na posição fornecida.
*/

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


// _______________________________________________________________________________________________________________

// Operações especiais:
// _______________________________________________________________________________________________________________


// _______________________________________________________________________________________________________________


// _______________________________________________________________________________________________________________



// _______________________________________________________________________________________________________________


/*
Operação: remove_todos;
- Entrada: Endereço do endereço de uma lista e o elemento (double) a ser removido.
- Pré-Condição: Lista existir (Endereço ser valido) e elemento ser um double.
- Processo: Remove todas as ocorrencias do elemento na lista.
- Saída: 0 (Lista vazia), 1 (Elemento removido com sucesso).
- Pós-condição: O elemento foi removido na lista.
*/

int remove_todos(Lista *lst, double *elem){

if(lst == NULL) { // Se o ponteiro estiver apontando NULL, a lista está vazia
      return 0;
}


Lista aux = *lst;

// Nó unico
if( ((*lst)->prox == NULL) && (*lst)->ant == NULL){ // Verifica se é nó unico

if(aux->info == *elem){ // Elemento passado é exatamente o presente no nó
  remove_elemento(&lst,*elem);
}else{ // Se o elemento for diferente
 return 1;
}
}

do{

  if(aux->info != *elem){ // Verificação, se a info do aux é diferente
  aux = aux->prox; //Movimentar o aux
}

// Achou um nó com o elemento
remove_elemento(&lst,*elem);
aux = aux->prox;

}while (aux->prox != NULL); // Repete até entrar no ultimo nó

// Ultimo nó
if(aux->info == *elem){ // Elemento passado é exatamente o presente no nó
   remove_elemento(&lst,*elem);
   return 1;
}else{ // Se o elemento for diferente
 return 1;
}
}
// _______________________________________________________________________________________________________________


// _______________________________________________________________________________________________________________


/*
Operação: remove_todos;
- Entrada: Endereço do endereço de uma lista e o elemento (double) a ser removido.
- Pré-Condição: Lista existir (Endereço ser valido) e elemento ser um double.
- Processo: Remove o maior elemento da lista.
- Saída: 0 (Lista vazia), 1 (Elemento removido com sucesso).
- Pós-condição: O elemento foi removido na lista.
*/


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

// _______________________________________________________________________________________________________________

/*
Operação: insere_posicao;
- Entrada: Endereço do endereço de uma lista, a posicao, e o elemento (double) a ser inserido.
- Pré-Condição: Lista existir (Endereço ser valido), ter a posição na lista  e elemento ser um float.
- Processo: Insere na posição fornecida o elemento na lista.
- Saída: 0 (Lista não existe ou lista vazia), 1 (Elemento inserido com sucesso).
- Pós-condição: O elemento foi inserido na lista na posição fornecida.
*/

int insere_posicao(Lista *lst, int pos, double elem){

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

// _______________________________________________________________________________________________________________

/*
Operação: inverte;
- Entrada: Endereço do endereço de uma lista.
- Pré-Condição: Lista existir (Endereço ser valido).
- Processo: Recebe uma lista L e retorna uma nova lista L2, formada pelos elementos de L na
ordem inversa.
- Saída:  NULL(Caso a listas fornecida não existe) ou ponteiro que referencia o local onde foi criada a lista.
- Pós-condição: Sem pós-condição.
*/

Lista inverte(Lista* lst){
    if(lst == NULL || lista_vazia(*lst)== 1){
        return NULL;
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

// _______________________________________________________________________________________________________________

/*
Operação: libera
- Entrada: Endereço de uma lista
- Pré-Condição: Lista existir (Endereço ser valido)
- Processo: Retira a alocação (Libera) de uma determinada lista.
- Saída: Sem saida (VOID).
- Pós-condição: A lista foi “liberada” da memoria.
*/

void libera(Lista x){

    if(x != NULL){
        free(x);
        x = NULL;
    }
}

// _______________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________

int tamanho_lista(Lista *lst, int *tam){
if (lista_vazia(*lst) == 1){   // Se a lista estiver vazia
 tam = 0;
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

tam = tamanho;
return 1;
}
