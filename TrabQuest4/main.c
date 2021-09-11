#include <stdio.h>
#include <stdlib.h>
#include "ListaOrdenadaCab.h"
/*
Implementar o TAD listanão ordenada de números reais(float) usando alocaçãodinâmica/encadeada SEM cabeçalho.
Além das operações vistas em sala, o TAD também deve contemplar:
 Tamanho: retorna o número de elementos da lista.
 Remover menor: remove e retornao menor número da lista. No caso de empate, deve-seremover a última ocorrência encontrada.
 Iguais: recebe duas listas ordenadas e verifica se elas são iguais.
 Intercalar: recebe duas listas ordenadas e retorna uma nova lista com os elementos dasduas listas de entrada intercalados.
As listas originais não devem ser alteradas.
 */
void imprime_lista(Lista *);

int main() {
    int op, flag = 0, resp, flag2 = 0; //Flag contabiliza a quantidade de especificações da lista (0 - lista nao criada | 1 - Lista criada)
    Lista l;
    Lista l2;
    Lista l3;
    do { // Programa
        do { //Menu
            //Obtem a opção do usuario
            printf("\n------------------- MENU -------------------\n");
            printf("\n [1] Criar uma lista");
            printf("\n [2] Esvaziar a lista");
            printf("\n [3] Apagar a lista");
            printf("\n [4] Inserir um elemento na lista");
            printf("\n [5] Remover um elemento na lista");
            printf("\n [6] Mostra o tamanho da lista");
            printf("\n [7] Remove a posicao da lista");
            printf("\n [8] Criar lista inversa");
            printf("\n [9] Imprimir a lista");
            printf("\n [10] Intercala listas");
            printf("\n [11] Sair do sistema");
            printf("\n\n Digite a opcao desejada: ");
            printf("\n\n------------------------------------------\n");

            scanf("%d", &op);
            setbuf(stdin, NULL);

            if (op < 1 || op > 11)
                printf("\n *** Opcao digitada invalida! As opcoes disponiveis são:");

        } while (op < 1 || op > 11);

        if (op == 10) break; //Sair do sistema

        else if (op != 1 && flag == 0) {
            printf("\n\n Antes de qualquer operacao, a lista 1 precisa ser CRIADA.");
            continue;
        }

        switch (op) {
            case 1: {

                printf("\n Digite [1] para criar na lista 1 e [2] para criar na lista 2: \n");
                scanf("%d", &resp);

                if (resp == 1) {
                    l = cria_lista();
                    printf("\n A lista foi CRIADA com sucesso!");
                    flag++; //Quantidade de vezes que a lista 1 foi criada
                    break;
                } else if (resp == 2) {
                    l2 = cria_lista();
                    printf("\n A lista foi CRIADA com sucesso!");
                    flag2++;
                    break;
                } else {
                    printf("\n Opção inválida");
                    break;
                }
            }

            case 2:{
                printf("\n Digite [1] para esvaziar a lista 1 e [2] para esvaziar a lista 2: \n");
                scanf("%d", &resp);
                if (resp == 1) {
                    if (esvazia_lista(l) == 0) {
                        printf("\n Nao foi possivel esvaziar a lista.");
                        return -1;
                    }
                    printf("\n A lista foi ESVAZIADA com sucesso!");
                    break;
                }
                else if (resp == 2) {
                    if (esvazia_lista(l2) == 0) {
                        printf("\n Nao foi possivel esvaziar a lista.");
                        return -1;
                    }
                    printf("\n A lista foi ESVAZIADA com sucesso!");
                    break;
                } else {
                    printf("\n Opção inválida");
                    break;
                }
            }

            case 3:{
                printf("\n Digite [1] para apagar a lista 1 e [2] para apagar a lista 2: \n");
                scanf("%d", &resp);
                if (resp == 1) {
                    apaga_lista(l);
                    printf("\n lista 1 foi APAGADA com sucesso!");
                    flag = 0;
                    break;
                } else if (resp == 2) {
                    apaga_lista(l2);
                    printf("\n lista 2 foi APAGADA com sucesso!");
                    flag2 = 0;
                    break;
                } else {
                    printf("\n Opção inválida");
                    break;
                }
            }
            case 4:{
                int n; //Elemento digitado
                printf("\n Digite o elemento (int) a ser inserido na lista: ");
                scanf("%d", &n);

                printf("\n Digite [1] para inserir na lista 1 e [2] para inserir na lista 2: \n");
                scanf("%d", &resp); // resposta da operação

                // Tratamentos:
                if (resp == 1) {
                    if (insere_ord(&l, n) == 0)
                        printf("\n A lista esta cheia! Nao foi possivel incluir o elemento %d . ", n);
                    else
                        printf("\n O elemento %d foi incluido com sucesso! ", n);
                    break;
                } else if (resp == 2) {
                    if (insere_elem(&l2, n) == 0) {
                        printf("\n A lista esta cheia! Nao foi possivel incluir o elemento %d . ", n);
                    } else {
                        printf("\n O elemento %d foi incluido com sucesso! ", n);
                    }
                    break;
                } else {
                    printf("\n Opção inválida");
                    break;
                }
            }

            case 5:{
                int n;
                printf("\n Digite o elemento (float) a ser excluido na lista: ");
                scanf("%d", &n);

                printf("\n Digite [1] para remover na lista 1 e [2] para remover na lista 2: \n");
                scanf("%d", &resp);

                if (resp == 1) {
                    if (remove_ord(&l, n) == 0) {
                        if (lista_vazia(l) == 1)
                            printf("\n A lista 1 ja esta vazia!");
                        else
                            printf("\n Nao existe o elemento %d na lista! ", n);
                    } else
                        printf("\n o elemento %d foi removido com sucesso! ", n);
                    break;
                } else if (resp == 2) {
                    if (remove_ord(&l2, n) == 0) {
                        if (lista_vazia(l2) == 1)
                            printf("\n A lista 2 ja esta vazia!");
                        else
                            printf("\n Nao existe o elemento %d na lista! ", n);
                    } else
                        printf("\n o elemento %d foi removido com sucesso! ", n);
                    break;
                } else {
                    printf("\n Opção inválida");
                    break;
                }
            }
            case 6:{
                int tam1, tam2;
                printf("\n Digite [1] para mostrar tamanho da lista 1 e [2] para mostrar oo tamanho da lista 2 e [3] para mostrar o tamanho de ambas as listas: \n");
                scanf("%d", &resp);

                if (resp == 1) {
                    if (tamanho_lista(&l, &tam1) == 0)
                        printf("\n A lista nao existe! Nao foi possivel calcular o tamanho. ");
                    else
                        printf("\n Tamanho da lista 1 eh: %d", tam1);
                    break;
                } else if (resp == 2) {
                    if (tamanho_lista(&l2, &tam2) == 0)
                        printf("\n A lista nao existe! Nao foi possivel calcular o tamanho. ");
                    else
                        printf("\n Tamanho da lista 2 eh: %d", tam2);
                    break;
                }
                else if (resp == 3) {

                    if (tamanho_lista(&l, &tam1) == 0 || tamanho_lista(&l2, &tam2) == 0)
                        printf("\n Uma das lista nao existe! Nao foi possivel calcular o tamanho. ");
                    else
                        printf("\n O tamanho da lista 1 eh: %d; \n O tamanho da lista 2 eh: %d;", tam1, tam2);
                    break;
                } else {
                    printf("\n Opcao invalida! Tente novamente");
                    break;
                }
            }

            case 7:{

                int n;
                printf("\n Digite a posição a ser excluido na lista: ");
                scanf("%d", &n);

                int valor; //Recebe o valor removido

                printf("\n Digite [1] para remover da lista 1 e [2] para remover da lista 2: \n");
                scanf("%d", &resp);

                if (resp == 1) {
                    if (remove_pos(&l,n,&valor)  == 0) {
                        printf("\n A lista nao existe! Nao foi possivel remover. ");
                        break;
                    } else {
                        printf("\n O valor era o %d e ja foi removido.", valor);
                        break;
                    }
                }else if (resp == 2) {
                    if (remove_pos(&l2,n,&valor)  == 0) {
                        printf("\n A lista nao existe! Nao foi possivel remover. ");
                        break;
                    } else {
                        printf("\n O valor era o %d e ja foi removido.", valor);
                        break;
                    }
                    }else {
                    printf("\n Opcao invalida! Tente novamente");
                    break;
                }
                }
            case 8:{
                l2 = inverter_lista(&l);
                printf("\n A lista 2 (inversa) sera apresentada a seguir");
                imprime_lista(l2);
                break;
            }

            case 9:{
                printf("\n Digite:\n");
                printf("\n [1] para imprimir a lista 1.");
                printf("\n [2] para imprimir a lista 2.");
                printf("\n [3] para imprimir ambas as listas.\n");
                scanf("%d", &resp);

                if (resp == 1) {
                    imprime_lista(l); // Interface não é feita no TAD.
                    break;
                } else if (resp == 2) {
                    imprime_lista(l2);
                    break;
                }
                else if (resp == 3) {
                    imprime_lista(l);
                    imprime_lista(l2);
                    break;
                } else {
                    printf("\n Opcao invalida! Tente novamente");
                    break;
                }
            }

            case 10:{
                l3 = intercala(&l, &l2);
                imprime_lista(l3);
                break;
            }
        }
        }while (op != 11);

        printf("\n\n\t\t FIM DE PROGRAMA! \n");

        libera(l); //Liberar o espaço alocado para as listas.
        libera(l2);
        libera(l3);

        return 0;
    }


void imprime_lista(Lista *l) {
    if (lista_vazia(l) == 1) {
        printf("\n Lista VAZIA! ");
        return;
    }

    printf("\n\n\n \t LISTA: ");
    printf("\n\t {");

    int i;
    int tam;
    tamanho_lista(&l,&tam);

    for (i=1;i<=tam; i++) { //Não sei quantos elementos tem na lista
        int n; // N representa o elemento presente na lista
        get_elem_pos(&l, i, &n);
        printf(" %d ",n);
        //printf("O %d elemento da lista eh %d\n",i,n);

    }
    printf("} \n Existem %d elementos na lista. \n", i - 1); // i-1 será pq o break está dentro do for.
}
