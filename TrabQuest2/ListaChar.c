#include <stdlib.h>
#include "ListaChar.h"
#define MAX 10
#define WORD 15

struct lista {
    char no[MAX][WORD];// Nó que vai ser limitado por MAX[10] posições(definido pelo programador). OBS: Colunas serão as Strings
    int fim; // O fim vai indicar qual é a próxima posição disponível.
};


//_______________________________________________________________________________________________________________

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
- Entrada: Endereço de uma lista e o elemento (string (vetor de char)) a ser inserido.
- Pré-Condição: Lista existir (Endereço ser valido) e elemento ser um vetor de char.
- Processo: Insere (de forma não ordenada) o elemento na lista fornecida.
- Saída: 0 (Lista não existe ou Lista cheia), 1 (Elemento inserido com sucesso).
- Pós-condição: O elemento foi inserido na lista de forma não ordenada.
*/
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

// _______________________________________________________________________________________________________________

/*
Operação: remove_elem;
- Entrada: Endereço de uma lista e o elemento (string (vetor de char)) a ser removido.
-  Pré-Condição: Lista existir (Endereço ser valido) e elemento ser (string (vetor de char)).
- Processo: Remove o elemento na lista fornecida.
- Saída: 0 (Lista não existe ou lista vazia, ou elemento não presente na lista), 1 (Elemento removido com sucesso).
- Pós-condição: O elemento foi removido na lista.
*/

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
// n [0x19] = temp

// b [0x49] -> [0x19]
// *b = TEMP


// [CASA] fim = 1

// _______________________________________________________________________________________________________________

/*
Operação: get_elem_pos
- Entrada: Endereço de uma lista, posição a obter o elemento e uma variavel para receber a informação da dita posição.
-  Pré-Condição: Lista existir (Endereço ser valido).
- Processo: Através da posição fornecida, busca-se na lista o elemento correspondente aquela posição e o retorna atraves da variavel fornecida.
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: A variavel recebe o valor do elemento presente na posição fornecida.
*/

int get_elem_pos(Lista lst, int pos, char *ponteiro){
    int i;
        // pos = Posição do elemento na lista (começa com 1)
    if(lst == NULL || lista_vazia(lst) || pos >= lst->fim)
        return 0; // FALHA


    for(i=0;i<15;i++){
        ponteiro[i] = lst->no[pos][i];
    }


    return 1; //Sucesso

}


// _______________________________________________________________________________________________________________

// Operações especiais:
// _______________________________________________________________________________________________________________


// _______________________________________________________________________________________________________________


/*
Operação: remove_todas
- Entrada: Endereço de uma lista e a letra (char).
-  Pré-Condição: Lista existir (Endereço ser valido).
- Processo: Percorre toda a lista e remove(se existir) as “palavras” presentes na lista que iniciam com a letra fornecida.
- Saída: 1 (sucesso) ou 0 (falha).
- Pós-condição: A lista agora não provém de palavras com a letra fornecida.*/


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

// _______________________________________________________________________________________________________________

/*
Operação: remove_maior
- Entrada: Endereço de uma lista.
- Pré-Condição: Lista existir (Endereço ser valido).
- Processo: Percorre toda a lista e remove a maior “palavra” da lista.
- Saída: 1 (sucesso) ou 0 (falha).
- Pós-condição: A lista agora não provém da maior palavra verificada.
*/


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

// _______________________________________________________________________________________________________________

/*
Operação: tamanho_lista
- Entrada: Endereço de uma lista e uma variavel para receber o tamanho da lista.
- Pré-Condição: Lista existir (Endereço ser valido).
- Processo: Percorre toda a lista e contabiliza o tamanho da mesma.
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: A lista foi contabilizada e seu tamanho foi atribuido para a variavel vinda de argumento.*/

int tamanho_lista(Lista lst, int *tamanho){

    if(lst == NULL)
    return 0;
    // 3 palavras no nó  lst->fim = 3 [0,1,2]
   // [CASA, CARRO, BEBE,__] FIM = 3
    *tamanho = lst->fim; // Recebe o ponteiro tamanho do tipo float e vai retornar o tamanho da lista(qtde de elem)

    return 1;
}

// _______________________________________________________________________________________________________________


/*
Operação: concatena_listas
- Entrada: Endereço de duas listas a serem intercaladas.
- Pré-Condição: Listas existirem (Endereço ser valido).
- Processo: Recebe duas listas (L1 e L2) e retorna uma nova lista L3 com os elementos de L1 seguidos dos elementos de L2. As listas originais não devem ser alteradas.
- Saída: NULL(Caso alguma das listas fornecidas não existe) ou ponteiro que referencia o local onde foi criada a terceira lista.
- Pós-condição: Sem pós-condição.*/

Lista concatena_listas(Lista l1, Lista l2){
    int i,j;
    if(l1 == NULL || l2 == NULL)
    return NULL; //Uma das duas listas não existe, logo, não podemos seguir


    int vetor[MAX*2][WORD]; // Vetor com o dobro de palavras

    for(i=0; i< MAX*2;i++){ // Começando pela l1
        for(j=0;j < WORD;j++){ //preencher cada letra da palavra l1 para o vetor
        vetor[i][j] = 0;
       }
    }

    int tam1,tam2,tamt;
    tamanho_lista(l1,&tam1); //Verifica o tamanho de palavras no l1
    tamanho_lista(l2,&tam2); //Verifica o tamanho de palavras no l2
    tamt = tam1+tam2;

    int k; // Declarações para o for

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
        // l1+l2
        // l1 [Vitor] // l2[Pedro, Maria]
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

   char n[15];
    //tamt = 4 (4 nomes)
   for(i=0;i<tamt;i++){
        for(j=0;vetor[i][j] != '\0';j++){
            n[j] = vetor[i][j];
        }

   insere_elem(l3,n);
   // n = [VITOR]
   // N = [000]

   int p;
   for(p=0; p< 15;p++){ // Começando pela l1
        n[p] = 0;
       }

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
