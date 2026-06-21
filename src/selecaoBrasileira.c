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
} Jogador;

Jogador inserirJogador(Jogador *p, int c);
void listarJogadores(Jogador *p, int c);
void exibirJogador(Jogador *p);
void editarJogadores(Jogador *p, int c);
void pesquisarJogadores(Jogador *p, int c);
void excluirJogador(Jogador *p, int c);
void estatisticas(Jogador *p, int c);
void limpaTela();

int main()
{
    Jogador selecao[QNT_JOGADORES];
    int menu = 1, contadorJogadores = 11;

    for(int i=0; i < QNT_JOGADORES; i++){
        selecao[i].ativo = 0;
    }

    strcpy(selecao[0].nome, "Alisson");
    selecao[0].numCamisa = 1;
    selecao[0].idade = 29;
    selecao[0].altura = 1.91;
    strcpy(selecao[0].posicao, "Goleiro");
    strcpy(selecao[0].time, "Liverpool");
    selecao[0].ativo = 1;

    strcpy(selecao[1].nome, "Ederson");
    selecao[1].numCamisa = 2;
    selecao[1].idade = 26;
    selecao[1].altura = 1.83;
    strcpy(selecao[1].posicao, "Meia Central");
    strcpy(selecao[1].time, "Atalanta");
    selecao[1].ativo = 1;

    strcpy(selecao[2].nome, "Gabriel Magalhaes");
    selecao[2].numCamisa = 3;
    selecao[2].idade = 28;
    selecao[2].altura = 1.88;
    strcpy(selecao[2].posicao, "Zagueiro");
    strcpy(selecao[2].time, "Arsenal");
    selecao[2].ativo = 1;

    strcpy(selecao[3].nome, "Marquinhos");
    selecao[3].numCamisa = 4;
    selecao[3].idade = 32;
    selecao[3].altura = 1.83;
    strcpy(selecao[3].posicao, "Zagueiro");
    strcpy(selecao[3].time, "PSG");
    selecao[3].ativo = 1;

    strcpy(selecao[4].nome, "Casemiro");
    selecao[4].numCamisa = 5;
    selecao[4].idade = 34;
    selecao[4].altura = 1.83;
    strcpy(selecao[4].posicao, "Volante");
    strcpy(selecao[4].time, "Manchester United");
    selecao[4].ativo = 1;

    strcpy(selecao[5].nome, "Alex Sandro");
    selecao[5].numCamisa = 6;
    selecao[5].idade = 35;
    selecao[5].altura = 1.80;
    strcpy(selecao[5].posicao, "Lat Esquerdo");
    strcpy(selecao[5].time, "Flamengo");
    selecao[5].ativo = 1;

    strcpy(selecao[6].nome, "Vinicius Jr.");
    selecao[6].numCamisa = 7;
    selecao[6].idade = 25;
    selecao[6].altura = 1.76;
    strcpy(selecao[6].posicao, "Ponta Esquerda");
    strcpy(selecao[6].time, "Real Madrid");
    selecao[6].ativo = 1;

    strcpy(selecao[7].nome, "Bruno Guimaraes");
    selecao[7].numCamisa = 8;
    selecao[7].idade = 28;
    selecao[7].altura = 1.82;
    strcpy(selecao[7].posicao, "Meia Central");
    strcpy(selecao[7].time, "Newcastle");
    selecao[7].ativo = 1;

    strcpy(selecao[8].nome, "Matheus Cunha");
    selecao[8].numCamisa = 9;
    selecao[8].idade = 27;
    selecao[8].altura = 1.83;
    strcpy(selecao[8].posicao, "Centroavante");
    strcpy(selecao[8].time, "Manchester United");
    selecao[8].ativo = 1;

    strcpy(selecao[9].nome, "Neymar");
    selecao[9].numCamisa = 10;
    selecao[9].idade = 34;
    selecao[9].altura = 1.75;
    strcpy(selecao[9].posicao, "Meia Ofensivo");
    strcpy(selecao[9].time, "Santos");
    selecao[9].ativo = 1;

    strcpy(selecao[10].nome, "Raphinha");
    selecao[10].numCamisa = 11;
    selecao[10].idade = 29;
    selecao[10].altura = 1.76;
    strcpy(selecao[10].posicao, "Ponta Direita");
    strcpy(selecao[10].time, "Barcelona");
    selecao[10].ativo = 1;

    do{
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

        switch(menu){
            case 0:
                printf("Saindo...");
                break;
            case 1:
                //inserir();
                limpaTela();
                selecao[contadorJogadores] = inserirJogador(&selecao[0], contadorJogadores);
                contadorJogadores++;
                break;
            case 2:
                //listar();
                limpaTela();
                listarJogadores(&selecao[0], contadorJogadores);
                break;
            case 3:
                //editar();
                limpaTela();
                editarJogadores(&selecao[0], contadorJogadores);
                break;
            case 4:
                //excluir();
                limpaTela();
                excluirJogador(&selecao[0], contadorJogadores);
                break;
            case 5:
                //pesquisar();
                limpaTela();
                pesquisarJogadores(&selecao[0], contadorJogadores);
                break;
            case 6:
                //resumo();
                limpaTela();
                estatisticas(&selecao[0], contadorJogadores);
                break;
            default:
                limpaTela();
                printf("Opcao Invalida! Digite uma opcao valida. \n");
                break;
        }
    } while(menu != 0);
}

