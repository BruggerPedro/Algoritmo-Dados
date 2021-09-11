#include <stddef.h>
#include<stdlib.h>
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
2- lista_vazia OK             *         2 - remover menor OK
3- lista_cheia OK             *         3 - iguais OK
4- insere OK                  *         4 - intercalar OK
5- remove OK                  *
6- esvazia OK                 *
7- apaga_lista OK             *
8- get_elem_pos   OK            */


// BASICAS:

Lista cria_lista(){
return NULL; //Cria uma lista e retorna o endereço de uma lista apontando pra NULL
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1; //Lista vazia
    else
        return 0; //Lista aponta pra algo, logo, não é vazia
}

int lista_cheia(Lista *li){
return 0;
}
// lista_cheia (Na teoria, não existe como "encher" uma lista dinamica, [exceto pela limitação de espaço na memoria])

int insere_elem(Lista *lst, float elem){
    // Aloca um novo nó
    Lista N = (Lista) malloc(sizeof(struct no)); // N aloca um novo campo de lista
    if (N == NULL) //Falha: Não conseguiu alocar o Nó
        {
            return 0;
        }
    N->info = elem; //Insere o conteudo (valor de elem)
    N->prox = *lst; //Aponta para o 1° nó atual da lista
    *lst = N;       // Faz a lista apontar para o novo nó
    return 1;       // Inserido
}

int remove_elem(Lista *lst, float elem){
    if(lista_vazia(*lst) == 1) //Se lista estiver vazia
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

    if(lst == NULL) { // Se o ponteiro estiver apontando NULL, a lista está vazia
      return 0;
      }

    Lista aux = *lst; //Ponteiro auxiliar aponta para o começo da lista

    while(*lst != NULL){ //Enquanto ponteiro for != de NULL
        (*lst) = (*lst)->prox; //Ponteiro atual recebe o proximo nó
        free(aux);  //Libera o nó atual
        aux = *lst; // aux aponta pra nó atual
    }
    free(aux); //Nessa região, lst aponta pra null, então, vamos liberar o aux

    return 1; // Sucesso

}

void apaga_lista(Lista *lst){

    if(lst != NULL){ //Se for igual a null, a lista já está excluida

        Lista aux = *lst; // Aux aponta pra inicio da lista

        while(*lst != NULL){ // Enquanto existir nó
            (*lst) = (*lst)->prox; //lst aponta para o proximo nó
            free(aux); // Liberamos o nó atual
            aux = *lst; // Aux aponta para o mesmo nó de lst
        }
        free(aux); // Liberamos o aux
        free(lst); // Liberamos o lst
        //OBS: A diferença entre apaga e esvazia está na linha acima.
        // Enquanto no esvazia "liberamos" apenas o aux, no apaga,
        // liberamos tambem o lst (responsavel por apontar a primeira posição na lista)
    }
}



int get_elem_pos(Lista lst, int pos, float *elem){

    if(lst == NULL || lista_vazia(lst) || pos < 0)
        // lst aponta pra null? OU lista é vazia? OU pos <=0 OU pos > proximo?
     return 0; // FALHA

    *elem = lst->info; // elem recebe aquela informação do nó atual
    return 1; //Sucesso
}


// INCREMENTOS EXTRAS:


int tamanho_lista(Lista *lst, int *tam){

    if(lst == NULL) {// Se o ponteiro estiver apontando NULL, a lista está vazia
      return 0;
        }

    int contador = 0; // Variavel contadora

    if(lista_vazia(*lst) == 1){ // Se lista estiver vazia
        *tam = contador; //Basta atribuir ao tam o valor que está em contador(0)
        return 1;
    }


    Lista aux = *lst; // Aux aponta pra inicio da lista

    while(aux->prox != NULL){ // Enquanto "existir" proximo
        contador++;
        aux = aux->prox;
    }

    *tam = contador + 1; //Como o aux verifica uma posição "a frente" do nó, somamos o contador com +1 (Nó atual que não possui prox nó)

    return 1;

}


int remove_menor(Lista *lst, float *menor){
    // Se lst aponta pra null OU lista vazia, retornamos 0
    if(lst == NULL || lista_vazia(*lst) == 1)
        return 0;


    *menor = (*lst)->info; // Começamos dizendo que o primeiro nó é o menor

    int operem; // receberá a resposta da operação remove_elem
    float menornum = *menor; // Variavel local que armazena o menor valor

    if((*lst)->prox == NULL){// Se a lista tiver apenas um elemento
     operem = remove_elem(lst,menornum); // Chamamos a função já criada remove_elem passando a lista e o menor valor (obtido agora pela função)
        if (operem == 0){ // Se a operação remover tiver falha
        return -1;     // Retornaremos -1 que significa, conseguimos encontrar o menor valor, MAS, não conseguimos remove-lô
        }else{
         return 1; // Retornaremos sucesso na função remove_menor
    }
    }


    // Lista com + de 1 elemento:

    Lista aux = *lst; //aux aponta pro primeiro nó

    while(aux->prox != NULL){ // Enquanto existir proximo nó

        if(aux->info < (*menor)) //Se o info do nó for menor do já armazenado na variavel menor
        *menor = aux->info; // Variavel menor é atualizada com o info do nó

        aux = aux->prox;   // Aux avança na lista
    }

    if(aux->info < (*menor)) //VERIFICANDO A ULTIMA POSICAO
    *menor = aux->info; // Variavel menor é atualizada com o info do nó



    menornum = *menor; // Variavel local que armazena o menor valor
    operem = remove_elem(lst,menornum); // Chamamos a função já criada remove_elem passando a lista e o menor valor (obtido agora pela função)



    if (operem == 0){ // Se a operação remover tiver falha
        return -1;     // Retornaremos -1 que significa, conseguimos encontrar o menor valor, MAS, não conseguimos remove-lô
    }else{
         return 1; // Retornaremos sucesso na função remove_menor
    }
}

