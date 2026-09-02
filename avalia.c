#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "avalia.h"

// Função que ler o próximo item da expressão em notação pré-fixa
char *proximo_item(void) {

  static char buffer[TAMANHO_MAXIMO_ITEM+1];

  if ( scanf("%s", buffer) == EOF )

    return NULL;
  
  return strcpy(malloc(sizeof(char)*(strlen(buffer)+1)), buffer);
}

// Retorna o valor de uma expressão aritmética em notação pré-fixa recursivamente
double avalia(void) {

  char *item = proximo_item();

  // Caso chegou ao fim da entrada, encerra a função
  if (item == NULL)
    return NAN;
  
  // Caso o item seja um número, converte de string para double
  if (isdigit(item[0]))
  {
    double num;

    num = strtod(item, NULL);
    free(item);

    return num;
  }

  // Início das expressões aritméticas

  // Operação de soma
  if (item[0] == '+')
  {
    double a, b;
    
    a = avalia();
    b = avalia();
    free(item);

    return a + b;
  }

  // Operação de subtração
  if (item[0] == '-')
  {
    double a, b;

    a = avalia();
    b = avalia();
    free(item);

    return a - b;
  }

  // Operação de multiplicação
  if (item[0] == '*')
  {
    double a, b;

    a = avalia();
    b = avalia();
    free(item);

    return a * b;
  }

  // Operação de divisão
  if (item[0] == '/') 
  {
    double a, b;

    a = avalia();
    b = avalia();
    free(item);

    return a / b;
  }

  // Operação de potência
  if (item[0] == '^')
  {
    double a, b;

    a = avalia();
    b = avalia();
    free(item);

    return pow(a, b);
  }

  // Operação de logaritmo
  if (!(strcmp(item, "log")))
  {
    double a, b;

    a = avalia();
    b = avalia();
    free(item);

    return log(a) / log(b);
  }

  // Caso onde o item não seja uma operação válida
  free(item);
  
  return 0;
}