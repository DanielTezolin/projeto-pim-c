#include "./src/login.c"
#include "./src/menus.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void exitProgram(void);

void mainAccess(void);
void userAccess(void);

void usersMenu(void);
void mainMenu(void);

int main(void);

int main()
{
  setlocale(LC_ALL, "Portuguese");
  system("clear");
  // login();
  mainAccess();

  return (0);
}

void exitProgram()
{
  int opc;

  system("clear");
  printf("Tem certeza que deseja sair?.\n\n");
  printf("[1] - SIM\n[0] - NAO.\n\n");

  while (1)
  {
    scanf("%d", &opc);
    fflush(stdin);

    switch (opc)
    {
    case 1:
      printf("Saindo...\n");
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

void mainAccess()
{
  int menu = 0;

  system("clear");
  mainMenu();

  printf("\nSelecione uma opcao e pressione ENTER: ");
  scanf("%d", &menu);
  fflush(stdin);

  switch (menu)
  {
  case 1:
    userAccess();
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

void userAccess()
{
  int menu = 0;

  system("clear");
  /*---- Acesso ao menu de usuários ----*/
  usersMenu();

  printf("\nSelecione uma opcao e pressione ENTER: ");
  scanf("%d", &menu);
  fflush(stdin);

  switch (menu)
  {
  case 1:
    printf("Lista de Usuários .\n");
    break;
  case 2:
    printf("Buscar Usuários.\n");
    break;
  case 3:
    printf("Excluir Usuários.\n");
    break;
  case 4:
    printf("Cadastrar Usuários .\n");
    break;
  case 5:
    mainAccess();
    break;
  default:
    printf("Opcao invalida, tente novamente.\n");
    break;
  }
}