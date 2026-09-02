#include <stdio.h>
#include <math.h>

#include "avalia.h"

int main(void) {
  double resultado = avalia();

  if (isnan(resultado))
    printf("Expressao invalida ou entrada vazia.\n");
  else
    printf("%g\n", resultado);

  return 0;
}
