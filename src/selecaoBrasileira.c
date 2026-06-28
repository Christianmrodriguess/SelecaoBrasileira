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
int verificaAtivo(Jogador *p, int c);
void exibirJogador(Jogador *p);
void editarJogador(Jogador *p, int c);
int verificaCamisa(int camisa, Jogador *p, int c);
void pesquisarJogador(Jogador *p, int c);
void excluirJogador(Jogador *p, int c);
void estatisticas(Jogador *p, int c);
void limpaTela();
void limpaBuffer();
void populaVetor(Jogador *p, int *c);

int main()
{
    Jogador selecao[QNT_JOGADORES];
    int menu = 1, contadorJogadores = 0;

    for(int i = 0; i< QNT_JOGADORES; i++){
        strcpy(selecao[i].nome, "");
        selecao[i].numCamisa = 0;
        selecao[i].idade = 0;
        selecao[i].altura = 0;
        strcpy(selecao[i].posicao, "");
        strcpy(selecao[i].time, "");
        selecao[i].ativo = 0;
    }

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
                if(contadorJogadores > 0 && verificaAtivo(&selecao[0], contadorJogadores) != -1){
                    listarJogadores(&selecao[0], contadorJogadores);
                }
                else{
                    printf("Nenhum jogador cadastrado!\n");
                    printf("\nPressione enter para voltar ao menu.\n");
                    getchar();
                }
                break;
            case 3:
                limpaTela();
                if(contadorJogadores > 0 && verificaAtivo(&selecao[0], contadorJogadores) != -1){
                    editarJogador(&selecao[0], contadorJogadores);
                    
                    
                }
                else{
                    printf("Nenhum jogador cadastrado!\n");
                    printf("\nPressione enter para voltar ao menu.\n");
                    getchar();
                }
                break;
            case 4:
                limpaTela();
                if(contadorJogadores > 0 && verificaAtivo(&selecao[0], contadorJogadores) != -1){
                    excluirJogador(&selecao[0], contadorJogadores);
                }
                else{
                    printf("Nenhum jogador cadastrado!\n");
                    printf("\nPressione enter para voltar ao menu.\n");
                    getchar();
                }
                break;
            case 5:
                limpaTela();
                if(contadorJogadores > 0 && verificaAtivo(&selecao[0], contadorJogadores) != -1){
                    pesquisarJogador(&selecao[0], contadorJogadores);
                }
                else{
                    printf("Nenhum jogador cadastrado!\n");
                    printf("\nPressione enter para voltar ao menu.\n");
                    getchar();
                }
                break;
            case 6:
                limpaTela();
                if(contadorJogadores > 0 && verificaAtivo(&selecao[0], contadorJogadores) != -1){
                    estatisticas(&selecao[0], contadorJogadores);
                }
                else{
                    printf("Nenhum jogador cadastrado!\n");
                    printf("\nPressione enter para voltar ao menu.\n");
                    getchar();
                }
                break;
            //funcao escondida no menu para popular o vetor para facilitar
            case 11:
                limpaTela();
                populaVetor(&selecao[0], &contadorJogadores);
                printf("Vetor populado com 11 jogadores!\n");
                printf("\nPressione enter para voltar ao menu.\n");
                getchar();
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
    int idCamisa;

    printf("Nome do jogador: ");
    fgets(j.nome, sizeof(j.nome), stdin);
    j.nome[strcspn(j.nome, "\n")] = '\0';

    do{
        do{
            printf("Numero da camisa: ");
            scanf("%d", &j.numCamisa);

            if(j.numCamisa < 1 || j.numCamisa > QNT_JOGADORES){
                printf("Numero de camisa invalido! Digite um numero entre 1 e %d.\n\n", QNT_JOGADORES);
            }
        } while(j.numCamisa < 1 || j.numCamisa > QNT_JOGADORES);

        idCamisa = verificaCamisa(j.numCamisa, p, c);

        //Não pode pra usar a camisa de um jogador inativo
        if(idCamisa != -1){    
            printf("Camisa nao pode ser usada!\n");
            if(p[idCamisa].ativo == 1)
                printf("Jogador com a camisa %d: %s\n\n", p[idCamisa].numCamisa, p[idCamisa].nome);    
        }
    } while(idCamisa != -1);

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
int verificaAtivo(Jogador *p, int c){
    for(int i=0; i < c; i++){
        if(p[i].ativo != 0){
            return i;
        }
    }
    return -1;
}

void listarJogadores(Jogador *p, int c){
    //retorna todos os jogadores ativos na lista
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
    int camisa, trocarCamisa, novaCamisa, camisaIgual, idCamisa;
    do{
        printf("Digite o numero da camisa do jogador que voce deseja editar: ");
        scanf("%d", &camisa);

        if(camisa < 1 || camisa > QNT_JOGADORES){
            printf("Numero de camisa invalido! Digite um numero entre 1 e %d.\n", QNT_JOGADORES);
        }
    } while(camisa < 1 || camisa > QNT_JOGADORES);

    //verificaCamisa retorna o indice no vetor que tem a camisa que o usuario digitou, caso nao tem eh retornado o valor -1
    idCamisa = verificaCamisa(camisa, p, c); 
    
    //se existir a camisa e o jogador estiver ativo, comeca a edicao do jogador
    if(idCamisa != -1 && p[idCamisa].ativo == 1){
        printf("\nJogador encontrado! Editando...\n\n");
        printf("Nome do jogador: ");
        limpaBuffer();
        fgets(p[idCamisa].nome, sizeof(p[idCamisa].nome), stdin);
        p[idCamisa].nome[strcspn(p[idCamisa].nome, "\n")] = '\0';

        do{
                printf("Voce deseja alterar o numero da camisa? (digite 1 para sim, 0 para nao): ");
                scanf("%d", &trocarCamisa);
                limpaBuffer();
                if(trocarCamisa < 0 || trocarCamisa > 1){
                    printf("Digite um numero valido!\n");
                }
            } while(trocarCamisa < 0 || trocarCamisa > 1);
            //se o usuario desejar trocar a camisa
            if(trocarCamisa == 1){
                do{
                    do{
                        printf("Numero da camisa: ");
                        scanf("%d", &novaCamisa);

                        if(novaCamisa < 1 || novaCamisa > QNT_JOGADORES){
                            printf("Numero de camisa invalido! Digite um numero entre 1 e %d.\n", QNT_JOGADORES);
                        }
                    } while(novaCamisa < 1 || novaCamisa > QNT_JOGADORES);
                    //verificaCamisa retorna o indice no vetor que tem a camisa que o usuario digitou, caso nao tem eh retornado o valor -1
                    camisaIgual = verificaCamisa(novaCamisa, p, c);
        
                    if(camisaIgual != -1 && camisaIgual != idCamisa){
                        printf("Camisa ja cadastrada!\n");
                    }
                } while(camisaIgual != -1 && camisaIgual != idCamisa); //vai se repetir enquanto o usuario digitar uma camisa ja cadastrada que nao seja a do proprio jogador sendo editado

                p[idCamisa].numCamisa = novaCamisa;
            }

            do{
                printf("Idade: ");
                scanf("%d", &p[idCamisa].idade);

                if(p[idCamisa].idade < 15){
                    printf("Idade invalida! Nao sao convocados jogadores menores de 15 anos!\n");
                }

                if(p[idCamisa].idade > 60){
                    printf("O jogador ja deveria ter se aposentado! Apenas jogadores mais novos que 60 anos!\n");
                }
            } while(p[idCamisa].idade < 15 || p[idCamisa].idade > 60);

            do{
                printf("Altura(em metros): ");
                scanf("%f", &p[idCamisa].altura);

                if(p[idCamisa].altura < 1.3){
                    printf("Impossivel que alguem menor que 1.30m seja um jogador profissional de futebol!\n");
                }

                if(p[idCamisa].altura > 2.4){
                    printf("Parece que voce se confundiu com a convocacao do basquete! Ate 2.40m! \n");
                }
            } while(p[idCamisa].altura < 1.3 || p[idCamisa].altura > 2.4);

            printf("Posicao(texto): ");
            limpaBuffer();
            fgets(p[idCamisa].posicao, sizeof(p[idCamisa].posicao), stdin);
            p[idCamisa].posicao[strcspn(p[idCamisa].posicao, "\n")] = '\0';

            printf("Time: ");
            fgets(p[idCamisa].time, sizeof(p[idCamisa].time), stdin);
            p[idCamisa].time[strcspn(p[idCamisa].time, "\n")] = '\0';

            printf("\nJogador editado com sucesso!\n");
            printf("\nPressione enter para voltar ao menu.\n");
            getchar();
            limpaTela();
    }
    else
        printf("Jogador nao encontrado!\n\n");
}

int verificaCamisa(int camisa, Jogador *p, int c){
    //verificaCamisa retorna o indice no vetor que tem a camisa que o usuario digitou, caso nao tem eh retornado o valor -1
    for(int i=0; i < c; i++){
        if(p[i].numCamisa == camisa)
        {
            return i;
        }
    }
    return -1;
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

    //menu de pesquisa
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
    do{
        printf("Digite o numero da camisa do jogador a ser excluido: ");
        scanf("%d", &camisa);
        limpaBuffer();

        if(camisa < 1 || camisa > QNT_JOGADORES){
            printf("Numero de camisa invalido! Digite um numero entre 1 e %d.\n", QNT_JOGADORES);
        }
    } while(camisa < 1 || camisa > QNT_JOGADORES);

    for(int i=0; i < c; i++){
        if(p[i].numCamisa == camisa && p[i].ativo == 1){
            p[i].ativo = 0;
            printf("\nJogador excluido com sucesso!\n\n");
            printf("\nPressione enter para voltar ao menu.\n");
            getchar();
            limpaTela();
            return;
        }
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

    //pega o primeiro indice ativo do vetor
    int primeiroAtivo = verificaAtivo(p, c);

    
    //se nao tiver nenhum indice ativo ja sai da funcao e retorna que nao ha jogador cadastrado
    if(primeiroAtivo == -1){
        printf("Nenhum jogador cadastrado!\n");
        printf("\nPressione enter para voltar ao menu.\n");
        getchar();
        limpaTela();
        return;
    }

    menorIdade = p[primeiroAtivo].idade;
    maiorIdade = p[primeiroAtivo].idade;
    
    strcpy(jogadorMaisNovo, p[primeiroAtivo].nome);
    strcpy(jogadorMaisVelho, p[primeiroAtivo].nome);

    menorAltura = p[primeiroAtivo].altura;
    maiorAltura = p[primeiroAtivo].altura;

    strcpy(jogadorMaisBaixo, p[primeiroAtivo].nome);
    strcpy(jogadorMaisAlto, p[primeiroAtivo].nome);

    for(int i=0; i < c; i++){
        if(p[i].ativo != 0){
            totalJogadoresAtivos++;
            somaIdade += p[i].idade;
            somaAltura += p[i].altura;

            if(p[i].idade < menorIdade){
                menorIdade = p[i].idade;
                strcpy(jogadorMaisNovo, p[i].nome);
            }

            if(p[i].idade > maiorIdade){
                maiorIdade = p[i].idade;
                strcpy(jogadorMaisVelho, p[i].nome);
            }

            if(p[i].altura < menorAltura){
                menorAltura = p[i].altura;
                strcpy(jogadorMaisBaixo, p[i].nome);
            }

            if(p[i].altura > maiorAltura){
                maiorAltura = p[i].altura;
                strcpy(jogadorMaisAlto, p[i].nome);
            }
        }
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

void populaVetor(Jogador *p, int *c){
    //so pra facilitar caso quiser o vetor com alguns dados
    strcpy(p[0].nome, "Alisson");
    p[0].numCamisa = 1;
    p[0].idade = 29;
    p[0].altura = 1.91;
    strcpy(p[0].posicao, "Goleiro");
    strcpy(p[0].time, "Liverpool");
    p[0].ativo = 1;
    
    strcpy(p[1].nome, "Ederson");
    p[1].numCamisa = 2;
    p[1].idade = 26;
    p[1].altura = 1.83;
    strcpy(p[1].posicao, "Meia Central");
    strcpy(p[1].time, "Atalanta");
    p[1].ativo = 1;
    
    strcpy(p[2].nome, "Gabriel Magalhaes");
    p[2].numCamisa = 3;
    p[2].idade = 28;
    p[2].altura = 1.88;
    strcpy(p[2].posicao, "Zagueiro");
    strcpy(p[2].time, "Arsenal");
    p[2].ativo = 1;
    
    strcpy(p[3].nome, "Marquinhos");
    p[3].numCamisa = 4;
    p[3].idade = 32;
    p[3].altura = 1.83;
    strcpy(p[3].posicao, "Zagueiro");
    strcpy(p[3].time, "PSG");
    p[3].ativo = 1;
    
    strcpy(p[4].nome, "Casemiro");
    p[4].numCamisa = 5;
    p[4].idade = 34;
    p[4].altura = 1.83;
    strcpy(p[4].posicao, "Volante");
    strcpy(p[4].time, "Manchester United");
    p[4].ativo = 1;
    
    strcpy(p[5].nome, "Alex Sandro");
    p[5].numCamisa = 6;
    p[5].idade = 35;
    p[5].altura = 1.80;
    strcpy(p[5].posicao, "Lat Esquerdo");
    strcpy(p[5].time, "Flamengo");
    p[5].ativo = 1;
    
    strcpy(p[6].nome, "Vinicius Jr.");
    p[6].numCamisa = 7;
    p[6].idade = 25;
    p[6].altura = 1.76;
    strcpy(p[6].posicao, "Ponta Esquerda");
    strcpy(p[6].time, "Real Madrid");
    p[6].ativo = 1;
    
    strcpy(p[7].nome, "Bruno Guimaraes");
    p[7].numCamisa = 8;
    p[7].idade = 28;
    p[7].altura = 1.82;
    strcpy(p[7].posicao, "Meia Central");
    strcpy(p[7].time, "Newcastle");
    p[7].ativo = 1;
    
    strcpy(p[8].nome, "Matheus Cunha");
    p[8].numCamisa = 9;
    p[8].idade = 27;
    p[8].altura = 1.83;
    strcpy(p[8].posicao, "Centroavante");
    strcpy(p[8].time, "Manchester United");
    p[8].ativo = 1;
    
    strcpy(p[9].nome, "Neymar");
    p[9].numCamisa = 10;
    p[9].idade = 34;
    p[9].altura = 1.75;
    strcpy(p[9].posicao, "Meia Ofensivo");
    strcpy(p[9].time, "Santos");
    p[9].ativo = 1;
    
    strcpy(p[10].nome, "Raphinha");
    p[10].numCamisa = 11;
    p[10].idade = 29;
    p[10].altura = 1.76;
    strcpy(p[10].posicao, "Ponta Direita");
    strcpy(p[10].time, "Barcelona");
    p[10].ativo = 1;

    *c = 11;

    for(int i = *c; i< QNT_JOGADORES; i++){
        strcpy(p[i].nome, "");
        p[i].numCamisa = 0;
        p[i].idade = 0;
        p[i].altura = 0;
        strcpy(p[i].posicao, "");
        strcpy(p[i].time, "");
        p[i].ativo = 0;
    }
}