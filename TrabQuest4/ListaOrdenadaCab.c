#include <stddef.h>
#include <stdlib.h>
#include "ListaOrdenadaCab.h"

struct no{
int info; //Número
struct no * prox; // Por ser dinamico, agora temos um ponteiro que "aponta" ao proximo nó
};

//_______________________________________________________________________________________________________________

/*
Operação: cria_lista
- Entrada: Sem entrada.
  Pré-Condição: Sem pré-condições.
- Processo: Cria uma lista e retorna o endereço de uma lista com a cabeça(HEAD) criado.
- Saída: Ponteiro que referencia o local onde foi criada a lista(Podendo ser NULL quando mal-alocado).
- Pós-condição: Sem pós-condição.
*/

Lista cria_lista(){
    Lista cab;
    cab = (Lista) malloc(sizeof(struct no));

    if(cab != NULL){ // Se a alocação funcionou:
     cab->prox = NULL; // "cabeça aponta pra NULL"
     cab->info = 0; //Vamos guardar o tamanho da lista
    }
    return cab; // Retorno já com a cabeça
}

//_______________________________________________________________________________________________________________

/*
Operação: lista_vazia;
- Entrada: Endereço de uma lista.
- Pré-Condição: Sem pré-condições.
- Processo: Verifica se a lista está vazia.
- Saída: 0 (Lista não está vazia), 1 (Lista vazia)
- Pós-condição: Sem pós-condição.
*/

int lista_vazia(Lista lst){
    if(lst->prox == NULL)
        return 1; //Lista vazia
    else
        return 0; //Lista aponta pra algo, logo, não é vazia
}

// _______________________________________________________________________________________________________________

/* Na teoria, não existe como "encher" uma lista dinamica, [exceto pela limitação de espaço na memoria])*/


//int lista_cheia(Lista *li){
//return 0;
//}
// _______________________________________________________________________________________________________________

/*
Operação: insere_ord;
- Entrada: Endereço do endereço de uma lista e o elemento (inteiro) a ser inserido.
- Pré-Condição: Elemento ser um inteiro.
- Processo: Insere (de forma ordenada) o elemento na lista fornecida.
- Saída: 0 (Lista não existe), 1 (Elemento inserido com sucesso).
- Pós-condição: O elemento foi inserido na lista de forma ordenada.
*/

int insere_ord(Lista *lst, int elem){
    // Aloca um novo nó
    Lista N = (Lista) malloc(sizeof(struct no)); // N aloca um novo campo de lista

    if (N == NULL){ return 0;} //Falha: Não conseguiu alocar o Nó

    N->info = elem; //Insere o conteudo (valor de elem)



    // Percorrimento da lista (elem > 1° nó da lista)

    Lista aux = *lst; //Faz aux apontar para 1° nó

    while(aux->prox != NULL && aux->prox->info < elem) // Se existir proximo E Info proximo for menor que o elemento
     aux = aux->prox; //Avança

    // Insere o novo elemento na lista
    N->prox = aux->prox; // Prox do N receberá o prox de Aux
    aux->prox = N; //Prox de aux agora aponta pra N
    (*lst)->info++; //Utiliza o info do cabeçalho pra contador e o incrementa
    return 1; //Sucesso
}
// _______________________________________________________________________________________________________________

/*
Operação: remove_ord;
- Entrada: Endereço do endereço de uma lista e o elemento (inteiro) a ser removido.
- Pré-Condição: Lista existir (existir nó além do HEAD) e elemento ser um inteiro.
- Processo: Remove o elemento na lista fornecida e mantém ordenada.
- Saída: 0 (Lista vazia ou elemento não presente na lista), 1 (Elemento removido com sucesso).
- Pós-condição: O elemento foi removido na lista.
*/

int remove_ord(Lista *lst, int elem){
    if(lista_vazia(*lst) == 1) // Se lista for vazia
    return 0; //falha

    Lista aux = *lst; //Ponteiro auxiliar para o 1°  nó


    // Percorrimento até final de lista, achar elem ou nó maior
    while(aux->prox != NULL && aux->prox->info < elem) // Enquanto existir proximo E info do proximo for menor que elem
   aux = aux->prox;

    if (aux->prox == NULL || aux->prox->info > elem) // Se não existir proximo OU info do prox for MAIOR que elem
        return 0; //Falha

    // Remove elemento da lista
    Lista aux2 = aux->prox; //Aponta nó a ser removido
    aux->prox = aux2->prox; //Retira nó da lista
    free(aux2); //Libera memória alocada
    (*lst)->info--; // Decrementar a quantidade de nós.
    return 1;
}

// _______________________________________________________________________________________________________________

