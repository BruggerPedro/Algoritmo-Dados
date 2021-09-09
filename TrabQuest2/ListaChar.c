#include <stdlib.h>
#include "ListaChar.h"
#define MAX 10
#define WORD 15
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
    char no[MAX][WORD];// Nó que vai ser limitado por MAX[10] posições(definido pelo programador). OBS: Colunas serão as Strings
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

int insere_elem(Lista lst, char elem[]){ //Insere o(s) elemento(s) de forma ordenada

    if (lst == NULL || lista_cheia(lst) == 1) //Possuimos 10 palavras
    return 0; // Nao tem como inserir porque lst eh NULL OU ela esta cheia (lista_cheia) == 1)
    int i;
    // TEMPORARIAMENTE
    for(i=0;i<WORD;i++){
        lst->no[lst->fim][i] = elem[i];
    }
    lst->fim++; //Avança o fim
    return 1; //Sucesso
}

int remove_elem(Lista lst, char elem[]){
    if(lst == NULL || lista_vazia(lst) == 1){
    return 0; //Falha
    }

    int i, j, aux = 0;

    // elem ["AULA"]
    // lst = [ "PAO","BOLA", "PORTA"] fim = 3
    // lst = [ "PAO","BOLA","PORTA"]

    while(aux < lst->fim){
      int tam = strcmp(elem,lst->no[aux]); // vetor elem[] possui o mesmo tamanho do nó

    if (tam != 0){ //Elemento e a palavra possuem tamanhos distintos
       aux++;
    }else{

    for(j=0; elem[j] != '\0'; j++){ // Se letra existir
            if (elem[j] != lst->no[aux][j]){    // se letra do elem for diferente da letra do nó
                break;  // Quebra o for j
            }

        // Deslocamento a esq. do sucessor até o final da lista
       for(i=aux+1; i<lst->fim;i++){
            for(j=0; j<15;j++){
            lst->no[i-1][j] = lst->no[i][j];
            }
    }
        lst->fim--; // Decremento
        return 1; // Sucesso
    }
    aux++;


}
}
    if(aux == lst->fim)
    // Elemento não vai existir quando o aux estiver no fim, e quando o elemento inserido for maior que o que está no auxiliar
    return 0;

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
// n [0x19] = temp

// b [0x49] -> [0x19]
// *b = TEMP


// [CASA] fim = 1
int get_elem_pos(Lista lst, int pos, char *ponteiro){
        // pos = Posição do elemento na lista (começa com 1)
    if(lst == NULL || lista_vazia(lst) || pos >= lst->fim)
        return 0; // FALHA


    for(int i=0;i<15;i++){
        ponteiro[i] = lst->no[pos][i];
    }


    return 1; //Sucesso

}


// INCREMENTOS DA QUESTÃO 2:


//Remover todas: remove todas as strings da lista que começam com um dado caractere.
int remove_todas(Lista lst, char letra){ // C

if(lst == NULL || lista_vazia(lst) == 1) //ponteiro nulo ou lista vazia
    return 0;

int i,j; // variavel "generica" para os for´s
char palavra[15]; // Guardar a palavra a ser removida.

    // [CASA, BOLO]
    for(i=0;i<lst->fim;i++){ //Até a ultima "palavra" cadastrada
        if(lst->no[i][0] == letra){
                for(j=0;lst->no[i][j] != '\0';j++){ // Copiando a "palavra" a ser excluida
            palavra[j] = lst->no[i][j]; //
            }
        remove_elem(lst,palavra); // Remove a "palavra" do nó
    }
}
return 1;
}

//Remover maior: remove e retorna a maior string da lista.
//No caso de empate, deve-se remover a primeira ocorrência encontrada.
int remove_maior(Lista lst){
if(lst == NULL || lista_vazia(lst) == 1) //ponteiro nulo ou lista vazia
    return 0;

    int maior = -1; //Possui o tamanho de letras da maior palavra
    int posmai = -1; // Guarda a posição do maior elemento no nó.

    int cont = 0; //Contador de letras

    int i,j; // variavel "generica" para os for´s

    char palavra[15]; // Guardar a palavra a ser removida.

    // [CASA,CARRO, XXXX] fim = 2
    for(i=0;i<lst->fim;i++){ //Até a ultima "palavra" cadastrada
        for(j=0;lst->no[i][j] != '\0';j++){ // Contar as letras da palavra
            cont++;
        }
            if(cont > maior){
                maior = cont; //maior = 5
                posmai = i; // posmai = 1
            }
        }
        for(j=0;lst->no[posmai][j] != '\0';j++){
            palavra[j] = lst->no[posmai][j];
        }
        remove_elem(lst,palavra); // Remove a "palavra" do nó

        return 1;
}

//Tamanho: retorna o número de elementos da lista.

int tamanho_lista(Lista lst, int *tamanho){

    if(lst == NULL)
    return 0;
    // 3 palavras no nó  lst->fim = 3 [0,1,2]
   // [CASA, CARRO, BEBE,__] FIM = 3
    *tamanho = lst->fim; // Recebe o ponteiro tamanho do tipo float e vai retornar o tamanho da lista(qtde de elem)

    return 1;
}


//Concatenar: recebe duas listas (L1 e L2) e retorna uma nova lista L3 com os elementos de
//L1 seguidos dos elementos de L2. As listas originais não devem ser alteradas.

// l1[ZUMBIDO] l2[CARRO]
// l3 [CASA CARRO]

Lista concatena_listas(Lista l1, Lista l2){

    if(l1 == NULL || l2 == NULL)
    return 0; //Uma das duas listas não existe, logo, não podemos seguir


    int vetor[MAX*2][WORD]; // Vetor com o dobro de palavras

    int tam1,tam2,tamt;
    tamanho_lista(l1,&tam1); //Verifica o tamanho de palavras no l1
    tamanho_lista(l2,&tam2); //Verifica o tamanho de palavras no l2
    tamt = tam1+tam2;

    int i, j,k; // Declarações para o for

    // l1 [MARIA] tam1= 1
    // l2[ANDERSON, PEDRO] tam2= 2
    // tamt = 1+2


    // Preenchendo o "vetor" com todos os elementos das listas

    for(i=0; i< tam1;i++){ // Começando pela l1
        for(j=0;l1->no[i][j] != '\0';j++){ //preencher cada letra da palavra l1 para o vetor
        vetor[i][j] = l1->no[i][j];
       }
    }
    int temp = 0; //Temp começa com 0 para percorrermos desde o inicio, a l2.
        // k= 2
    for(k = tam1; k < tamt;k++){
        for(j=0;l2->no[k-tam1][j] != '\0';j++){ //preencher cada letra da palavra l2 para o vetor
        vetor[k][j] = l2->no[temp][j]; // Usando temp pra percorrer desde o inicio
       }
       temp++;
    }


// Como a alocação da lista 3 é o dobro da comum[10], teremos que faze-los aqui:

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

