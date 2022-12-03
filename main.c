#include "./src/login.c"
#include "./src/menus.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*- Estrutura do usuário*/
typedef struct
{
  char nome[52];
  char email[100];
  char cpf[12];
  char senha[52];
} user;

void exitProgram(void);

void mainAccess(void);
void userAccess(void);

void usersMenu(void);
void mainMenu(void);
void tratamento_cpf(char *tcpf, int tcpf_size);

void newUser(void);
void removeUser(void);

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
    removeUser();
    break;
  case 4:
    newUser();
    break;
  case 5:
    mainAccess();
    break;
  default:
    printf("Opcao invalida, tente novamente.\n");
    break;
  }

  // userAccess();
}

void newUser()
{
  FILE *file;
  file = fopen("data/users.csv", "a");

  if (file == NULL)
  {
    printf("\n\nErro ao abrir arquivo de usuários ou ainda nao foi realizado nenhum cadastro!");

    return;
  }

  user user_cad;

  printf("\n\nNome do usuário: \n");
  scanf("%s", user_cad.nome);
  fflush(stdin);

  printf("\n\nCPF do usuário: \n");
  scanf("%s", user_cad.cpf);
  fflush(stdin);

  printf("\n\nEmail do usuário: \n");
  scanf("%s", user_cad.email);
  fflush(stdin);

  printf("\n\nSenha do usuário: \n");
  scanf("%s", user_cad.senha);
  fflush(stdin);

  printf("Nome: %s - CPF: %s - Email: %s  \n", user_cad.nome, user_cad.cpf, user_cad.email);

  fprintf(file, "%s,%s,%s,%s\n", user_cad.nome, user_cad.cpf, user_cad.email, user_cad.senha);
  fclose(file);

  return;
}

void removeUser()
{
  printf("\n\nteste\n");
  FILE *file;
  FILE *file_temp;

  char cpf_busca[12];
  user cusuario;

  file = fopen("data/users.csv", "r");

  if (file == NULL)
  {
    printf("\n\nErro ao abrir arquivo de usuários ou ainda nao foi realizado nenhum cadastro!");

    return;
  }

  file_temp = fopen("data/users_temp.csv", "w");

  if (file == NULL)
  {
    printf("\n\nErro para criar arquivo temporário, não foi possível carregar essa função.");
    return;
  }

  // printf("Para deletar um usuario, insira o CPF do usuario: ");
  // scanf("%s", cpf_busca);

  while (fscanf(file, "%[^,],%[^,],%[^,],%[^,]\n", cusuario.nome, cusuario.cpf, cusuario.email, cusuario.senha) == EOF)
  {
    printf("nao excluir => %s-%s-%s-%s\n", cusuario.nome, cusuario.cpf, cusuario.email, cusuario.senha);
    // if (strcmp(cpf_busca, cusuario.cpf) != 0)
    // {
    //   printf("3 %s\n", cusuario.nome);
    //   printf("nao excluir => %s-%s-%s-%s\n", cusuario.nome, cusuario.cpf, cusuario.email, cusuario.senha);
    // }
    // else
    // {
    //   printf("excluir => %s,%s,%s,%s\n", cusuario.nome, cusuario.cpf, cusuario.email, cusuario.senha);
    // }
  }

  fclose(file_temp);
  fclose(file);
}