/*
Operação: esvazia_lista
- Entrada: Endereço do endereço de uma lista
- Pré-Condição: Lista existir (existir nó além do HEAD).
- Processo: Esvaziar a lista.
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: a instancia da lista no estado de vazia
*/

int esvazia_lista(Lista *lst){

    if((*lst)->prox == NULL) { // Se o ponteiro estiver apontando NULL, a lista está vazia
      return 0;
      }

    Lista aux = (*lst)->prox; //Ponteiro auxiliar aponta para o começo da lista

    while((*lst)->prox != NULL){ //Enquanto ponteiro for != de NULL
         (*lst)->prox = aux->prox; //lst recebe o que aux apontava
          free(aux);  //Libera o nó atual
          aux = (*lst)->prox; // aux aponta pra nó atual
    }
    free(aux); //Nessa região, lst aponta pra null, então, vamos liberar o aux
    (*lst)->prox = NULL; // Aponta pra nada.

    return 1; // Sucesso

}

// _______________________________________________________________________________________________________________

/*
Operação: apaga_lista
- Entrada: Endereço do endereço de uma lista
- Pré-Condição: Lista existir (existir nó além do HEAD).
- Processo: liberar a instancia da lista e apagar o seu endereço
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: instancia da lista liberada.
*/
void apaga_lista(Lista *lst){

    if((*lst)->prox != NULL){ //Se for igual a null, a lista já está excluida

        Lista aux =(*lst)->prox; // Aux aponta pra inicio da lista

        while((*lst)->prox != NULL){ //Enquanto ponteiro for != de NULL
         (*lst)->prox = aux->prox; //lst recebe o que aux apontava
          free(aux);  //Libera o nó atual
        aux = (*lst)->prox; // aux aponta pra nó atual
    }
        free(aux); // Liberamos o aux
        free(lst); // Liberamos o lst
        //OBS: A diferença entre apaga e esvazia está na linha acima.
        // Enquanto no esvazia "liberamos" apenas o aux, no apaga,
        // liberamos tambem o lst (responsavel por apontar a primeira posição na lista)
    }
}
// _______________________________________________________________________________________________________________

/*
Operação: get_elem_pos
- Entrada: Endereço de uma lista, posição a obter o elemento e uma variavel para receber a informação da dita posição.
-  Pré-Condição: Lista existir (existir nó além do HEAD), a lista não estar vazia e posição ser maior que 0.
- Processo: Através da posição fornecida, busca-se na lista o elemento correspondente aquela posição e o retorna atraves da variavel fornecida.
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: A variavel recebe o valor do elemento presente na posição fornecida.
*/

int get_elem_pos(Lista *lst, int pos, float *elem){
    // pos < 1 porque a pos=0 Seria o head
    if((*lst)->prox == NULL || lista_vazia(*lst) || pos < 1)
        // lst aponta pra null? OU lista é vazia? OU pos <0
     return 0; // FALHA
    Lista aux = (*lst)->prox;
    *elem = aux->info; // elem recebe aquela informação do nó atual
    return 1; //Sucesso
}

// _______________________________________________________________________________________________________________

// Operações especiais:
// _______________________________________________________________________________________________________________


// _______________________________________________________________________________________________________________


// _______________________________________________________________________________________________________________

/*
Operação: tamanho_lista
- Entrada: Endereço do endereço de uma lista e uma variavel para receber o tamanho da lista.
- Pré-Condição: Lista existir (existir nó além do HEAD).
- Processo: Percorre toda a lista e contabiliza o tamanho da mesma.
- Saída: 1 (sucesso) ou 0 (falha)
- Pós-condição: A lista foi contabilizada e seu tamanho foi atribuido para a variavel vinda de argumento.*/


