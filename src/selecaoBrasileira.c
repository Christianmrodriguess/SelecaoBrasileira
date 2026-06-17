/*
        Projeto Selecao Brasileira
Integrantes do projeto: Christian, Gabriel e José Elias

*/
#include <stdio.h>

#define QNT_JOGADORES 26

jogador inserirJogador();
void listarJogadores(jogador *p);

typedef struct{
    char nome[30];
    int idade;
    float altura;
    int numCamisa;
    char posicao[20];
    char time[50];
    int ativo;
    
}jogador;

int main()
{
    jogador selecao[QNT_JOGADORES];
    int menu = 1;
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
        
        switch(menu)
        {
        case 1:
            //inserir();
            break;
        
        case 2:
            //listar();
            break;
        case 3:
            //editar();
            break;
        case 4:
            //excluir();
            break;
        case 5:
            //pesquisar();
            break;
        case 6:
            //resumo();
            break;
        case 0:
            printf("Saindo...");
            break;
        default:
            printf("Opcao Invalida! Digite uma opcao valida. \n");
        }
    }while(menu != 0);
}

jogador inserirJogador(){

}


void listarJogadores(jogador *p){
    for(int i=0; i < QNT_JOGADORES; i++){
        if(*p.ativo != 0){
            printf("Nome: %s \n", *p.nome);
            printf("Idade: %d \n", *p.idade);
            printf("Altura: %.2f \n", *p.altura);
            printf("Numero da camisa: %d \n", *p.numCamisa);
            printf("Posicao: %s \n", *p.posicao);
            printf("Time: %s \n\n\n", *p.time);
        }

        p++;
    }
}
