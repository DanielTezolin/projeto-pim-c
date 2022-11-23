#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int emailIsValid(char email[20]) {
  int tam = strlen(email);
  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

  for (i = 0; i < tam; i++) {
    char c = email[i];
    if (c == '@') {
      if (arroba)
        break; // não pode ter uma segunda @
      arroba = 1;
      if (i < 3)
        break;           // se @ vier antes de 3 caracteres, erro
    } else if (arroba) { // se já encontrou @
      if (ponto) {       // se já encontrou . depois de @
        depoisPonto++;
      } else if (c == '.') {
        ponto = 1;
        if (antesPonto < 3) {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      } else {
        antesPonto++;
      }
    }
  } // for

  if (i == tam && depoisPonto > 1)
    return 1;
  else
    return 0;
}

int login() {
  char login[20];
  char password[8];
  int8_t emailisNotValid = 1;

  while (emailisNotValid) {
    printf("Coloque seu email:\n\n");
    fgets(login, 20, stdin);
    fflush(stdin);

    if (emailIsValid(login) == 1) {
      emailisNotValid = 0;
    } else {
      system("clear");
      printf("Esse Email nao e valido\n\n");
    }
  }

  system("clear");
  printf("Insira sua senha:\n\n");
  fgets(password, 8, stdin);
  fflush(stdin);

  return 1;
}