int tamanho_lista(Lista *lst, int *tam){

    if((*lst)->prox == NULL) {// Se o ponteiro estiver apontando NULL, a lista está vazia
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

    *tam = contador ; //Como o aux verifica uma posição "a frente" do nó, somamos o contador com +1 (Nó atual que não possui prox nó)

    return 1;

}
// _______________________________________________________________________________________________________________

/*
Operação: remove_elem;
- Entrada: Endereço do endereço de uma lista, a posção a ser excluida e uma variavel pra receber o valor excluido.
- Pré-Condição: Lista existir (existir nó além do HEAD) e posição existir na lista.
- Processo: Remove o elemento presente na posição fornecida e oferece o valor presente no mesmo.
- Saída: 0 (Lista vazia ou posição não presente na lista), 1 (Elemento removido com sucesso).
- Pós-condição: O elemento foi removido na lista.
*/



int remove_pos(Lista *lst, int pos, int *valor)
{
    if((*lst)->prox == NULL)   // Se o ponteiro->prox estiver null, a lista tá vazia
        return 0;


if(pos == 0) // Se quiser remover a primeira posição, basta usar a função criada
 {
 int n = ((*lst)->prox)->info;
 remove_ord(lst,n);
 (*valor) = n;
 return 1;
}

int tam;
tamanho_lista(lst,&tam);
// 2 > 2
if(pos > tam-1){ // Se o usuario quiser uma posição que não existe(lembrando que o primeiro no é pos=0)
    return 0;
}

int contador = 1; //Começa com 1 pq 0 será a cabeça
Lista aux = (*lst)->prox; //aux aponta pra inicio da lista
aux = aux -> prox; // Se não queremos a primeira posição, vamos avançar

while(aux->prox != NULL || contador < pos){
    contador++;
    aux = aux->prox;
}

if(contador == pos){
   int n = aux->info;
   remove_ord(lst,n);
   (*valor) = n;

}
return 1;
}

// _______________________________________________________________________________________________________________

/*
Operação: inverter_lista
- Entrada: Endereço do endereço da lista a ser sua inversa.
- Pré-Condição: Lista existir (existir nó além do HEAD).
- Processo: Recebe uma lista L e retorna uma nova lista L2, formada pelos elementos de L na
ordem inversa.
- Saída: NULL(Caso a lista fornecidas não existe) ou ponteiro que referencia o local onde foi criada a lista.
- Pós-condição: Sem pós-condição.*/

Lista inverter_lista(Lista *l1){
        if((*l1)->prox == NULL )   // Se o ponteiro->prox estiver null, a lista tá vazia
        return NULL;

Lista l2 = cria_lista(); // Cria a l2 (lista inversa)

Lista aux = (*l1)->prox; // Aux Lista 1

int tam;
tamanho_lista(l1,&tam);

int i;

for(i=0;i<tam;i++){   // I percorre o tamanho da lista 1

insere_ord(&l2, aux->info);    // Pede para inserir
aux = aux->prox;
}
free(aux);

return l2;

}

// _______________________________________________________________________________________________________________

/*
Operação: intercala_listas
- Entrada: Endereço do endereço de duas listas a serem intercaladas.
- Pré-Condição: Listas existirem (existir nó além do HEAD).
- Processo: Recebe duas listas e retorna uma terceira, formada pelos elementos das duas listas intercalados (Sem alteração nas duas listas).
- Saída: NULL(Caso alguma das listas fornecidas não existe) ou ponteiro que referencia o local onde foi criada a terceira lista.
- Pós-condição: Sem pós-condição.*/

Lista intercala(Lista *l1,Lista *l2){
    if((*l1)->prox == NULL || (*l2)->prox == NULL)   // Se o ponteiro->prox estiver null, a lista tá vazia
    return NULL;

    Lista l3 = cria_lista(); // Cria a terceira lista

    Lista aux = (*l1)->prox;

    int tam1, tam2,tamt;

    tamanho_lista(l1,&tam1);
    tamanho_lista(l2,&tam2);

    tamt = tam1+tam2;

    int i;

    for(i=0;i<tam1;i++){   // I percorre o tamanho da lista 1
    insere_ord(&l3, aux->info);    // Pede para inserir
    aux = aux->prox;
    }

    aux = (*l2)->prox; // Aux agora é pra lista 2

    for(i=tam1;i<tamt;i++){
    insere_ord(&l3, aux->info);    // Pede para inserir
    aux = aux->prox;
    }

    free(aux);

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


// Função insere_elem [EXTRA] Não definida no .h por ser "escondida" do aplicativo:

// _______________________________________________________________________________________________________________
/*
Operação: insere_elem;
- Entrada: Endereço do endereço de uma lista e o elemento (inteiro) a ser inserido.
- Pré-Condição: Elemento ser um inteiro.
- Processo: Insere (de forma não ordenada) o elemento na lista fornecida.
- Saída: 0 (Lista não existe), 1 (Elemento inserido com sucesso).
- Pós-condição: O elemento foi inserido na lista de forma não ordenada.
*/

int insere_elem(Lista *lst, int elem)
{

 // Aloca um novo nó
 Lista N = (Lista) malloc(sizeof(struct no));

 if(N==NULL) //Falha, alocação mal-sucedida
    {
        return 0;
    }

 //Preenche os campos do novo nó

 N->info = elem;
 N->prox = (*lst)->prox;
 (*lst)->prox = N;
 (*lst)->info++; // Contador de nós

 return 1;
}

// _______________________________________________________________________________________________________________
