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

void inserirJogador(Jogador *p, int *c);
void listarJogadores(Jogador *p, int c);
void exibirJogador(Jogador *p);
void editarJogadores(Jogador *p, int c);
void pesquisarJogadores(Jogador *p, int c);
void excluirJogador(Jogador *p, int *c);
void estatisticas(Jogador *p, int c);
void limpaTela();

int main()
{
    Jogador selecao[QNT_JOGADORES];
    int menu = 1, contadorJogadores = 11;

    for(int i=0; i < QNT_JOGADORES; i++){
        strcpy(selecao[i].nome, "");
        selecao[i].numCamisa = 0;
        selecao[i].idade = 0;
        selecao[i].altura = 0;
        strcpy(selecao[i].posicao, "");
        strcpy(selecao[i].time, "");
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
                limpaTela();
                inserirJogador(&selecao[0], &contadorJogadores);
                break;
            case 2:
                limpaTela();
                listarJogadores(&selecao[0], contadorJogadores);
                break;
            case 3:
                limpaTela();
                editarJogadores(&selecao[0], contadorJogadores);
                break;
            case 4:
                limpaTela();
                excluirJogador(&selecao[0], &contadorJogadores);
                break;
            case 5:
                limpaTela();
                pesquisarJogadores(&selecao[0], contadorJogadores);
                break;
            case 6:
                limpaTela();
                estatisticas(&selecao[0], contadorJogadores);
                break;
            default:
                limpaTela();
                printf("Opcao Invalida! Digite uma opcao valida.\n\n");
                break;
        }
    } while(menu != 0);
}

void inserirJogador(Jogador *p, int *c){
    if(*c >= QNT_JOGADORES){
        printf("Limite de jogadores atingido!\n\n");
        return;
    }
    
    Jogador *j = &p[*c];
    int camisaIgual = 0;

    printf("Nome do jogador: ");
    fgets(j->nome, sizeof(j->nome), stdin);
    fflush(stdin);
    j->nome[strcspn(j->nome, "\n")] = '\0';

    do{
        do{
            printf("Numero da camisa: ");
            scanf("%d", &j->numCamisa);
            fflush(stdin);

            if(j->numCamisa < 1 || j->numCamisa > QNT_JOGADORES){
                printf("Numero de camisa invalido! Digite um numero entre 1 e %d.\n", QNT_JOGADORES);
            }
        } while(j->numCamisa < 1 || j->numCamisa > QNT_JOGADORES);

        for(int i=0; i < *c; i++){
            if(j->numCamisa == p[i].numCamisa){
                printf("Camisa ja cadastrada!\n");
                camisaIgual = 1;
                break;
            }
            else {
                camisaIgual = 0;
            }
        }
    } while(camisaIgual == 1);

    do{
        printf("Idade: ");
        scanf("%d", &j->idade);
        fflush(stdin);

        if(j->idade < 15){
            printf("Idade invalida! Nao sao convocados jogadores menores de 15 anos!\n");
        }
    } while(j->idade < 15);

    do{
        printf("Altura: ");
        scanf("%f", &j->altura);
        fflush(stdin);

        if(j->altura < 1.3){
            printf("Impossivel que alguem menor que 1.30m seja um jogador profissional de futebol!\n");
        }
    } while(j->altura < 1.3);

    printf("Posicao: ");
    fgets(j->posicao, sizeof(j->posicao), stdin);
    fflush(stdin);
    j->posicao[strcspn(j->posicao, "\n")] = '\0';

    printf("Time: ");
    fgets(j->time, sizeof(j->time), stdin);
    fflush(stdin);
    j->time[strcspn(j->time, "\n")] = '\0';

    j->ativo = 1;
    (*c)++;
}

void listarJogadores(Jogador *p, int c){
    for(int i=0; i < c; i++){
        if(p->ativo != 0){
            exibirJogador(p);
        }
        p++;
    }
    printf("\nPressione enter para voltar ao menu.\n");
    getchar();
    limpaTela();
}

