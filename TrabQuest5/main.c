#include <stdio.h>
#include <stdlib.h>
#include "ListaCiclo.h"

/*
Implementar o TAD listanão ordenada de caracteres usando alocação dinâmica comencadeamento CÍCLICO.
Além das operações vistas em sala, o TAD também devecontemplar:
 Inserir no início: inserir o elemento no início da lista
 Inserir na posição: insira o elemento em uma posição indicada. A operação deve verificarse a posição desejada é válida.
 Remover no fim: remover o último elemento da lista, retornando seu valor para aplicação.
 Remover vogais: remove todos os elementos da lista que são vogais.
*/


// Prototipo da função imprime_lista.
void imprime_lista(Lista );

int main() {

    int op; // Variavel responsavel por receber a opção desejada do menu
    int flag = 0,flag2 = 0; //Flag contabiliza a quantidade de especificações da lista (0 - lista nao criada | 1 - Lista criada)
    int resp; // Variavel responsavel por selecionar se a operação será realizada na lista 1 ou lista 2
    Lista l; Lista l2; // Declaração das "listas".

    do { // Programa
        do { //Menu
            //Obtem a opção do usuario
            printf("\n------------------- MENU -------------------\n");
            printf("\n [1] Criar uma lista");
            printf("\n [2] Esvaziar a lista");
            printf("\n [3] Apagar a lista");
            printf("\n [4] Inserir um elemento na lista");
            printf("\n [5] Remover um elemento na lista");
            printf("\n [6] Insere no inicio da lista um elemento");
            printf("\n [7] Insere em uma posicao da lista especifica");
            printf("\n [8] Remove no fim");
            printf("\n [9] Remove as vogais");
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

            case 2:{ // Esvaziar a lista:
                printf("\n Digite [1] para esvaziar a lista 1 e [2] para esvaziar a lista 2: \n");
                scanf("%d", &resp);
                if (resp == 1) {
                    if (esvazia_lista(&l) == 0) {
                        printf("\n Nao foi possivel esvaziar a lista.");
                        return -1;
                    }
                    printf("\n A lista foi ESVAZIADA com sucesso!");
                    break;
                }
                else if (resp == 2) {
                    if (esvazia_lista(&l2) == 0) {
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

            case 3:{ // Apagar
                printf("\n Digite [1] para apagar a lista 1 e [2] para apagar a lista 2: \n");
                scanf("%d", &resp);
                if (resp == 1) {
                    apaga_lista(&l);
                    printf("\n lista 1 foi APAGADA com sucesso!");
                    flag = 0;
                    break;
                } else if (resp == 2) {
                    apaga_lista(&l2);
                    printf("\n lista 2 foi APAGADA com sucesso!");
                    flag2 = 0;
                    break;
                } else {
                    printf("\n Opção inválida");
                    break;
                }
            }
            case 4:{ //Inserir elemento na lista
                char n; //Elemento digitado
                printf("\n Digite o elemento (char) a ser inserido na lista: ");
                scanf("%c", &n);

                printf("\n Digite [1] para inserir na lista 1 e [2] para inserir na lista 2: \n");
                scanf("%d", &resp); // resposta da operação

                // Tratamentos:
                if (resp == 1) {
                    if (insere_final(&l, n) == 0)
                        printf("\n A lista esta cheia! Nao foi possivel incluir o elemento %c . ", n);
                    else
                        printf("\n O elemento %c foi incluido com sucesso! ", n);
                    break;
                } else if (resp == 2) {
                    if (insere_final(&l2, n) == 0) {
                        printf("\n A lista esta cheia! Nao foi possivel incluir o elemento %c . ", n);
                    } else {
                        printf("\n O elemento %c foi incluido com sucesso! ", n);
                    }
                    break;
                } else {
                    printf("\n Opção inválida");
                    break;
                }
            }

            case 5:{ // Remove um elemento na lista
                char n;
                printf("\n Digite o elemento (char) a ser excluido na lista: ");
                scanf("%c", &n);

                printf("\n Digite [1] para remover na lista 1 e [2] para remover na lista 2: \n");
                scanf("%d", &resp);

                if (resp == 1) {
                    if (remove_inicio(&l, n) == 0) {
                        if (lista_vazia(l) == 1)
                            printf("\n A lista 1 ja esta vazia!");
                        else
                            printf("\n Nao existe o elemento %c na lista! ", n);
                    } else
                        printf("\n o elemento %c foi removido com sucesso! ", n);
                    break;
                } else if (resp == 2) {
                    if (remove_inicio(&l2, n) == 0) {
                        if (lista_vazia(l2) == 1)
                            printf("\n A lista 2 ja esta vazia!");
                        else
                            printf("\n Nao existe o elemento %c na lista! ", n);
                    } else
                        printf("\n o elemento %c foi removido com sucesso! ", n);
                    break;
                } else {
                    printf("\n Opção inválida");
                    break;
                }
            }
            case 6:{ // Insere um elemento no incio

                char n; //Elemento digitado
                printf("\n Digite o elemento (char) a ser inserido na lista: ");
                scanf("%c", &n);

                printf("\n Digite [1] para inserir no incio da lista 1 e [2] para inserir no inicio da lista 2 e [3] para inserir no inicio de ambas as listas: \n");
                scanf("%d", &resp);


                if (resp == 1) {
                    if (insere_inicio(&l,n) == 0)
                        printf("\n Falha ao inserir no inicio da lista 1 ");
                    else
                        printf("\n O elemento %c foi inserido com sucesso no inicio da lista 1",n);
                    break;
                } else if (resp == 2) {
                    if (insere_inicio(&l2,n) == 0)
                        printf("\n Falha ao inserir no inicio da lista 2 ");
                    else
                        printf("\n O elemento %c foi inserido com sucesso no inicio da lista 1",n);
                    break;
                }
                else if (resp == 3) {

                    if (insere_inicio(&l,n) == 0 || (insere_inicio(&l2,n) == 0))
                        printf("\n Uma das lista nao existe! Nao foi possivel inserir o elemento. ");
                    else
                        printf("\n Foi inserido com sucesso o elemento: %c em ambas as listas!",n);
                    break;
                } else {
                    printf("\n Opcao invalida! Tente novamente");
                    break;
                }
            }

            case 7:{ // Insere um elemento em uma posição especifica

                char n;
                printf("\n Digite o elemento a ser inserido na lista: ");
                scanf("%c", &n);

                int pos; //Recebe uma caractere a ser inserido em uma posição da lista

                printf("\n Digite a  posição que o elemento vai ser inserido: \n");
                scanf("%d", &pos);

                printf("\n Digite [1] para inserir na lista 1 e [2] para inserir na lista 2: \n");
                scanf("%d", &resp);

                if (resp == 1) {
                    if  (insere_posicao(&l,pos,n)  == 0) {
                        printf("\n A lista nao existe! Nao foi possivel inserir o elemento nesta possicao solicitada!. ");
                        break;
                    } else {
                        printf("\n O elemento %c na posição %d foi inserido com sucesso!.", n, pos);
                        break;
                    }
                }else if (resp == 2) {
                    if  (insere_posicao(&l2,pos,n)  == 0) {
                        printf("\n A lista nao existe! Nao foi possivel inserir o elemento nesta posicao solicitada!. ");
                        break;
                    } else {
                        printf("\n O elemento %c na posição %d foi inserido com sucesso!.", n, pos);
                        break;
                    }
                    }else {
                    printf("\n Opcao invalida! Tente novamente");
                    break;
                }
                }
            case 8:{ // Remove no fim da lista
                char n;

                printf("\n Digite [1] para remover no fim da lista 1 e [2] para remover no fim da lista 2: \n");
                scanf("%d", &resp);

                if (resp == 1) {
                    if (remover_fim(&l,&n)  == 0) {
                        printf("\n A lista nao existe! Nao foi possivel remover no fim!. ");
                        break;
                    } else {
                        printf("\n O elemento %c foi removido com sucesso!.", n);
                        break;
                    }
                }else if (resp == 2) {
                    if (remover_fim(&l2,&n)  == 0) {
                        printf("\n A lista nao existe! Nao foi possivel remover no fim!. ");
                        break;
                    } else {
                        printf("\n O elemento %c foi removido com sucesso!.", n);
                        break;
                    }
                    }else {
                    printf("\n Opcao invalida! Tente novamente");
                    break;
                }
            }

            //Remover vogais: remove todos os elementos da lista que são vogais.
            case 9:
                {
                     printf("\n Digite [1] para remover as vogais da lista 1 e [2] para remover as vogais da lista 2: \n");
                     scanf("%d", &resp);

                if (resp == 1) {
                    if (remove_vogais(&l)  == 0) {
                        printf("\n A lista nao existe! Nao foi possivel remover as vogais!. ");
                        break;
                    } else {
                        printf("\n As vogais foram removidas com sucesso da lista 1!.");
                        break;
                    }
                }else if (resp == 2) {
                    if (remove_vogais(&l2)  == 0) {
                        printf("\n A lista nao existe! Nao foi possivel remover as vogais!. ");
                        break;
                    } else {
                        printf("\n As vogais foram removidas com sucesso da lista 2");
                        break;
                    }
                    }else {
                    printf("\n Opcao invalida! Tente novamente");
                    break;
                }
                }

            case 10:{ // Imprimir
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


        }

        }while (op != 11);

        printf("\n\n\t\t FIM DE PROGRAMA! \n");

        libera(l); //Liberar o espaço alocado para as listas.
        libera(l2);


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

void imprime_lista(Lista l) {
    if (lista_vazia(l) == 1) {
        printf("\n Lista VAZIA! ");
        return;
    }

    printf("\n\n\n \t LISTA: ");
    printf("\n\t {");

    int i;
    int tam;
    tamanho_lista(&l,&tam);
    char n;

    for (i=1;i<=tam; i++) { //Não sei quantos elementos tem na lista
        // N representa o elemento presente na lista

        get_elem_pos(l, i, &n);
        printf("%c",n);
        //printf("O %d elemento da lista eh %d\n",i,n);

    }
    printf("} \n Existem %d elementos na lista. \n", i - 1); // i-1 será pq o break está dentro do for.
}
