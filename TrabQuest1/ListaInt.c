#include <stdlib.h>
#include "ListaInt.h"
#define MAX 20

struct lista {
    int no[MAX];// Nó que vai ser limitado por MAX[20] posições(definido pelo programador).
    int fim; // O fim vai indicar qual é a próxima posição disponível.
};

// _______________________________________________________________________________________________________________

/*
Operação: cria_lista

- Entrada: Sem entrada.
  Pré-Condição: Sem pré-condições.
- Processo: Alocação e criação da lista e de seu ponteiro.
- Saída: Ponteiro que referencia o local onde foi criada a lista(Podendo ser NULL quando mal-alocado).
- Pós-condição: Sem pós-condição.
*/

Lista cria_lista() { // Alocar uma instancia da estrutura lista(malloc).

    Lista lst; // Criando um ponteiro de lista.
    lst = (Lista) malloc(sizeof (struct lista)); // Tamanho da Struct lista.

    if (lst != NULL) { // Verifica se houve alocação bem sucedida.
        lst -> fim = 0; // O fim = 0 indica que a primeira posicao livre do vetor.
    }
    return lst; // Retornamos o endereço de ponteiro(lst).
}

// _______________________________________________________________________________________________________________

/*
Operação: lista_vazia;

- Entrada: Endereço de uma lista.
- Pré-Condição: Lista existir (Endereço ser valido)
- Processo: Verifica se a lista está vazia.
- Saída: -1 (Lista não existe), 0 (Lista não está vazia), 1 (Lista vazia)
- Pós-condição: Sem pós-condição.
*/
int lista_vazia(Lista lst) {
    if (lst == NULL) {
        return -1; // Ponteiro nao esta apontando pra lista valida/existente, entao declaramos como ERRO
    }
    if (lst->fim == 0)
        return 1; // A lista esta vazia
    else
        return 0; // Ha elementos dentro da lista, portanto nao esta vazia
}

// _______________________________________________________________________________________________________________

/*
Operação: lista_cheia

- Entrada: Endereço de uma lista.
- Pré-Condição: Lista existir (Endereço ser valido)
- Processo: Verifica se a lista está cheia.
- Saída: -1 (Lista não existe), 0 (Lista não está cheia), 1 (Lista cheia)
- Pós-condição: Sem pós-condição.
*/
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

// _______________________________________________________________________________________________________________