void exibirJogador(Jogador *p){
    printf("\nNome: %s \n", p->nome);
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
        if(p->numCamisa == camisa && p->ativo == 1){
            printf("Jogador encontrado! Editando...\n");
            printf("Nome do jogador: ");
            fgets(p->nome, sizeof(p->nome), stdin);
            fflush(stdin);
            p->nome[strcspn(p->nome, "\n")] = '\0';

            printf("Numero da camisa: ");
            scanf("%d", &p->numCamisa);
            fflush(stdin);

            do{
                printf("Idade: ");
                scanf("%d", &p->idade);
                fflush(stdin);

                if(p->idade < 15){
                    printf("Idade invalida! Nao sao convocados jogadores menores de 15 anos!\n");
                }
            } while(p->idade < 15);

            do{
                printf("Altura: ");
                scanf("%f", &p->altura);
                fflush(stdin);

                if(p->altura < 1.3){
                    printf("Impossivel que alguem menor que 1.30m seja um jogador profissional de futebol!\n");
                }
            } while(p->altura < 1.3);

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
    int menu;
    char nome[30];
    int numCamisa;
    int idade;
    float altura;
    char posicao[20];
    char time[50];  
    int jogadorEncontrado = 0;

    printf("\tPesquisar por: \n");
    printf("1 - Nome\n");
    printf("2 - Numero da camisa\n");
    printf("3 - Idade\n");
    printf("4 - Altura\n");
    printf("5 - Posicao\n");
    printf("6 - Time\n");
    printf("0 - Voltar\n");
    
    do{
        printf("Digite uma opcao: ");
        scanf("%d", &menu);
        fflush(stdin);

        if(menu < 0 || menu > 6){
            printf("Opcao Invalida! Digite uma opcao valida.\n\n");
        }
    } while(menu < 0 || menu > 6);

    switch(menu){
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
                    jogadorEncontrado = 1;
                }
                p++;
            }
            break;
        case 2:
            printf("Digite o numero da camisa: ");
            scanf("%d", &numCamisa);
            fflush(stdin);

            for(int i=0; i < c; i++){
                if(p->numCamisa == numCamisa){
                    exibirJogador(p);
                    jogadorEncontrado = 1;
                }
                p++;
            }
            break;
        case 3:
            printf("Digite a idade: ");
            scanf("%d", &idade);
            fflush(stdin);

            for(int i=0; i < c; i++){
                if(p->idade == idade){
                    exibirJogador(p);
                    jogadorEncontrado = 1;
                }
                p++;
            }
            break;
        case 4:
            printf("Digite a altura: ");
            scanf("%f", &altura);
            fflush(stdin);

            for(int i=0; i < c; i++){
                if(p->altura == altura){
                    exibirJogador(p);
                    jogadorEncontrado = 1;
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
                    jogadorEncontrado = 1;
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
                    jogadorEncontrado = 1;
                }
                p++;
            }
            break;
        default:
            break;
    }
    if(jogadorEncontrado == 0){
        printf("\nJogador nao encontrado!\n\n");
    }
    if(menu != 0){
        printf("\nPressione enter para voltar ao menu.\n");
        getchar();
    }
    limpaTela();
}

void excluirJogador(Jogador *p, int *c){
    int camisa;
    printf("Digite o numero da camisa do jogador a ser excluido: ");
    scanf("%d", &camisa);

    for(int i=0; i < *c; i++){
        if(p->numCamisa == camisa && p->ativo == 1){
            // strcpy(p->nome, "");
            // p->numCamisa = 0;
            // p->idade = 0;
            // p->altura = 0;
            // strcpy(p->posicao, "");
            // strcpy(p->time, "");
            p->ativo = 0;
            printf("\nJogador excluido com sucesso!\n\n");
            //(*c)--;
            return;
        }
        p++;
    }
    printf("\nJogador nao encontrado!\n\n");
}

void estatisticas(Jogador *p, int c){
    int totalJogadoresAtivos = 0;

    float somaIdade = 0;
    float somaAltura = 0;

    int menorIdade = p->idade;
    int maiorIdade = p->idade;

    char jogadorMaisNovo[30];
    strcpy(jogadorMaisNovo, p->nome);

    char jogadorMaisVelho[30];
    strcpy(jogadorMaisVelho, p->nome);

    float menorAltura = p->altura;
    float maiorAltura = p->altura;

    char jogadorMaisBaixo[30];
    strcpy(jogadorMaisBaixo, p->nome);

    char jogadorMaisAlto[30];
    strcpy(jogadorMaisAlto, p->nome);

    for(int i=0; i < c; i++){
        if(p->ativo != 0){
            totalJogadoresAtivos++;
            somaIdade += p->idade;
            somaAltura += p->altura;

            if(p->idade < menorIdade){
                menorIdade = p->idade;
                strcpy(jogadorMaisNovo, p->nome);
            }

            if(p->idade > maiorIdade){
                maiorIdade = p->idade;
                strcpy(jogadorMaisVelho, p->nome);
            }

            if(p->altura < menorAltura){
                menorAltura = p->altura;
                strcpy(jogadorMaisBaixo, p->nome);
            }

            if(p->altura > maiorAltura){
                maiorAltura = p->altura;
                strcpy(jogadorMaisAlto, p->nome);
            }
        }
        p++;
    }

    if(totalJogadoresAtivos > 0){
        printf("Total de jogadores ativos: %d\n", totalJogadoresAtivos);
        printf("Media de idade: %.2f anos\n", somaIdade / totalJogadoresAtivos);
        printf("Media de altura: %.2fm\n", somaAltura / totalJogadoresAtivos);
        printf("Jogador mais novo: %s, com %d anos\n", jogadorMaisNovo, menorIdade);
        printf("Jogador mais velho: %s, com %d anos\n", jogadorMaisVelho, maiorIdade);
        printf("Jogador mais baixo: %s, com %.2fm\n", jogadorMaisBaixo, menorAltura);
        printf("Jogador mais alto: %s, com %.2fm\n", jogadorMaisAlto, maiorAltura);
    }
    else{
        printf("Nenhum jogador cadastrado!\n");
    }
    printf("\nPressione enter para voltar ao menu.\n");
    getchar();
    limpaTela();
}

void limpaTela(){
    system("cls || clear");
}