#include <stdio.h>
#include <stdlib.h>

void exitProgram()
{
    int opc;

    system("clear");
    printf("Tem certeza que deseja sair?.\n\n");
    printf("[1] - SIM\n[0] - NAO.\n\n");

    while (1)
    {
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("Saindo..\n");
            exit(0);
            break;
        case 0:
            return;
            break;
        default:
            printf("Opcao invalida, tente novamente.\n");
            break;
        }
    }
}

int main()
{
    int menu = 0;

    while (1)
    {
        system("clear");
        printf("Selecione uma opcao.\n\n");
        printf("Cadastro - 1\nRelatorios - 2\nSair - 3\n\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("Entrou no Cadastro\n");
            break;
        case 2:
            printf("Entrou no Relatorios.\n");
            break;
        case 3:
            printf("Entrou no Sair.\n");
            exitProgram();
            break;
        default:
            printf("Opcao invalida, tente novamente.\n");
            break;
        }
    }

    return (0);
}