#include <stdlib.h>
#include "ListaChar.h"
#define MAX 10
/*Implementar o TAD lista não ordenada de strings com no máximo 10 elementos, cada um
com até 15 caracteres, usando alocação estática/sequencial. Além das operações vistas em sala,
o TAD também deve contemplar:
 Remover todas: remove todas as strings da lista que começam com um dado caractere.
 Remover maior: remove e retorna a maior string da lista. No caso de empate, deve-se
remover a primeira ocorrência encontrada.
 Tamanho: retorna o número de elementos da lista.
 Concatenar: recebe duas listas (L1 e L2) e retorna uma nova lista L3 com os elementos de
L1 seguidos dos elementos de L2. As listas originais não devem ser alteradas.
*/

struct lista {
    char no[MAX];// Nó que vai ser limitado por MAX[20] posições(definido pelo programador).
    int fim; // O fim vai indicar qual é a próxima posição disponível.
};



// Mesmo sendo Lista estática, precisamos alocar a estrutura.

Lista cria_lista() { // Alocar uma instancia da estrutura lista(malloc).

    Lista lst; // Criando um ponteiro de lista.
    lst = (Lista) malloc(sizeof (struct lista)); // Tamanho da Struct lista.

    if (lst != NULL) { // Verifica se houve alocação bem sucedida.
        lst -> fim = 0; // O fim = 0 indica que a primeira posicao livre do vetor.
    }
    return lst; // Retornamos o endereço de ponteiro(lst).
}

int lista_vazia(Lista lst) {
    if (lst == NULL) {
        return -1; // Ponteiro nao esta apontando pra lista valida/existente, entao declaramos como ERRO
    }
    if (lst->fim == 0)
        return 1; // A lista esta vazia
    else
        return 0; // Ha elementos dentro da lista, portanto nao esta vazia
}

int lista_cheia(Lista lst) {
    if (lst == NULL) {
        return -1; // Ponteiro nao esta apontando pra lista valida/existente, então declaramos como ERRO
    }
    if ((lst -> fim == MAX)) { // Fim começa com 0, entao ele eh como um contador de elementos
        return 1; // Quando fim == MAX significa que a lista esta cheia.
    } else {
        return 0; // A lista nao esta cheia.
    }

    // Pode se fazer tirando da linha 37 ate 40, apenas fazendo: return(lst->fim == MAX)
}

int insere_elem(Lista lst, char elem){ //Insere o(s) elemento(s) de forma ordenada

    if (lst == NULL || lista_cheia(lst) == 1)
    return 0; // Nao tem como inserir porque lst eh NULL OU ela esta cheia (lista_cheia) == 1)

    // Trata lista vazia ou elemento >= ultimo da lista

    if (lista_vazia(lst) == 1 || elem <= lst->no[lst->fim-1]){ // Enquanto a lista estiver vazia e o elemento inserido for menor ou igual ao já inserido antes
        lst->no[lst->fim] = elem; // Inserção no final
    }else{
        int i, aux = 0;
        while(elem <= lst->no[aux]) //Percorrendo
            aux++;
        for(i=lst->fim;i>aux;i--) //Deslocando
            lst->no[i] = lst->no[i-1];
        lst->no[aux] = elem; //Incluindo o elemento na lista
    }
    lst->fim++; //Avança o fim
    return 1; //Sucesso
}

int remove_elem(Lista lst, char elem){
    if(lst == NULL || lista_vazia(lst) == 1 || elem > lst->no[0] || elem < lst->no[lst->fim-1]){
    //Quando elem > lst->no[0], significa que se o elemento que eu quero apagar é o 9 e minha lista é composta por L = {7,5}, o 9 não existe na minha lista.
    //Quando , elem < lst->no[lst->fim-1], significa que se o elemento que eu quero apagar é o 3 e minha lista é composta por L = {7,5}, o 3 não existe na minha lista.
        return 0; //Falha
        }
        int i, aux = 0;

    // Percorre até ACHAR O ELEM OU NÓ MAIOR, ou final da lista

    while(aux < lst->fim && lst->no[aux] > elem)
    // Percorre com o aux enquanto o elemento que está no auxiliar for maior que o elemento digitado
        aux++;

//       7        5       3
//      aux

    if(aux == lst->fim || lst->no[aux] < elem)
    // Elemento não vai existir quando o aux estiver no fim, e quando o elemento inserido for maior que o que está no auxiliar
        return 0;

    // Deslocamento a esq. do sucessor até o final da lista
    for(i=aux+1; i<lst->fim;i++){
        lst->no[i-1] = lst->no[i];
    }
        lst->fim--; // Decremento
        return 1; // Sucesso
}


int apaga_lista(Lista *end_lst){
    if(end_lst == NULL) //Se o ponteiro não aponta pra lista
        return 0;

    free(*end_lst); // Limpa a região da lista (liberando a memoria para o computador)
    *end_lst = NULL; // apontar pra NULL para não conseguirem acessar aquela area novamente

    return 1;
}

int esvazia_lista(Lista lst){
     if(lst == NULL ){
        return 0;
     }
    lst->fim = 0;
    return 1;
}

int get_elem_pos(Lista lst, int pos, char *elem){
        // pos = Posição do elemento na lista (começa com 1)
    if(lst == NULL || lista_vazia(lst) || pos >= lst->fim)
        return 0; // FALHA

    *elem = lst->no[pos-1]; // subtração pq temos que passar o indice real da lista
    return 1; //Sucesso

}
int tamanho_lista(Lista x, int *tamanho){

    if(x == NULL)
    return 0;

    *tamanho = x->fim; // Recebe o ponteiro tamanho do tipo float e vai retornar o tamanho da lista(qtde de elem)

    return 1;

}

Lista intercala_listas(Lista l1, Lista l2){

    if(l1 == NULL || l2 == NULL)
    return 0; //Uma das duas listas não existe, logo, não podemos seguir

    int vetor[MAX*2];

    int tam1,tam2,tamt;
    tamanho_lista(l1,&tam1);
    tamanho_lista(l2,&tam2);
    tamt = tam1+tam2;

    int i, j;

    // Preenchendo o "vetor" com todos os elementos das listas
    for(i=0; i< tam1;i++){
       vetor[i] = l1->no[i];
    }
    int temp = 0;

    for(j = tam1; j < tamt ;j++){
        vetor[j] = l2->no[temp];
        temp++;
    }

    int aux = 0;

    for(i=0;i<=tamt-1;i++){ //Percorrendo todos os indices do vetor e ordenando-os em ordem decrescente
        for(j=i; j<=tamt-1;j++){
            if(vetor[i] < vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

// Como a alocação da lista 3 é o dobro da comum[20], teremos que faze-los aqui:

 Lista l3; // Criando um ponteiro de lista.
    l3 = (Lista) malloc(2* sizeof (struct lista)); // Tamanho da Struct lista.

    if (l3 == NULL) { // Verifica se houve alocação bem sucedida.
         return NULL;
    }

   l3 -> fim = 0; // O fim = 0 indica que a primeira posicao livre do vetor.

   for(i=0;i<tamt;i++){
    insere_elem(l3,vetor[i]);
   }

   return l3;
}

void libera(Lista x){

    if(x != NULL){
        free(x);
        x = NULL;
    }
}
