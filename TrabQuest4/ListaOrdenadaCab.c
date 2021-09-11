#include <stddef.h>
#include "ListaOrdenadaCab.h"

struct no{
int info; //Dado a guardar
struct no * prox;
};

/* BASICAS               *         PEDIDAS NO EXERCICIO
1 - cria_lista OK        *          9 - tamanho_lista OK
2- lista_vazia OK        *          10 - remover_pos OK
3- lista_cheia OK        *          11 - Inverter
4- insere OK             *          12 - Intercala
5- remove OK             *
6- esvazia OK            *
7- apaga_lista OK        *
8- get_elem_pos OK       */


// BASICAS:
Lista cria_lista(){
    Lista cab;
    cab = (Lista) malloc(sizeof(struct no));

    if(cab != NULL){ // Se a alocação funcionou:
     cab->prox = NULL; // "cabeça aponta pra NULL"
     cab->info = 0; //Vamos guardar o tamanho da lista
    }
    return cab; // Retorno já com a cabeça
}

int lista_vazia(Lista lst){
    if(lst->prox == NULL)
        return 1; //Lista vazia
    else
        return 0; //Lista aponta pra algo, logo, não é vazia
}

int lista_cheia(Lista *li){
return 0;
}
// lista_cheia (Na teoria, não existe como "encher" uma lista dinamica, [exceto pela limitação de espaço na memoria])


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

int remove_ord(Lista *lst, int elem){
    if(lista_vazia(lst) == 1) // Se lista for vazia
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

int get_elem_pos(Lista *lst, int pos, float *elem){
    // pos < 1 porque a pos=0 Seria o head
    if((*lst)->prox == NULL || lista_vazia(lst) || pos < 1)
        // lst aponta pra null? OU lista é vazia? OU pos <=0 OU pos > proximo?
     return 0; // FALHA

    *elem = ((*lst)->prox)->info; // elem recebe aquela informação do nó atual
    return 1; //Sucesso
}



// Incrementos extras:

int tamanho_lista(Lista *lst, int *tam){
    if((*lst)->prox == NULL)   // Se o ponteiro->prox estiver null, a lista tá vazia
        return 0;

    return((*lst)->info); // O info da cabeça já armazena o tamanho da lista.
}




int remove_pos(Lista *lst, int pos, int *valor){
    if((*lst)->prox == NULL)   // Se o ponteiro->prox estiver null, a lista tá vazia
        return 0;


if(pos == 0){ // Se quiser remover a primeira posição, basta usar a função criada
 int n = ((*lst)->prox)->info;
 int remove_ord(lst,n);
 valor = n;
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
   int remove_ord(lst,n);
    valor = n;
    return 1;
}

}

Lista inverter_lista(Lista *l1){
        if((*l1)->prox == NULL )   // Se o ponteiro->prox estiver null, a lista tá vazia
        return 0;

Lista l2 = cria_lista(); // Cria a l2 (lista inversa)

Lista aux = (*l1)->prox; // Aux Lista 1

int tam;
tamanho_lista((*l1),&tam);

int i;

for(i=0;i<tam;i++){   // I percorre o tamanho da lista 1

insere_elem(l2, aux->info);    // Pede para inserir
aux = aux->prox;
}
free(aux);

return l2;

}

// Intercala: Recebe duas listas e retorna l3 ordenada.
Lista intercala(Lista *l1,Lista *l2){
    if((*l1)->prox == NULL || (*l2)->prox == NULL)   // Se o ponteiro->prox estiver null, a lista tá vazia
    return 0;

    Lista l3 = cria_lista(); // Cria a terceira lista

    Lista aux = (*l1)->prox;

    int tam1, tam2,tamt;

    tamanho_lista(l1,&tam1);
    tamanho_lista(l2,&tam2);

    tamt = tam1+tam2;

    int i;

    for(i=0;i<tam1;i++){   // I percorre o tamanho da lista 1
    insere_ord(l3, aux->info);    // Pede para inserir
    aux = aux->prox;
    }

    aux = (*l2)->prox; // Aux agora é pra lista 2

    for(i=tam1;i<tamt;i++){
    insere_ord(l3, aux->info);    // Pede para inserir
    aux = aux->prox;
    }

    free(aux);

return l3;

}

// Funções extras:

int insere_elem(Lista *lst, int elem){
 // Aloca um novo nó
 Lista N = (Lista) malloc(sizeof(struct no));
 if(N==NULL){ return 0; } //Falha, alocação mal-sucedida

 //Preenche os campos do novo nó

 N->info = elem;
 N->prox = (*lst)->prox;
 (*lst)->prox = N;
 (*lst)->info++; // Contador de nós
 return 1;
}

void libera(Lista x){

    if(x != NULL){
        free(x);
        x = NULL;
    }
}