Jogador inserirJogador(Jogador *p, int c){
    Jogador j;
    Jogador *pAux = p;
    int nomeIgual = 0, camisaIgual = 0;

    do{
        p = pAux;
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
            else{
                nomeIgual = 0;
            }
            p++;
        }
    } while(nomeIgual == 1);

    do{
        p = pAux;
        printf("Numero da camisa: ");
        scanf("%d", &j.numCamisa);
        fflush(stdin);

        for(int i=0; i < c; i++){
            if(j.numCamisa == p->numCamisa){
                printf("Camisa ja cadastrada!\n");
                camisaIgual = 1;
                break;
            }
            else{
                camisaIgual = 0;
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
    printf("Nome: %s \n", p->nome);
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
    fflush(stdin);

    for(int i=0; i < c; i++){
        if(p->numCamisa == camisa){
            printf("Jogador encontrado! Editando...\n");
            printf("Nome do jogador: ");
            fgets(p->nome, sizeof(p->nome), stdin);
            fflush(stdin);
            p->nome[strcspn(p->nome, "\n")] = '\0';

            printf("Numero da camisa: ");
            scanf("%d", &p->numCamisa);
            fflush(stdin);

            printf("Idade: ");
            scanf("%d", &p->idade);
            fflush(stdin);

            printf("Altura: ");
            scanf("%f", &p->altura);
            fflush(stdin);

            printf("Posicao: ");
            fgets(p->posicao, sizeof(p->posicao), stdin);
            fflush(stdin);
            p->posicao[strcspn(p->posicao, "\n")] = '\0';

            printf("Time: ");
            fgets(p->time, sizeof(p->time), stdin);
            fflush(stdin);
            p->time[strcspn(p->time, "\n")] = '\0';

            p->ativo = 1;
            
            return;
        }
        p++;
    }
    printf("Jogador não encontrado!\n\n");
}

void pesquisarJogadores(Jogador *p, int c){
    int opcao;
    char nome[30];
    int numCamisa;
    int idade;
    float altura;
    char posicao[20];
    char time[50];

    printf("\tPesquisar por: \n");
    printf("1 - Nome\n");
    printf("2 - Numero da camisa\n");
    printf("3 - Idade\n");
    printf("4 - Altura\n");
    printf("5 - Posicao\n");
    printf("6 - Time\n");
    printf("0 - Voltar\n");
    scanf("%d", &opcao);
    fflush(stdin);

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
            printf("Digite o numero da camisa: ");
            scanf("%d", &numCamisa);
            for(int i=0; i < c; i++){
                if(p->numCamisa == numCamisa){
                    exibirJogador(p);
                }
                printf("\n");
                p++;
            }
            break;
        case 3:
            printf("Digite a idade: ");
            scanf("%d", &idade);
            for(int i=0; i < c; i++){
                if(p->idade == idade){
                    exibirJogador(p);
                }
                p++;
            }
            break;
        case 4:
            printf("Digite a altura: ");
            scanf("%f", &altura);
            for(int i=0; i < c; i++){
                if(p->altura == altura){
                    exibirJogador(p);
                }
                p++;
            }
            break;
        case 5:
            printf("Digite a posicao: ");
            fgets(posicao, sizeof(posicao), stdin); 
            fflush(stdin);
            posicao[strcspn(posicao, "\n")] = '\0';
            for(int i=0; i < c; i++){
                if(strstr(p->posicao, posicao) != NULL){
                    exibirJogador(p);
                }
                p++;
            }
            break;
        case 6:
            printf("Digite o time: ");
            fgets(time, sizeof(time), stdin);
            fflush(stdin);
            time[strcspn(time, "\n")] = '\0';
            for(int i=0; i < c; i++){   
                if(strstr(p->time, time) != NULL){
                    exibirJogador(p);
                }
                p++;
            }
            break;
        default:
            printf("Opcao invalida! Retornando ao menu...\n\n");
            break;
    }
}

void excluirJogador(Jogador *p, int c){
    int camisa;
    printf("Digite o numero da camisa do jogador a ser excluido: ");
    scanf("%d", &camisa);

    for(int i=0; i < c; i++){
        if(p->numCamisa == camisa){
            p->ativo = 0;
            printf("Jogador excluido com sucesso!\n\n");
            return;
        }
        p++;
    }
    printf("Jogador nao encontrado!\n\n");
}

void estatisticas(Jogador *p, int c){
    int totalJogadoresAtivos = 0;
    float somaIdade = 0;
    float somaAltura = 0;

    for(int i=0; i < c; i++){
        if(p->ativo != 0){
            totalJogadoresAtivos++;
            somaIdade += p->idade;
            somaAltura += p->altura;
        }
        p++;
    }

    if(totalJogadoresAtivos > 0){
        printf("Total de jogadores ativos: %d\n", totalJogadoresAtivos);
        printf("Media de idade: %.2f\n", somaIdade / totalJogadoresAtivos);
        printf("Media de altura: %.2f\n\n", somaAltura / totalJogadoresAtivos);
    }
    else{
        printf("\nNenhum jogador cadastrado!\n\n");
    }
}
void limpaTela(){
    //system("cls || clear");
}