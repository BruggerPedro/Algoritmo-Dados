#include <stdio.h>
#include <stdlib.h>
#include "ListaChar.h"

// Prototipo da função imprime_lista.
void imprime_lista(Lista);


int main(){
int op; // Variavel responsavel por receber a opção desejada do menu
int flag = 0,flag2 = 0; //Flag contabiliza a quantidade de especificações da lista (0 - lista nao criada | 1 - Lista criada)
int resp; // Variavel responsavel por selecionar se a operação será realizada na lista 1 ou lista 2
int tam = 0;  // Variavel que receberá o tamanho da lista.
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
            printf("\n [6] Remover todas as palavras da lista comecadas com a letra digitada");
            printf("\n [7] Remove maior palavra da lista");
            printf("\n [8] Apresentar o tamanho da lista");
            printf("\n [9] Imprimir a lista");
            printf("\n [10] Concatena listas");
            printf("\n [11] Sair do sistema");
            printf("\n\n Digite a opcao desejada: \n");

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
        case 1: { // Cria uma lista
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

        case 2:{ // Esvaziar a lista:
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

        case 3:{ // Apagar
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
        case 4:{ //Inserir elemento na lista
            char n[15]; //Elemento digitado
            printf("\n Digite o termo a ser inserido na lista: ");
            gets(n);

            printf("\n Digite:\n");
            printf("\n [1] para inserir na lista 1.");
            printf("\n [2] para inserir na lista 2.\n");
            scanf("%d", &resp); // resposta da operação

            // Tratamentos:
            if (resp == 1){
                if (insere_elem(l,n) == 0)
                printf("\n A lista esta cheia! Nao foi possivel incluir o elemento %s. ",n);
            else
                printf("\n O elemento %s foi incluido com sucesso! ",n);
            break;
                }
                else if(resp == 2){
                if (insere_elem(l2,n) == 0){
                    printf("\n A lista esta cheia! Nao foi possivel incluir o elemento %s. ",n);
                    }else{
                        printf("\n O elemento %s foi incluido com sucesso! ",n);
                }
                        break;
                }
                else{
                    printf("\n Opção inválida");
                    break;
                    }
        }

        case 5:{ // Remove um elemento na lista
            char n[15];
             printf("\n Digite o termo a ser excluido na lista: ");
             gets(n);

             printf("\n Digite:\n");
             printf("\n [1] para remover na lista 1.");
             printf("\n [2] para remover na lista 2.\n");
             scanf("%d", &resp);

                if (resp == 1){
                if(remove_elem(l,n) == 0){
                    if(lista_vazia(l) == 1)
                        printf("\n A lista 1 ja esta vazia!");
                    else
                        printf("\n Nao existe o elemento %s na lista! ",n);
                        }
                else
                    printf("\n o elemento %s foi removido com sucesso! ",n);
                    break;
                }
                else if(resp == 2){
                    if(remove_elem(l2,n) == 0){
                        if(lista_vazia(l2) == 1)
                            printf("\n A lista 2 ja esta vazia!");
                    else
                        printf("\n Nao existe o elemento %s na lista! ",n);
            }
            else
                printf("\n o elemento %s foi removido com sucesso! ",n);
                break;
            }
            else{
                printf("\n Opção inválida");
                break;
                }
        }
        case 6:{ // Remove palavras começadas com a letra digitada
            char n; //Elemento digitado
            printf("\n Digite a letra (char) a ser removido na lista: ");
            scanf("%c",&n);

            printf("\n Digite:\n");
            printf("\n [1] para remover todas as palavras com a letra, na lista 1.");
            printf("\n [2] para remover todas as palavras com a letra, na lista 2.\n");
            scanf("%d", &resp);


            if (resp == 1){
                if(remove_todas(l,n) == 0){
                   printf("\n Falha na remoção na lista");
                    return -1;
                }
                printf("\n Todas as palavras com a letra %c foram removidas com sucesso!",n);
                break;
                }
                else if(resp == 2){
                    if(remove_todas(l2,n) == 0){
                   printf("\n Falha na remoção na lista");
                    return -1;
                }
                printf("\n Todas as palavras com a letra %c foram removidas com sucesso!",n);
                break;
        }else{
                printf("\n Opção inválida");
                break;
            }
        }

        case 7:{ //Remove a maior palavra da lista
            printf("\n Digite:\n");
            printf("\n [1] para remover a maior palavra da lista 1.");
            printf("\n [2] para remover a maior palavra da lista 2.\n");
            scanf("%d", &resp);

            if(resp == 1){
                if(remove_maior(l) == 0){
                 printf("\n Falha na remoção da maior palavra na lista");
                    return -1;
                }
                printf("\n A maior palavra foi removida com sucesso!");
                break;
                } else if(resp == 2){
                    if(remove_maior(l2) == 0){
                   printf("\n Falha na remoção da maior palavra na lista");
                    return -1;
                }
                printf("\n A maior palavra foi removida com sucesso!");
                break;
            }else{
                printf("\n Opção inválida");
                break;
            }
        }


        case 8:{    // Tamanho da lista
            printf("\n Digite:\n");
            printf("\n [1] para verificar tamanho da lista 1.");
            printf("\n [2] para verificar tamanho da lista 2.\n");
            scanf("%d", &resp);

            if(resp == 1){
                if(tamanho_lista(l,&tam) == 0){
                 printf("\n Falha ao obter o tamanho da lista 1");
                    return -1;
                }
                printf("\n Existem %d palavras cadastradas!",tam);
                break;
                } else if(resp == 2){
                    if(tamanho_lista(l2,&tam) == 0){
                   printf("\n Falha ao obter o tamanho da lista 2");

                    return -1;
                }
                printf("\n Existem %d palavras cadastradas!",tam);
                break;
            }else{
                printf("\n Opção inválida");
                break;
            }

        }

        case 9:{ // Imprime a lista
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

        case 10:{ //Concatenar
            l3 =  concatena_listas(l,l2);

            imprime_lista(l3);
            break;
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
    if (l == NULL){
        printf("\n Ponteiro esta NULO");
        return;
    }

    if(lista_vazia(l) == 1){
        printf("\n Lista VAZIA! ");
        return;
    }

    printf("\n\n\n \t LISTA: ");
    printf("\n\t {");
    int i;


for(i=0;;i++){
    char n[15];// N representa o elemento presente na lista
    if(get_elem_pos(l,i,&n) == 0){ //Não existe a posição
    break;
}
    printf("%s,",n);

    }
    printf("} \n Existem %d elementos na lista. \n",i); // i-1 será pq o break está dentro do for.

}
