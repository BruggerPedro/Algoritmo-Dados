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
int op, flag = 0,resp, flag2 = 0; //Flag contabiliza a quantidade de especificações da lista (0 - lista nao criada | 1 - Lista criada)
Lista l; Lista l2; Lista l3;
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
            printf("\n\n Digite a opcao desejada: \n");

            scanf("%d", &op);
            setbuf(stdin, NULL);

            if(op < 1 || op > 10)
            printf("\n *** Opcao digitada invalida! As opcoes disponiveis são:");

        } while(op < 1 || op > 10);

        if (op == 10) break; //Sair do sistema

        else if(op != 1 && flag == 0) {
            printf("\n\n Antes de qualquer operacao, a lista 1 precisa ser CRIADA.");
            continue;
            }




        switch(op){
        case 1: {
                printf("\n Digite:\n");
                printf("\n [1] para criar na lista 1.");
                printf("\n [2] para criar na lista 2.\n");
                scanf("%d", &resp);


                if (resp == 1){
                    l = cria_lista();
                    if(l == NULL){
                        printf("\n Falha na criacao da lista");
                        return -1;
                }
                printf("\n A lista foi CRIADA com sucesso!");
                flag++; //Quantidade de vezes que a lista 1 foi criada
                break;
                }
                else if(resp == 2){
                    l2 = cria_lista();
                    if(l2 == NULL){
                        printf("\n Falha na criacao da lista");
                        return -1;
                }
                printf("\n A lista foi CRIADA com sucesso!");
                flag2++;
                break;
                }
                else{
                    printf("\n Opção inválida");
                    break;
                }
        }

        case 2:{
            printf("\n Digite:\n");
            printf("\n [1] para esvaziar a lista 1.");
            printf("\n [2] para esvaziar a lista 2.\n");
            scanf("%d", &resp);
            if (resp == 1){
                if(esvazia_lista(l) == 0){
                    printf("\n Nao foi possivel esvaziar a lista.");
                    return -1;
            }
            printf("\n A lista foi ESVAZIADA com sucesso!");
            break;
            }

            else if(resp == 2){
                if(esvazia_lista(l2) == 0){
                printf("\n Nao foi possivel esvaziar a lista.");
                return -1;
            }
            printf("\n A lista foi ESVAZIADA com sucesso!");
            break;
            }

            else{
                printf("\n Opção inválida");
                break;
            }
        }

        case 3:{
            printf("\n Digite:\n");
            printf("\n [1] para apagar na lista 1.");
            printf("\n [2] para apagar na lista 2.\n");
            scanf("%d", &resp);
            if (resp == 1){
                if(apaga_lista(&l) == 0){
                    printf("\n Nao foi possivel apagar a lista 1.");
                    return -1;
                    }
                    printf("\n lista 1 foi APAGADA com sucesso!");
                    flag = 0;
                    break;
                }
                else if(resp == 2){
                    if(apaga_lista(&l2) == 0){
                    printf("\n Nao foi possivel apagar a lista 2.");
                    return -1;
                    }
                    printf("\n lista 2 foi APAGADA com sucesso!");
                    flag2 = 0;
                    break;
                    }
                    else{
                        printf("\n Opção inválida");
                        break;
                        }
                    }
        case 4:{
            int n; //Elemento digitado
            printf("\n Digite o elemento (int) a ser inserido na lista: ");
            scanf("%d", &n);

            printf("\n Digite:\n");
            printf("\n [1] para inserir na lista 1.");
            printf("\n [2] para inserir na lista 2.\n");
            scanf("%d", &resp); // resposta da operação

            // Tratamentos:
            if (resp == 1){
                if (insere_elem(l,n) == 0)
                printf("\n A lista esta cheia! Nao foi possivel incluir o elemento %d. ",n);
            else
                printf("\n O elemento %d foi incluido com sucesso! ",n);
            break;
                }
                else if(resp == 2){
                if (insere_elem(l2,n) == 0){
                    printf("\n A lista esta cheia! Nao foi possivel incluir o elemento %d. ",n);
                    }else{
                        printf("\n O elemento %d foi incluido com sucesso! ",n);
                }
                        break;
                }
                else{
                    printf("\n Opção inválida");
                    break;
                    }
        }

        case 5:{
            int n;
             printf("\n Digite o elemento (int) a ser excluido na lista: ");
             scanf("%d", &n);

             printf("\n Digite:\n");
             printf("\n [1] para remover na lista 1.");
             printf("\n [2] para remover na lista 2.");
             scanf("%d", &resp);

                if (resp == 1){
                if(remove_elem(l,n) == 0){
                    if(lista_vazia(l) == 1)
                        printf("\n A lista 1 ja esta vazia!");
                    else
                        printf("\n Nao existe o elemento %d na lista! ",n);
                        }
                else
                    printf("\n o elemento %d foi removido com sucesso! ",n);
                    break;
                }
                else if(resp == 2){
                    if(remove_elem(l2,n) == 0){
                        if(lista_vazia(l2) == 1)
                            printf("\n A lista 2 ja esta vazia!");
                    else
                        printf("\n Nao existe o elemento %d na lista! ",n);
            }
            else
                printf("\n o elemento %d foi removido com sucesso! ",n);
                break;
            }
            else{
                printf("\n Opção inválida");
                break;
                }
        }
        case 6:{
             printf("\n Digite:\n");
             printf("\n [1] para imprimir a lista 1.");
             printf("\n [2] para imprimir a lista 2.");
             printf("\n [3] para imprimir ambas as listas.\n");
             scanf("%d", &resp);

                if (resp == 1){
                imprime_lista(l);// Interface não é feita no TAD.
                break;
                }
                else if(resp == 2){
                imprime_lista(l2);
                break;
            }

            else if (resp == 3){
                imprime_lista(l);
                imprime_lista(l2);
                break;
            }else{
               printf("\n Opcao invalida! Tente novamente");
                break;
            }


        }
        case 7:{
            printf("\n Digite:\n");
            printf("\n [1] para remover negativos da lista 1.");
            printf("\n [2] para remover negativos da lista 2.\n");
            scanf("%d", &resp);


            if (resp == 1){
                remove_negativos(l);
                break;
            }else if(resp == 2){
                remove_negativos(l2);
                break;
            }else{
                printf("\n Opção inválida");
                break;
        }
        }
        case 8:{
            printf("\n Digite:");
            printf("\n [1] para remover pares da lista 1.");
            printf("\n [2] para remover pares da lista 2.\n");
                scanf("%d", &resp);

                if (resp == 1){
                    remove_pares(l);
                    break;
                }else if(resp == 2){
                    remove_pares(l2);
                    break;
                }else{
                 printf("\n Opção inválida");
                 break;
                 }
        }
        case 9:{
           l3 =  intercala_listas(l,l2);
            imprime_lista(l3);
            break;
        }


        }
        }while(op != 10);

        printf("\n\n\t\t FIM DE PROGRAMA! \n");

        libera(l); //Liberar o espaço alocado para as listas.
        libera(l2);
        libera(l3);

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
        int n; // N representa o elemento presente na lista
        if(get_elem_pos(l,i,&n) == 0){ //Não existe a posição
            break;
        }
        printf(" %d ",n);
        //printf("O %d elemento da lista eh %d\n",i,n);

    }
    printf("} \n Existem %d elementos na lista. \n",i-1); // i-1 será pq o break está dentro do for.
}
