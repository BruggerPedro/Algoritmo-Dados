#include <stdio.h>
#include <stdlib.h>

#include "ListaInt.h"

/*Implementar o TAD listaordenada decrescente de números inteiros com no máximo 20 elementos, usando alocação estática/sequencial. Além das operações vistas em sala, o TAD também deve contemplar:
 Remover negativos: remove todos os elementos negativos da lista.
 Remover pares: remove todos os elementos pares da lista.
 Tamanho: retorna o número de elementos da lista.
 Intercalar: recebe duas listas ordenadas (L1 e L2) e retorna uma nova lista L3 formadapelos elementos de L1 e L2 intercalados, mantendo o critério de ordenação. As listas originais não devem ser alteradas.
*/

void imprime_lista(Lista);

int main(){
int op, flag = 0; //Flag contabiliza a quantidade de especificações da lista (0 - lista nao criada | 1 - Lista criada)
Lista l; Lista l2;
    do{ // Programa
        do{ //Menu
            //Obtem a opção do usuario
            printf("\n------------------- MENU -------------------\n");
            printf("\n [1] Criar uma lista");
            printf("\n [2] Esvaziar a lista");
            printf("\n [3] Apagar a lista");
            printf("\n [4] Inserir um elemento na lista");
            printf("\n [5] Remover um elemento na lista");
            printf("\n [6] Imprimir a lista");
            printf("\n [7] Remove negativos");
            printf("\n [8] Remove par");
            printf("\n [9] Intercala listas");
            printf("\n [10] Sair do sistema");
            printf("\n\n Digite a opcao desejada: ");
            printf("\n\n------------------------------------------\n");

            scanf("%d", &op);
            setbuf(stdin, NULL);

            if(op < 1 || op > 10)
            printf("\n *** Opcao digitada invalida! As opcoes disponiveis são:");

        } while(op < 1 || op > 10);

        if (op == 10) break; //Sair do sistema

        else if(op != 1 && flag == 0) {
            printf("\n\n Antes de qualquer operacao, a lista precisa ser CRIADA.");
            continue;
        }
        switch(op){
        case 1: {
                if(flag) { // verifica se a lista já existe (Flag == 1)
                    if(apaga_lista(&l) == 0 ){
                        printf("\n Já existe uma instancia de lista e houve falha ao tentar apaga-la");
                    break;
                    }
                }
                l = cria_lista();
                if(l == NULL){
                    printf("\n Falha na criacao da lista");
                    return -1;
                }
                if (flag) // Se ao criar a lista, ela existisse outra, entra nesta cond
                    printf("\n A lista foi REINICIALIZADA pela %d vez com sucesso!\n",flag);
                else
                    printf("\n A lista foi CRIADA com sucesso!");
                flag++;
                break;
            }

        case 2:{
        if(esvazia_lista(l) == 0 ){
            printf("\n Nao foi possivel esvaziar a lista.");
            return -1;
        }
        printf("\n A lista foi ESVAZIADA com sucesso!");
        break;
        }

        case 3:{
        if(apaga_lista(&l) == 0){
            printf("\n Nao foi possivel apagar a lista.");
            return -1;
        }
        printf("\n lista foi APAGADA com sucesso!");
        flag = 0;
        break;
        }
        case 4:{
            int n;
            printf("\n Digite o elemento (int) a ser inserido na lista: ");
            scanf("%d", &n);

            if (insere_elem(l,n) == 0)
                printf("\n A lista esta cheia! Nao foi possivel incluir o elemento %d. ",n);
            else
                printf("\n O elemento %d foi incluido com sucesso! ",n);
            break;
        }

        case 5:{
            int n;
             printf("\n Digite o elemento (int) a ser excluido na lista: ");
             scanf("%d", &n);

            if(remove_elem(l,n) == 0){
                if(lista_vazia(l) == 1)
                    printf("\n A lista ja esta vazia!");
                else
                    printf("\n Nao existe o elemento %d na lista! ",n);
            }
            else
                    printf("\n o elemento %d foi removido com sucesso! ",n);
            break;
        }
        case 6:{
            imprime_lista(l); // Interface não é feita no TAD.
            break;
        }
        case 7:{
            remove_negativos(l);
            break;
        }
        case 8:{
            remove_pares(l);
            break;
        }
        case 9:{
            intercala_listas(l,l2);
            break;
        }
        }

        }while(op != 10);

        printf("\n\n\t\t FIM DE PROGRAMA! \n");
        return 0;
}

void imprime_lista(Lista l){
    if(lista_vazia(l) == 1){
        printf("\n Lista VAZIA! ");
        return;
    }

    printf("\n\n\n \t LISTA: ");
    printf("\n\t {");
    int i;
    for(i=1;;i++){ //Não sei quantos elementos tem na lista
        int n;
        if(get_elem_pos(l,i,&n) == 0){ //Não existe a posição
            break;
        }
        printf(" %d ",n);
        //printf("O %d elemento da lista eh %d\n",i,n);

    }
    printf("} \n Existem %d elementos na lista. \n",i-1);
}
