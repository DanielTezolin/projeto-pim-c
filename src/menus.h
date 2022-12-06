#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*MENU TELAS*/

void mainMenu(void)
{
	setlocale(LC_ALL, ""); //Para acentuação
	printf("\033[2J\033[1;1H");

	printf("	      ========   Prote-g   ========\n\n");

	printf("    .____________________________________________________.\n");
	printf("    |                                                    |\n");
	printf("    |                   Menu principal                   |\n");
	printf("    |____________________________________________________|\n");
	printf("    |                                                    |\n");
	printf("    |       [1] - Menu de Usuários                       |\n");
  printf("    |       [2] - Menu de Colaboradores                  |\n");
  printf("    |       [3] - Menu de Clientes                       |\n");
	printf("    |       [4] - Menu de Relatorios                     |\n");
	printf("    |       [5] - Sair do Programa                       |\n");
	printf("    |                                                    |\n");
	printf("    |____________________________________________________|\n");
}

void usersMenu(void)
{
	setlocale(LC_ALL, ""); //Para acentuação
	printf("\033[2J\033[1;1H");

	printf("	      ========   Prote-g   ========\n\n");

	printf("    .____________________________________________________.\n");
	printf("    |                                                    |\n");
	printf("    |                   Menu Usuários                    |\n");
	printf("    |____________________________________________________|\n");
	printf("    |                                                    |\n");
	printf("    |       [1] - Lista de Usuários                      |\n");
  printf("    |       [2] - Buscar Usuários                        |\n");
  printf("    |       [3] - Excluir Usuários                       |\n");
	printf("    |       [4] - Cadastrar Usuários                     |\n");
	printf("    |       [5] - Voltar                                 |\n");
	printf("    |                                                    |\n");
	printf("    |____________________________________________________|\n");
}

void collaboratorsMenu(void)
{
	setlocale(LC_ALL, ""); //Para acentuação
	printf("\033[2J\033[1;1H");

	printf("	      ========   Prote-g   ========\n\n");

	printf("    .____________________________________________________.\n");
	printf("    |                                                    |\n");
	printf("    |                   Menu Colaboradores               |\n");
	printf("    |____________________________________________________|\n");
	printf("    |                                                    |\n");
	printf("    |       [1] - Lista de Colaboradores                 |\n");
  printf("    |       [2] - Buscar Colaborador                     |\n");
  printf("    |       [3] - Excluir Colaborador                    |\n");
	printf("    |       [4] - Cadastrar Colaborador                  |\n");
	printf("    |       [5] - Voltar                                 |\n");
	printf("    |                                                    |\n");
	printf("    |____________________________________________________|\n");
}

void clientsMenu(void)
{
	setlocale(LC_ALL, ""); //Para acentuação
	printf("\033[2J\033[1;1H");

	printf("	      ========   Prote-g   ========\n\n");

	printf("    .____________________________________________________.\n");
	printf("    |                                                    |\n");
	printf("    |                   Menu Clientes                    |\n");
	printf("    |____________________________________________________|\n");
	printf("    |                                                    |\n");
	printf("    |       [1] - Lista de Clientes                      |\n");
  printf("    |       [2] - Buscar Cliente                         |\n");
  printf("    |       [3] - Excluir Cliente                        |\n");
	printf("    |       [4] - Cadastrar Cliente                      |\n");
	printf("    |       [5] - Voltar                                 |\n");
	printf("    |                                                    |\n");
	printf("    |____________________________________________________|\n");
}