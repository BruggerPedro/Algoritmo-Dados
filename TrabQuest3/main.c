#include <stdio.h>
#include "lista.h"

void imprime_lista(Lista);

int main(){
int op, flag = 0; //Flag contabiliza a quantidade de especificações da lista (0 - lista nao criada | 1 - Lista criada)
Lista l;
    do{ // Programa
        do{ //Menu
            //Obtem a opção do usuario
            printf("\n\t _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n [1] Criar uma lista");
            printf("\n [2] Esvaziar a lista");
            printf("\n [3] Apagar a lista");
            printf("\n [4] Inserir um elemento na lista");
            printf("\n [5] Remover um elemento na lista");
            printf("\n [6] Imprimir a lista");
            printf("\n [7] Sair do sistema");
            printf("\n\n Digite a opcao desejada: ");
            printf("\n\t _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");

            scanf("%d", &op);
            setbuf(stdin, NULL);

            if(op < 1 || op > 7)
            printf("\n *** Opcao digitada invalida! As opcoes disponiveis são:");

        } while(op < 1 || op > 7);

        if (op == 7) break; //Sair do sistema

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
        esvazia_lista(l);
        printf("\n A lista foi ESVAZIADA com sucesso!");
        break;
        }


        case 3:{
        apaga_lista(&l);
        printf("\n lista foi APAGADA com sucesso!");
        flag = 0;
        break;
        }

        case 4:{
            char n;
            printf("\n Digite o elemento (char) a ser inserido na lista: ");
            scanf("%c", &n);

            if (insere_elem(l,n) == 0)
                printf("\n A lista esta cheia! Nao foi possivel incluir o elemento %c. ",n);
            else
                printf("\n O elemento %c foi incluido com sucesso! ",n);
            break;
        }

        case 5:{
            char n;
             printf("\n Digite o elemento (char) a ser excluido na lista: ");
             scanf("%c", &n);

            if(remove_elem(l,n) == 0){
                if(lista_vazia(l) == 1)
                    printf("\n A lista ja esta vazia!");
                else
                    printf("\n Nao existe o elemento %c na lista! ",n);
            }
            else
                    printf("\n o elemento %c foi removido com sucesso! ",n);
            break;
        }
        case 6:{
            imprime_lista(l); // Interface não é feita no TAD.
            break;
        }
        }

        }while(op != 7);

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

    Lista aux = l; //Ponteiro auxiliar para o 1° nó
    char n;

        printf(" %c ",n);
        //printf("O %d elemento da lista eh %d\n",i,n);

    }







