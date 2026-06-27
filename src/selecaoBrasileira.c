/*
        Projeto Seleção Brasileira
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
void editarJogador(Jogador *p, int c);
void pesquisarJogador(Jogador *p, int c);
void excluirJogador(Jogador *p, int c);
void estatisticas(Jogador *p, int c);
void limpaTela();
void limpaBuffer();

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
        limpaBuffer();

        switch(menu){
            case 0:
                printf("Saindo...");
                break;
            case 1:
                limpaTela();
                if(contadorJogadores < QNT_JOGADORES){
                    selecao[contadorJogadores] = inserirJogador(&selecao[0], contadorJogadores);
                    contadorJogadores++;
                }
                else {
                    printf("Lista de jogadores cheia!\n\n");
                }
                break;
            case 2:
                limpaTela();
                listarJogadores(&selecao[0], contadorJogadores);
                break;
            case 3:
                limpaTela();
                editarJogador(&selecao[0], contadorJogadores);
                break;
            case 4:
                limpaTela();
                excluirJogador(&selecao[0], contadorJogadores);
                break;
            case 5:
                limpaTela();
                pesquisarJogador(&selecao[0], contadorJogadores);
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

    return 0;
}

Jogador inserirJogador(Jogador *p, int c){   
    Jogador j;
    Jogador *pAux = p;
    int camisaIgual = 0;

    printf("Nome do jogador: ");
    fgets(j.nome, sizeof(j.nome), stdin);
    j.nome[strcspn(j.nome, "\n")] = '\0';

    do{
        p = pAux;
        do{
            printf("Numero da camisa: ");
            scanf("%d", &j.numCamisa);

            if(j.numCamisa < 1 || j.numCamisa > QNT_JOGADORES){
                printf("Numero de camisa invalido! Digite um numero entre 1 e %d.\n\n", QNT_JOGADORES);
            }
        } while(j.numCamisa < 1 || j.numCamisa > QNT_JOGADORES);

        for(int i=0; i < c; i++){
            if(j.numCamisa == p->numCamisa){    // Não da pra usar a camisa de um jogador inativo
                printf("Camisa ja cadastrada!\n");
                printf("Jogador com a camisa %d: %s\n\n", p->numCamisa, p->nome);
                camisaIgual = 1;
                break;
            }
            else {
                camisaIgual = 0;
            }
            p++;
        }
    } while(camisaIgual == 1);

    do{
        printf("Idade: ");
        scanf("%d", &j.idade);

        if(j.idade < 15){
            printf("Idade invalida! Nao sao convocados jogadores menores de 15 anos!\n");
        }
        if(j.idade > 60){
            printf("O jogador ja deveria ter se aposentado! Apenas jogadores mais novos que 60 anos!\n");
        }
    } while(j.idade < 15 || j.idade > 60);

    do{
        printf("Altura(em metros): ");
        scanf("%f", &j.altura);

        if(j.altura < 1.3){
            printf("Impossivel que alguem menor que 1.30m seja um jogador profissional de futebol!\n");
        }

        if(j.altura > 2.4){
            printf("Parece que voce se confundiu com a convocacao do basquete! Ate 2.40m! \n");
        }
    } while(j.altura < 1.3 || j.altura > 2.4);

    printf("Posicao(texto): ");
    limpaBuffer();
    fgets(j.posicao, sizeof(j.posicao), stdin);
    j.posicao[strcspn(j.posicao, "\n")] = '\0';

    printf("Time: ");
    fgets(j.time, sizeof(j.time), stdin);
    j.time[strcspn(j.time, "\n")] = '\0';

    j.ativo = 1;

    printf("\nJogador inserido com sucesso!\n");
    printf("\nPressione enter para voltar ao menu.\n");
    getchar();
    limpaTela();

    return j;
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
    printf("\nNome: %s\n", p->nome);
    printf("Numero da camisa: %d\n", p->numCamisa);
    printf("Idade: %d anos\n", p->idade);
    printf("Altura: %.2fm\n", p->altura);
    printf("Posicao: %s\n", p->posicao);
    printf("Time: %s\n", p->time);
}

void editarJogador(Jogador *p, int c){
    Jogador *pOriginal = p;
    Jogador *pAux = p;
    int camisa, trocarCamisa, novaCamisa, camisaIgual = 0;
    printf("Digite o numero da camisa do jogador que voce deseja editar: ");
    scanf("%d", &camisa);

    for(int i=0; i < c; i++){
        if(p->numCamisa == camisa && p->ativo == 1){
            printf("\nJogador encontrado! Editando...\n\n");
            printf("Nome do jogador: ");
            limpaBuffer();
            fgets(p->nome, sizeof(p->nome), stdin);
            p->nome[strcspn(p->nome, "\n")] = '\0';

            do{
                printf("Voce deseja alterar o numero da camisa? (digite 1 para sim, 0 para nao): ");
                scanf("%d", &trocarCamisa);
                limpaBuffer();
                if(trocarCamisa < 0 || trocarCamisa > 1){
                    printf("Digite um numero valido!\n");
                }
            } while(trocarCamisa < 0 || trocarCamisa > 1);

            if(trocarCamisa == 1){
                do{
                    pAux = pOriginal;
                    do{
                        printf("Numero da camisa: ");
                        scanf("%d", &novaCamisa);

                        if(novaCamisa < 1 || novaCamisa > QNT_JOGADORES){
                            printf("Numero de camisa invalido! Digite um numero entre 1 e %d.\n", QNT_JOGADORES);
                        }
                    } while(novaCamisa < 1 || novaCamisa > QNT_JOGADORES);

                    for(int i=0; i < c; i++){
                        if(novaCamisa == pAux->numCamisa && novaCamisa != p->numCamisa){
                            printf("Camisa ja cadastrada!\n");
                            camisaIgual = 1;
                            break;
                        }
                        else {
                            camisaIgual = 0;
                        }
                        pAux++;
                    }
                } while(camisaIgual == 1);

                p->numCamisa = novaCamisa;
            }

            do{
                printf("Idade: ");
                scanf("%d", &p->idade);

                if(p->idade < 15){
                    printf("Idade invalida! Nao sao convocados jogadores menores de 15 anos!\n");
                }

                if(p->idade > 60){
                    printf("O jogador ja deveria ter se aposentado! Apenas jogadores mais novos que 60 anos!\n");
                }
            } while(p->idade < 15 || p->idade > 60);

            do{
                printf("Altura(em metros): ");
                scanf("%f", &p->altura);

                if(p->altura < 1.3){
                    printf("Impossivel que alguem menor que 1.30m seja um jogador profissional de futebol!\n");
                }

                if(p->altura > 2.4){
                    printf("Parece que voce se confundiu com a convocacao do basquete! Ate 2.40m! \n");
                }
            } while(p->altura < 1.3 || p->altura > 2.4);

            printf("Posicao(texto): ");
            limpaBuffer();
            fgets(p->posicao, sizeof(p->posicao), stdin);
            p->posicao[strcspn(p->posicao, "\n")] = '\0';

            printf("Time: ");
            fgets(p->time, sizeof(p->time), stdin);
            p->time[strcspn(p->time, "\n")] = '\0';

            p->ativo = 1;

            printf("\nJogador editado com sucesso!\n");
            printf("\nPressione enter para voltar ao menu.\n");
            getchar();
            limpaTela();
            return;
        }
        p++;
    }
    printf("Jogador nao encontrado!\n\n");
}

void pesquisarJogador(Jogador *p, int c){
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

        if(menu < 0 || menu > 6){
            printf("Opcao Invalida! Digite uma opcao valida.\n\n");
        }
    } while(menu < 0 || menu > 6);

    switch(menu){
        case 0:
            printf("Retornando ao menu principal...\n\n");
            break;
        case 1:
            printf("Digite o nome: ");
            limpaBuffer();
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            for(int i=0; i < c; i++){
                if(strstr(p->nome, nome) != NULL && p->ativo == 1){
                    exibirJogador(p);
                    jogadorEncontrado = 1;
                }
                p++;
            }
            break;
        case 2:
            printf("Digite o numero da camisa: ");
            scanf("%d", &numCamisa);
            limpaBuffer();

            for(int i=0; i < c; i++){
                if(p->numCamisa == numCamisa && p->ativo == 1){
                    exibirJogador(p);
                    jogadorEncontrado = 1;
                }
                p++;
            }
            break;
        case 3:
            printf("Digite a idade: ");
            scanf("%d", &idade);
            limpaBuffer();

            for(int i=0; i < c; i++){
                if(p->idade == idade && p->ativo == 1){
                    exibirJogador(p);
                    jogadorEncontrado = 1;
                }
                p++;
            }
            break;
        case 4:
            printf("Digite a altura(em metros): ");
            scanf("%f", &altura);
            limpaBuffer();

            for(int i=0; i < c; i++){
                if(p->altura == altura && p->ativo == 1){
                    exibirJogador(p);
                    jogadorEncontrado = 1;
                }
                p++;
            }
            break;
        case 5:
            printf("Digite a posicao(texto): ");
            limpaBuffer();
            fgets(posicao, sizeof(posicao), stdin); 
            posicao[strcspn(posicao, "\n")] = '\0';

            for(int i=0; i < c; i++){
                if(strstr(p->posicao, posicao) != NULL && p->ativo == 1){
                    exibirJogador(p);
                    jogadorEncontrado = 1;
                }
                p++;
            }
            break;
        case 6:
            printf("Digite o time: ");
            limpaBuffer();
            fgets(time, sizeof(time), stdin);
            time[strcspn(time, "\n")] = '\0';

            for(int i=0; i < c; i++){   
                if(strstr(p->time, time) != NULL && p->ativo == 1){
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
        printf("\nJogador nao encontrado para essa pesquisa!\n\n");
    }
    if(menu != 0){
        printf("\nPressione enter para voltar ao menu.\n");
        getchar();
    }
    limpaTela();
}

void excluirJogador(Jogador *p, int c){
    int camisa;
    printf("Digite o numero da camisa do jogador a ser excluido: ");
    scanf("%d", &camisa);

    for(int i=0; i < c; i++){
        if(p->numCamisa == camisa && p->ativo == 1){
            p->ativo = 0;
            printf("\nJogador excluido com sucesso!\n\n");
            return;
        }
        p++;
    }
    printf("\nJogador nao encontrado!\n\n");
}

void estatisticas(Jogador *p, int c){
    int totalJogadoresAtivos = 0;
    float somaIdade = 0, somaAltura = 0;

    int menorIdade = 0, maiorIdade = 0;
    float menorAltura = 0, maiorAltura = 0;

    char jogadorMaisNovo[30];
    strcpy(jogadorMaisNovo, "");
    char jogadorMaisVelho[30];
    strcpy(jogadorMaisVelho, "");

    char jogadorMaisBaixo[30];
    strcpy(jogadorMaisBaixo, "");
    char jogadorMaisAlto[30];
    strcpy(jogadorMaisAlto, "");

    Jogador *pAux = p;
    int primeiroAtivo = -1;

    for(int i=0; i < c; i++){
        if(p->ativo != 0){
            primeiroAtivo = i;
            break;
        }
        p++;
    }

    if(primeiroAtivo == -1){
        printf("Nenhum jogador cadastrado!\n");
        printf("\nPressione enter para voltar ao menu.\n");
        getchar();
        limpaTela();
        return;
    }

    menorIdade = p->idade;
    maiorIdade = p->idade;
    
    strcpy(jogadorMaisNovo, p->nome);
    strcpy(jogadorMaisVelho, p->nome);

    menorAltura = p->altura;
    maiorAltura = p->altura;

    strcpy(jogadorMaisBaixo, p->nome);
    strcpy(jogadorMaisAlto, p->nome);

    p = pAux;

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

    printf("Total de jogadores ativos: %d\n", totalJogadoresAtivos);
    printf("Media de idade: %.2f anos\n", somaIdade / totalJogadoresAtivos);
    printf("Media de altura: %.2fm\n", somaAltura / totalJogadoresAtivos);
    printf("Jogador mais novo: %s, com %d anos\n", jogadorMaisNovo, menorIdade);
    printf("Jogador mais velho: %s, com %d anos\n", jogadorMaisVelho, maiorIdade);
    printf("Jogador mais baixo: %s, com %.2fm\n", jogadorMaisBaixo, menorAltura);
    printf("Jogador mais alto: %s, com %.2fm\n", jogadorMaisAlto, maiorAltura);

    printf("\nPressione enter para voltar ao menu.\n");
    getchar();
    limpaTela();
}

void limpaTela(){
    system("cls || clear");
}

void limpaBuffer(){
    int c;
    do{
        c = getchar();
    } while(c != '\n' && c != EOF);
}