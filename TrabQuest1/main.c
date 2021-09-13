#include <stdio.h>
#include <stdlib.h>
#include "ListaInt.h"

// Prototipo da função imprime_lista.
void imprime_lista(Lista);

int main(){
int op; // Variavel responsavel por receber a opção desejada do menu
int flag = 0,flag2 = 0; //Flag contabiliza a quantidade de especificações da lista (0 - lista nao criada | 1 - Lista criada)
int resp; // Variavel responsavel por selecionar se a operação será realizada na lista 1 ou lista 2
Lista l; Lista l2; Lista l3; // Declaração das "listas".

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
            printf("\n [10] Verificar o tamanho da lista:");
            printf("\n [11] Sair do sistema");
            printf("\n\n Digite a opcao desejada: ");
            printf("\n\n------------------------------------------\n");

            scanf("%d", &op);
            setbuf(stdin, NULL);

            if(op < 1 || op > 11)
            printf("\n *** Opcao digitada invalida! As opcoes disponiveis são:");

        } while(op < 1 || op > 11);

        if (op == 11) break; //Sair do sistema

        else if(op != 1 && flag == 0) {
            printf("\n\n Antes de qualquer operacao, a lista 1 precisa ser CRIADA.");
            continue;
            }




        switch(op){
        case 1: { // Criar uma lista:
                printf("\n Digite [1] para criar na lista 1 e [2] para criar na lista 2: \n");
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

        case 2:{ // Esvaziar a lista:
            printf("\n Digite [1] para esvaziar a lista 1 e [2] para esvaziar a lista 2: \n");
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

        case 3:{ // Apagar
            printf("\n Digite [1] para apagar na lista 1 e [2] para apagar na lista 2: \n");
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

        case 4:{ //Inserir elemento na lista
            int n; //Elemento digitado
            printf("\n Digite o elemento (int) a ser inserido na lista: ");
            scanf("%d", &n);

            printf("\n Digite [1] para inserir na lista 1 e [2] para inserir na lista 2: \n");
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

        case 5:{    // Remove um elemento na lista
            int n;
             printf("\n Digite o elemento (int) a ser excluido na lista: ");
             scanf("%d", &n);

             printf("\n Digite [1] para remover na lista 1 e [2] para remover na lista 2: \n");
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

        case 6:{ // Imprime a lista
             printf("\n Digite [1] para imprimir a lista 1 e [2] para imprimir a lista 2 e [3] para imprimir ambas as listas: \n");
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
        case 7:{ // Remove os negativos
            printf("\n Digite [1] para remover negativos da lista 1 e [2] para remover negativos da lista 2: \n");
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
        case 8:{ // Remove os pares
            printf("\n Digite [1] para remover pares da lista 1 e [2] para remover pares da lista 2: \n");
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

        case 9:{ // Intercala as listas
           l3 =  intercala_listas(l,l2);
            imprime_lista(l3);
            break;
        }

        case 10:{
        int tamanho; // Variavel que receberá o tamanho da lista.
        printf("\n Digite [1] para verificar o tamanho da lista 1 e [2] para verificar o tamanho da lista 2: \n");
             scanf("%d", &resp);

                if (resp == 1){
                tamanho_lista(l,&tamanho);
                break;
                }
                else if(resp == 2){
                tamanho_lista(l,&tamanho);
                break;
            }else{
               printf("\n Opcao invalida! Tente novamente");
                break;
            }

        }

        }
        }while(op != 11);

        printf("\n\n\t\t FIM DE PROGRAMA! \n");

        libera(l); //Liberar o espaço alocado para as listas.
        libera(l2);
        libera(l3);

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

    }
    printf("} \n Existem %d elementos na lista. \n",i-1); // i-1 será pq o break está dentro do for.
}
