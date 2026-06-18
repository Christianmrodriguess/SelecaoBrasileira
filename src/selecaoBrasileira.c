/*
        Projeto Selecao Brasileira
Integrantes do projeto: Christian, Gabriel e José Elias

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT_JOGADORES 26

typedef struct{
    char nome[30];
    int numCamisa;
    int idade;
    float altura;
    char posicao[20];
    char time[50];
    int ativo;

}Jogador;

Jogador inserirJogador(Jogador *p, int c);
void listarJogadores(Jogador *p, int c);
void exibirJogador(Jogador *p);
void editarJogadores(Jogador *p, int c);
void pesquisarJogadores(Jogador *p, int c);

int main()
{
    Jogador selecao[QNT_JOGADORES];
    int menu = 1, contadorJogadores = 0;

    for(int i=0; i < QNT_JOGADORES; i++){
        selecao[i].ativo = 0;
    }

    do
    {
        printf("\tCONVOCACAO DA SELECAO BRASILEIRA\n\n");
        printf("1. Inserir jogador\n");
        printf("2. Listar jogadores\n");
        printf("3. Editar jogador\n");
        printf("4. Excluir jogador\n");
        printf("5. Pesquisar jogador\n");
        printf("6. Resumo/estatisticas\n");
        printf("0. Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &menu);
        fflush(stdin);

        switch(menu)
        {
        case 0:
            printf("Saindo...");
            break;
        case 1:
            //inserir();
            selecao[contadorJogadores] = inserirJogador(&selecao[0], contadorJogadores);
            contadorJogadores++;
            break;

        case 2:
            //listar();
            listarJogadores(&selecao[0], contadorJogadores);
            break;
        case 3:
            //editar();
            editarJogadores(&selecao[0], contadorJogadores);
            break;
        case 4:
            //excluir();
            break;
        case 5:
            //pesquisar();
            pesquisarJogadores(&selecao[0], contadorJogadores);
            break;
        case 6:
            //resumo();
            break;
        default:
            printf("Opcao Invalida! Digite uma opcao valida. \n");
        }
    }while(menu != 0);
}

Jogador inserirJogador(Jogador *p, int c){
    Jogador j;
    int nomeIgual = 0, camisaIgual = 0;

    do{
        printf("Nome do jogador: ");
        fgets(j.nome, sizeof(j.nome), stdin);
        fflush(stdin);
        j.nome[strcspn(j.nome, "\n")] = '\0';

        for(int i=0; i < c; i++){
            if(strcmp(p->nome, j.nome) == 0){
                printf("Jogador ja cadastrado!\n");
                nomeIgual = 1;
                break;
            }
            p++;
        }
    } while(nomeIgual == 1);

    do{
        printf("Numero da camisa: ");
        scanf("%d", &j.numCamisa);
        fflush(stdin);

        for(int i=0; i < c; i++){
            if(j.numCamisa == p->numCamisa){
                printf("Camisa ja cadastrada!\n");
                camisaIgual = 1;
                break;
            }
            p++;
        }
    } while(camisaIgual == 1);

    printf("Idade: ");
    scanf("%d", &j.idade);
    fflush(stdin);

    printf("Altura: ");
    scanf("%f", &j.altura);
    fflush(stdin);

    printf("Posicao: ");
    fgets(j.posicao, sizeof(j.posicao), stdin);
    fflush(stdin);
    j.posicao[strcspn(j.posicao, "\n")] = '\0';

    printf("Time: ");
    fgets(j.time, sizeof(j.time), stdin);
    fflush(stdin);
    j.time[strcspn(j.time, "\n")] = '\0';

    j.ativo = 1;

    return j;
}

void listarJogadores(Jogador *p, int c){
    for(int i=0; i < c; i++){
        if(p->ativo != 0){
            exibirJogador(p);
        }
        printf("\n\n");

        p++;
    }
}

void exibirJogador(Jogador *p){
    printf("\n\nNome: %s \n", p->nome);
    printf("Numero da camisa: %d \n", p->numCamisa);
    printf("Idade: %d \n", p->idade);
    printf("Altura: %.2f \n", p->altura);
    printf("Posicao: %s \n", p->posicao);
    printf("Time: %s\n", p->time);
}

void editarJogadores(Jogador *p, int c){
    int camisa;
    printf("Digite o numero da camisa do jogador: ");
    scanf("%d", &camisa);

    for(int i=0; i < c; i++){
        if(p->numCamisa == camisa){

        }
    }

}

void pesquisarJogadores(Jogador *p, int c){
    int opcao;
    char nome[30];
    do{
        printf("\tPesquisar por: \n");
        printf("1 - Nome\n");
        printf("2 - Numero da camisa\n");
        printf("3 - Idade\n");
        printf("4 - Altura\n");
        printf("5 - Posicao\n");
        printf("6 - Time\n");
        printf("0 - Voltar\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                printf("Retornando ao menu...\n\n");
                break;
            case 1:
                printf("Digite o nome: ");
                fgets(nome, sizeof(nome), stdin);
                fflush(stdin);
                nome[strcspn(nome, "\n")] = '\0';

                for(int i=0; i < c; i++){
                    if(strstr(p->nome, nome) != NULL){
                        exibirJogador(p);
                    }
                    printf("\n");
                    p++;
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                break;
        }

    } while (opcao != 0);
}