/*
Operação: insere_elem;

- Entrada: Endereço de uma lista e o elemento (inteiro) a ser inserido.
- Pré-Condição: Lista existir (Endereço ser valido) e elemento ser um inteiro.
- Processo: Insere (de forma ordenada) o elemento na lista fornecida.
- Saída: 0 (Lista não existe ou Lista cheia), 1 (Elemento inserido com sucesso).
- Pós-condição: O elemento foi inserido na lista de forma ordenada.
*/
int insere_elem(Lista lst, int elem){ //Insere o(s) elemento(s) de forma ordenada

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

// _______________________________________________________________________________________________________________

/*
Operação: remove_elem;

- Entrada: Endereço de uma lista e o elemento (inteiro) a ser removido.
-  Pré-Condição: Lista existir (Endereço ser valido) e elemento ser um inteiro.
- Processo: Remove o elemento na lista fornecida. Após a remoção, a lista mantém-se ordenada.
- Saída: 0 (Lista não existe ou lista vazia, ou elemento não presente na lista), 1 (Elemento removido com sucesso).
- Pós-condição: O elemento foi removido na lista de forma ordenada.
*/

int remove_elem(Lista lst, int elem){
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

// _______________________________________________________________________________________________________________

/*
Operação: apaga_lista
- Entrada: Endereço do endereço de uma lista
- Pré-Condição: endereço ser válido (primeiro endereço “ponteiro de ponteiro”)
- Processo: liberar a instancia da lista e apagar o seu endereço
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: instancia da lista liberada.
*/

int apaga_lista(Lista *end_lst){
    if(end_lst == NULL) //Se o ponteiro não aponta pra lista
        return 0;

    free(*end_lst); // Limpa a região da lista (liberando a memoria para o computador)
    *end_lst = NULL; // apontar pra NULL para não conseguirem acessar aquela area novamente

    return 1;
}

// _______________________________________________________________________________________________________________

/*
Operação: esvazia_lista

- Entrada: Endereço de uma lista
- Pré-Condição: Lista existir (Endereço ser valido)
- Processo: Colocar a lista no estado de vazia
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: a instancia da lista no estado de vazia
*/

int esvazia_lista(Lista lst){
     if(lst == NULL ){
        return 0;
     }
    lst->fim = 0;
    return 1;
}

// _______________________________________________________________________________________________________________

/*
Operação: get_elem_pos

- Entrada: Endereço de uma lista, posição a obter o elemento e uma variavel para receber a informação da dita posição.
-  Pré-Condição: Lista existir (Endereço ser valido).
- Processo: Através da posição fornecida, busca-se na lista o elemento correspondente aquela posição e o retorna atraves da variavel fornecida.
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: A variavel recebe o valor do elemento presente na posição fornecida.

*/

int get_elem_pos(Lista lst, int pos, int *elem){
        // pos = Posição do elemento na lista (começa com 1)
    if(lst == NULL || lista_vazia(lst) || pos <= 0 || pos > lst->fim)
        return 0; // FALHA
    *elem = lst->no[pos-1]; // subtração pq temos que passar o indice real da lista
    return 1; //Sucesso
}

// _______________________________________________________________________________________________________________

// Operações especiais:
// _______________________________________________________________________________________________________________


// _______________________________________________________________________________________________________________

/*
Operação: remove_negativos

- Entrada: Endereço de uma lista
-  Pré-Condição: Lista existir (Endereço ser valido)
- Processo: Percorre toda a lista e remove(se existir) os numeros negativos presentes na mesma (mantendo sua ordenação).
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: A lista agora não provém de elementos negativos.
*/

int remove_negativos(Lista x){ // Definimos a Lista como x para que não haja erro de interpretação do que estamos instanciando

    int i;

    if(x == NULL || lista_vazia(x) == 1)
    return 0;

    for(i = 0; i < x->fim; i++){
        if((int)x->no[i] < 0){
            remove_elem(x, x->no[i]);
            i--; //remove o elemento se for negativo e verifica o próximo
        }
    }

    return 1;

}

// _______________________________________________________________________________________________________________

/*
Operação: remove_pares


- Entrada: Endereço de uma lista
-  Pré-Condição: Lista existir (Endereço ser valido)
- Processo: Percorre toda a lista e remove(se existir) os numeros pares presentes na mesma (mantendo sua ordenação).
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: A lista agora não provém de elementos pares.*/

int remove_pares(Lista x){

    int i;

    if(x == NULL || lista_vazia(x) == 1)
    return 0;

    for(i = 0; i < x->fim; i++){
        if((int)x->no[i] % 2 == 0){
            remove_elem(x, x->no[i]);
            i--; //remove o elemento se for par e verifica o próximo
        }
    }

    return 1;

}
// _______________________________________________________________________________________________________________


/*
Operação: tamanho_lista
- Entrada: Endereço de uma lista e uma variavel para receber o tamanho da lista.
-  Pré-Condição: Lista existir (Endereço ser valido).
- Processo: Percorre toda a lista e contabiliza o tamanho da mesma.
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: A lista foi contabilizada e seu tamanho foi atribuido para a variavel vinda de argumento.*/

int tamanho_lista(Lista x, int *tamanho){

    if(x == NULL)
    return 0;

    *tamanho = x->fim; // Recebe o ponteiro tamanho do tipo float e vai retornar o tamanho da lista(qtde de elem)

    return 1;

}

// _______________________________________________________________________________________________________________

/*
Operação: intercala_listas
- Entrada: Endereço de duas listas a serem intercaladas.
- Pré-Condição: Listas existirem (Endereço ser valido).
- Processo: Recebe duas listas ordenadas e retorna uma terceira, formada pelos elementos das duas listas intercalados, mantendo sua ordenação. (Sem alteração nas duas listas).
- Saída: NULL(Caso alguma das listas fornecidas não existe) ou ponteiro que referencia o local onde foi criada a terceira lista.
- Pós-condição: Sem pós-condição.
*/

Lista intercala_listas(Lista l1, Lista l2){

    if(l1 == NULL || l2 == NULL)
    return NULL; //Uma das duas listas não existe, logo, não podemos seguir

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