int listas_iguais(Lista *l1, Lista *l2){

    if(l1 == NULL || l2 == NULL) {// Se o ponteiro estiver apontando NULL, uma das listas está vazia
      return -1; // Excepcionalmente, o erro de ponteiro nulo será retorno -1.
    }

    int t1,t2; //Variaveis responsaveis por armazenar o tamanho das listas.

    // Obtendo o tamanho das listas e atribuindo-as para t1 e t2
    tamanho_lista(l1,&t1);
    tamanho_lista(l2,&t2);


    // RETORNO 0 == LISTAS DIFERENTES /  RETORNO == 1 LISTAS IGUAIS

    if(t1 != t2){ // Se de cara, as listas tiverem tamanho diferentes
        return 0; // Listas diferentes
    }

    Lista aux1 = *l1; // Aux1 aponta pra inicio da lista l1
    Lista aux2 = *l2; // Aux2 aponta pra inicio da lista l2



    // Como sabemos que o tamanho das duas listas são iguais, vamos usar qualquer uma delas de parametro para o for

    while (aux1 != NULL){
     if(aux1->info != aux2->info) // Se infos forem diferentes
     {
        free(aux1); // Liberamos o aux1
        free(aux2); // Liberamos o aux2
        return 0; // Listas diferentes
     }
        aux1 = aux1->prox;   // Aux1 avança na lista
        aux2 = aux2->prox;   // Aux1 avança na lista

    }

    // Se chegou aqui, é pq as listas são iguais.
        free(aux1); // Liberamos o aux1
        free(aux2); // Liberamos o aux2
    return 1; // Listas iguais

}

// INTERCALAR: CRIA UMA TERCEIRA LISTA COM AS DUAS INTERCALADAS

Lista intercala_listas(Lista *l1, Lista *l2){

if(l1 == NULL || l2 == NULL) {// Se o ponteiro estiver apontando NULL, uma das listas está vazia
      return NULL; // Excepcionalmente, o erro de ponteiro nulo.
    }

    int t1,t2; //Variaveis responsaveis por armazenar o tamanho das listas.
    int tamt; // Variavel responsavel pela soma dos "tamanhos" das duas listas

    // Obtendo o tamanho das listas e atribuindo-as para t1 e t2
    tamanho_lista(l1,&t1);
    tamanho_lista(l2,&t2);


    tamt = t1+t2; // Soma do tamanho das duas listas

    Lista l3  = cria_lista(); // Criamos a terceira lista

    int i; // Variavel contadora do for:

    Lista aux1 = *l1; // Aux1 aponta pra inicio da lista l1

    Lista aux2 = *l2; // Aux2 aponta pra inicio da lista l2


    int info; // Responsavel por receber o valor do nó(info)


    for(i=0;i<tamt;i++){
        if(i%2 == 0 && aux1 != NULL && t1>0){ // Se i for par e Diferente de NULL:
            info = aux1->info; // Atribui pra local info, o valor presente no nó
            insere_elem(&l3,info); // Chama função insere passando a lista 3 e o valor info
            aux1 = aux1->prox;   // Aux1 avança na lista
            t1--; //Decrementa t1

        }else
        if (i%2 != 0 && aux2 != NULL && t2>0){ // Se i for impar e Diferente de NULL:
            info = aux2->info; // Atribui pra local info, o valor presente no nó
            insere_elem(&l3,info);// Chama função insere passando a lista 3 e o valor info
            aux2 = aux2->prox;   // Aux2 avança na lista
            t2--; //Decrementa t2
        }else
        if (t1>0){ // Caso o tamanho das listas sejam diferentes, esse if garante preencher os elementos sobressalentes de l1
            info = aux1->info; // Atribui pra local info, o valor presente no nó
            insere_elem(&l3,info); // Chama função insere passando a lista 3 e o valor info
            aux1 = aux1->prox;   // Aux1 avança na lista
            t1--; //Decrementa t1
        }else
        if(t2>0){ // Caso o tamanho das listas sejam diferentes, esse if garante preencher os elementos sobressalentes de l2
            info = aux2->info; // Atribui pra local info, o valor presente no nó
            insere_elem(&l3,info);// Chama função insere passando a lista 3 e o valor info
            aux2 = aux2->prox;   // Aux2 avança na lista
            t2--; //Decrementa t2
        }
    }
        free(aux1); // Liberamos o aux1
        free(aux2); // Liberamos o aux2

    return l3; // Retorna a lista criada

}

void libera(Lista x){

    if(x != NULL){
        free(x);
        x = NULL;
    }
}
