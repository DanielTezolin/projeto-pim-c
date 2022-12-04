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
void enterToContinue(void);

void mainAccess(void);
void userAccess(void);

void usersMenu(void);
void mainMenu(void);
void tratamento_cpf(char *tcpf, int tcpf_size);

void newUser(void);
void removeUser(void);
void listUser(void);
void searchUser(void);

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
    listUser();
    break;
  case 2:
    searchUser();
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

  userAccess();
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

  printf("usuário cadastrado com sucesso\n");
  enterToContinue();
  userAccess();
}

void removeUser()
{
  system("clear");

  FILE *file;
  FILE *file_temp;

  char cpf_busca[12];
  char linha_csv[216];

  user cusuario;

  file = fopen("data/users.csv", "r");

  if (file == NULL)
  {
    printf("\n\nErro ao abrir arquivo de usuários ou ainda nao foi realizado nenhum cadastro!");

    return;
  }

  file_temp = fopen("data/users_temp.csv", "a");

  if (file_temp == NULL)
  {
    printf("\n\nErro para criar arquivo temporário, não foi possível carregar essa função.");
    return;
  }

  printf("Para deletar um usuario, insira o CPF do usuario: ");
  scanf("%s", cpf_busca);

  int isExistUser = 0;

  char buffer[1024];

  int row = 0;
  int column = 0;

  while (fgets(buffer, 1024, file))
  {
    column = 0;
    row++;

    // Splitting a linha do csv
    char *value = strtok(buffer, ",");

    while (value)
    {
      // Column nome
      if (column == 0)
      {

        strcpy(cusuario.nome, value);
      }

      // Column cpf
      if (column == 1)
      {
        strcpy(cusuario.cpf, value);
      }

      // Column email
      if (column == 2)
      {
        strcpy(cusuario.email, value);
      }

      // Column senha
      if (column == 3)
      {
        strcpy(cusuario.senha, value);
      }

      // printf("Column: %d Value: %s\n", column, value);
      value = strtok(NULL, ",");
      column++;
    }

    // verificar o CPF inserido
    if (strcmp(cpf_busca, cusuario.cpf) != 0)
    {
      // printf("name: %s \n", cusuario.nome);
      fprintf(file_temp, "%s,%s,%s,%s", cusuario.nome, cusuario.cpf, cusuario.email, cusuario.senha);
    }
    else
    {
      isExistUser = 1;
      printf("Usuário selecionado => Nome: %s, CPF: %s, Email: %s\n", cusuario.nome, cusuario.cpf, cusuario.email);
    }
  }

  if (isExistUser == 0)
  {
    printf("Não foi encontrado nenhum usuário com o CPF: %s\n", cpf_busca);
    enterToContinue();
    userAccess();
    return;
  }

  fclose(file_temp);
  fclose(file);

  int opc;

  printf("Tem certeza que deseja excluir este usuário?.\n\n");
  printf("[1] - SIM\n[2] - NAO.\n\n");

  while (1)
  {
    scanf("%d", &opc);
    fflush(stdin);

    switch (opc)
    {
    case 1:
      if (remove("data/users.csv") != 0)
      {
        printf(" Rua excluir banco de dados antigos.  Não foi possível concluir a operação\n");
        exit(1);
        return;
      }

      if (rename("data/users_temp.csv", "data/users.csv") != 0)
      {
        printf("Erro para nomear novo banco de dados.  Não foi possível concluir a operação\n");
        exit(1);
        return;
      }

      userAccess();
      return;
      break;
    case 2:
      if (remove("data/users_temp.csv") != 0)
      {
        printf(" Rua excluir banco de dados antigos.  Não foi possível concluir a operação\n");
        exit(1);
        return;
      }

      userAccess();
      return;
      break;
    default:
      printf("Opcao invalida, tente novamente.\n");
      break;
    }

    return;
  }

  enterToContinue();
  userAccess();
}

void searchUser()
{
  system("clear");

  FILE *file;

  char cpf_busca[12];
  char linha_csv[216];

  user cusuario;

  file = fopen("data/users.csv", "r");

  if (file == NULL)
  {
    printf("\n\nErro ao abrir arquivo de usuários ou ainda nao foi realizado nenhum cadastro!");

    return;
  }

  printf("Para buscar um usuario, insira o CPF: ");
  scanf("%s", cpf_busca);
  fflush(stdin);

  char buffer[1024];

  int row = 0;
  int column = 0;

  while (fgets(buffer, 1024, file))
  {
    column = 0;
    row++;

    // Splitting a linha do csv
    char *value = strtok(buffer, ",");

    while (value)
    {
      // Column nome
      if (column == 0)
      {
        strcpy(cusuario.nome, value);
      }

      // Column cpf
      if (column == 1)
      {
        strcpy(cusuario.cpf, value);
      }

      // Column email
      if (column == 2)
      {
        strcpy(cusuario.email, value);
      }

      // Column senha
      if (column == 3)
      {
        strcpy(cusuario.senha, value);
      }

      // printf("Column: %d Value: %s\n", column, value);
      value = strtok(NULL, ",");
      column++;
    }

    // verificar o CPF inserido
    if (strcmp(cpf_busca, cusuario.cpf) == 0)
    {
      printf("Usuário selecionado => Nome: %s, CPF: %s, Email: %s\n", cusuario.nome, cusuario.cpf, cusuario.email);
    }
  }

  fclose(file);

  enterToContinue();
  userAccess();
}

void listUser()
{
  system("clear");

  FILE *file;

  char linha_csv[216];
  char exitFun[1];

  user list_user;

  file = fopen("data/users.csv", "r");

  if (file == NULL)
  {
    printf("\n\nErro ao abrir arquivo de usuários ou ainda nao foi realizado nenhum cadastro!");

    return;
  }

  char buffer[1024];

  int row = 0;
  int column = 0;

  while (fgets(buffer, 1024, file))
  {
    column = 0;
    row++;

    if (row == 1)
      continue;

    // Splitting a linha do csv
    char *value = strtok(buffer, ",");

    while (value)
    {
      // Column nome
      if (column == 0)
      {
        strcpy(list_user.nome, value);
      }

      // Column cpf
      if (column == 1)
      {
        strcpy(list_user.cpf, value);
      }

      // Column email
      if (column == 2)
      {
        strcpy(list_user.email, value);
      }

      // Column senha
      if (column == 3)
      {
        strcpy(list_user.senha, value);
      }

      // printf("Column: %d Value: %s\n", column, value);
      value = strtok(NULL, ",");
      column++;
    }

    printf("Nome: %s, CPF: %s, Email: %s\n\n", list_user.nome, list_user.cpf, list_user.email);
  }

  fclose(file);
  enterToContinue();
  userAccess();
}

void enterToContinue()
{
  printf("Pressione enter para voltar\n");
  char enter = 0;
  while (enter != '\r' && enter != '\n')
  {
    enter = getchar();
  }
}