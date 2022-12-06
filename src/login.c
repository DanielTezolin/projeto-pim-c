#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*- Estrutura de login*/
typedef struct
{
  char password[52];
  char email[100];
} elogin;

int emailIsValid(char email[100])
{
  int tam = strlen(email);
  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

  for (i = 0; i < tam; i++)
  {
    char c = email[i];
    if (c == '@')
    {
      if (arroba)
        break; // não pode ter uma segunda @
      arroba = 1;
      if (i < 3)
        break; // se @ vier antes de 3 caracteres, erro
    }
    else if (arroba)
    { // se já encontrou @
      if (ponto)
      { // se já encontrou . depois de @
        depoisPonto++;
      }
      else if (c == '.')
      {
        ponto = 1;
        if (antesPonto < 3)
        {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      }
      else
      {
        antesPonto++;
      }
    }
  } // for

  if (i == tam && depoisPonto > 1)
    return 1;
  else
    return 0;
}

int validLogin(char email[100], char password[52])
{
  FILE *file;
  elogin login_file;

  char linha_csv[216];
  int isExistUser;
  int isValid;

  file = fopen("/Volumes/HD1TB/Projetos/projeto-pim-c/data/users.csv", "r");

  if (file == NULL)
  {
    printf("\n\nErro ao abrir arquivo de usuarios ou ainda nao foi realizado nenhum cadastro!");
    exit(1);
    return 0;
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

      // Column email
      if (column == 2)
      {
        strcpy(login_file.email, value);
      }

      // Column senha
      if (column == 3)
      {
        strcpy(login_file.password, value);
      }

      // printf("Column: %d Value: %s\n", column, value);
      value = strtok(NULL, ",");
      column++;
    }
    // printf("email: %s login_file.email: %s\n", email, login_file.email);
    if (strcmp(email, login_file.email) == 0)
    {
      isExistUser = 1;
      // printf("password: %s login_file.password: %s\n", password, login_file.password);
      if (strcmp(password, login_file.password) == 0)
      {
        isValid = 1;
      }
    }
  }
  fclose(file);

  if (isExistUser == 0)
  {
    printf("    .______________________________________________________.\n");
    printf("    |                                                      |\n");
    printf("    | Não foi encontrado nenhum usuario com o Email: %s\n  |", email);
    printf("    |______________________________________________________|\n");
    return 0;
  }

  if (isValid == 1)
  {
    return 1;
  }
  system("clear");
  printf("    .______________________________________________________.\n");
  printf("    |                                                      |\n");
  printf("    |                 Senha não é válida                   |\n");
  printf("    |______________________________________________________|\n");

  return 0;
}

int login()
{
  char email[100];
  char password[52];
  int8_t emailisNotValid = 1;

  while (emailisNotValid)
  {
    printf("	      ========   Prote-g   ========\n\n");
    printf("Coloque seu email:\n\n");
    scanf("%s", email);
    fflush(stdin);

    if (emailIsValid(email) == 1)
    {
      emailisNotValid = 0;
    }
    else
    {
      system("clear");
      printf("	      ========   Prote-g   ========\n\n");
      printf("Esse Email nao e valido\n\n");
    }
  }

  system("clear");
  printf("	      ========   Prote-g   ========\n\n");
  printf("Insira sua senha:\n\n");
  fgets(password, 8, stdin);
  fflush(stdin);

  if (validLogin(email, password) == 1)
  {
    return 1;
  }

  login();
  return 0;
}