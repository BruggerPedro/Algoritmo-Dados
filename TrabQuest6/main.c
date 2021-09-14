#include <stdio.h>
#include <stdlib.h>
#include "ListaDouble.h"

/*
Implementar o TAD lista não ordenada de números reais (double) usando alocação dinâmicacom encadeamento duplo.
Além das operações vistas em sala, o TAD deve contemplar:
 Remover todos: remove todas as ocorrências de um elemento da lista
 Remover maior: remove o maior elemento encontrado na lista, retornando seu valor.
  No caso de empate, deve-se remover a primeira ocorrência encontrada.
 Inserir na posição: insira o elemento em uma posição indicada. A operação deve verificarse a posição desejada é válida.
 Inverter: recebe uma lista L e retorna uma nova lista L2, formada pelos elementos de L naordem inversa.
  A lista original não deve ser alterada
*/


// Prototipo da função imprime_lista.
void imprime_lista(Lista *);

int main() {

    int op; // Variavel responsavel por receber a opção desejada do menu
    int flag = 0,flag2 = 0; //Flag contabiliza a quantidade de especificações da lista (0 - lista nao criada | 1 - Lista criada)
    // Variavel responsavel por selecionar se a operação será realizada na lista 1 ou lista 2
    Lista l; // Declaração das "listas".

    do { // Programa
        do { //Menu
            //Obtem a opção do usuario
            printf("\n------------------- MENU -------------------\n");
            printf("\n [1] Criar uma lista");
            printf("\n [2] Esvaziar a lista");
            printf("\n [3] Apagar a lista");
            printf("\n [4] Inserir um elemento na lista");
            printf("\n [5] Remover um elemento na lista");
            printf("\n [6] Remove todas as ocorrências de um elemento da lista ");
            printf("\n [7] Insira o elemento em uma posição indicada. ");
            printf("\n [8] Remove o maior elemento da lista.");
            printf("\n [9] Inverte a lista");
            printf("\n [10] Imprimir a lista");
            printf("\n [11] Sair do sistema");
            printf("\n\n Digite a opcao desejada: ");
            printf("\n\n------------------------------------------\n");

            scanf("%d", &op);
            setbuf(stdin, NULL);

            if (op < 1 || op > 11)
                printf("\n *** Opcao digitada invalida! As opcoes disponiveis são:");

        } while (op < 1 || op > 11);

        if (op == 11) break; //Sair do sistema

        else if (op != 1 && flag == 0) {
            printf("\n\n Antes de qualquer operacao, a lista 1 precisa ser CRIADA.");
            continue;
        }

        switch (op) {
            case 1: { // Cria uma lista

                    l = cria_lista();
                    printf("\n A lista foi CRIADA com sucesso!");
                    flag++; //Quantidade de vezes que a lista 1 foi criada
                    break;
                }


            case 2:{ // Esvaziar a lista:


                    if (esvazia_lista(&l) == 0) {
                        printf("\n Nao foi possivel esvaziar a lista.");
                        return -1;
                    }
                    printf("\n A lista foi ESVAZIADA com sucesso!");
                    break;
                   }

            case 3:{ // Apagar

                    apaga_lista(&l);
                    printf("\n lista 1 foi APAGADA com sucesso!");
                    flag = 0;
                    break;
                   }
            case 4:{ //Inserir elemento na lista
                double n; //Elemento digitado
                printf("\n Digite o elemento (float) a ser inserido na lista: ");
                scanf("%f", &n);

                // Tratamentos:

                    if  (insere_elemento(l, n) == 0)
                        printf("\n A lista esta cheia! Nao foi possivel incluir o elemento %f . ", n);
                    else
                        printf("\n O elemento %f foi incluido com sucesso! ", n);
                    break;

                   }

            case 5:{ // Remove um elemento na lista

                double n;
                printf("\n Digite o elemento (float) a ser excluido na lista: ");
                scanf("%f", &n);


                    if (remove_elemento(&l, n) == 0) {
                        if (lista_vazia(l) == 1)
                            printf("\n A lista 1 ja esta vazia!");
                        else
                            printf("\n Nao existe o elemento %f na lista! ", n);
                    } else
                        printf("\n o elemento %f foi removido com sucesso! ", n);
                    break;

                   }
            case 6:{ // Remove todas as ocorrências de um elemento da lista

                double n; //Elemento digitado
                printf("\n Digite o elemento (float) a ser excluido na lista: ");
                scanf("%f", &n);

                    if ((remove_todos(&l, &n)) == 0)
                        printf("\n Falha ao excluir os elementos da lista 1 ");
                    else
                        printf("\n Os elemento %f foram excluido com sucesso da lista 1",n);
                    break;

                    }

            case 7:{ // Insira o elemento em uma posição indicada. A operação deve verificarse a posição desejada é válida
                double n;
                printf("\n Digite o elemento a ser inserido na lista: ");
                scanf("%f", &n);

                int pos; //Recebe uma caractere a ser inserido em uma posição da lista

                printf("\n Digite a  posição que o elemento vai ser inserido: \n");
                scanf("%d", &pos);


                    if  (insere_posicao(&l, pos, n)  == 0) {
                        printf("\n A lista nao existe! Nao foi possivel inserir o elemento nesta possicao solicitada!. ");
                        break;
                    } else {
                        printf("\n O elemento %f na posição %d foi inserido com sucesso!.", n, pos);
                        break;
                    }

                }
            case 8:{ // Remove o maior elemento encontrado na lista, retornando seu valor.
                double n;


                    if ((remove_maior(&l, &n))  == 0) {
                        printf("\n A lista nao existe! Nao foi possivel remover no fim!. ");
                        break;
                    } else {
                        printf("\n Os elementos %f foram removido com sucesso!.", n);
                        break;
                    }

                    }

            //recebe uma lista L e retorna uma nova lista L2, formada pelos elementos de L na ordem inversa.
            case 9:
                {
                    if (inverte(&l)  == 0) {
                        printf("\n A lista nao existe! Nao foi possivel inverter a lista!. ");
                        break;
                    } else {
                        printf("\n A lista foi invertida com sucesso!.");
                        break;
                    }
                }

            case 10:{ // Imprimir


                    imprime_lista(&l); // Interface não é feita no TAD.
                    break;

                    }


        }

        }while (op != 11);

        printf("\n\n\t\t FIM DE PROGRAMA! \n");

        libera(l); //Liberar o espaço alocado para as listas.


        return 0;
}

/*
Operação: imprime_lista
- Entrada: Endereço de uma lista
-  Pré-Condição: Lista existir (Endereço ser valido)
- Processo: Ao percorrer a lista, apresentamos sua informação na aplicação.
- Saída: Por se tratar de um retorno VOID, a saida não existe.
- Pós-condição: Sem pós-condição.
*/

void imprime_lista(Lista *l) {
    if (lista_vazia(l) == 1) {
        printf("\n Lista VAZIA! ");
        return;
    }

    printf("\n\n\n \t LISTA: ");
    printf("\n\t {");

    int i;
    int tam;
    double n;
    tamanho_lista(&l,&tam);

    for (i=1;i<=tam; i++) { //Não sei quantos elementos tem na lista
        int n; // N representa o elemento presente na lista
        get_elem_pos(&l, i);
        printf(" %f ",n);
        //printf("O %d elemento da lista eh %d\n",i,n);

    }
    printf("} \n Existem %d elementos na lista. \n", i - 1); // i-1 será pq o break está dentro do for.
}
