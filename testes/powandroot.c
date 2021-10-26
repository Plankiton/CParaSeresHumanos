#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char ** argv){
  /*
  int p = 5;
  float n = pow(p, 2);
  printf("%i ao quadrado é %.0f\n", p, n);
  printf("a raiz quadrada de %.0f é %.0f\n", n, pow( n, (1.0/2.0)) );
  */
  /*
  double param, result;
  param = 1024.0;
  result = sqrt (param);
  printf ("sqrt(%.0f) = %.0f\n", param, result );
  */
// vou usar o expoente 2 mas funciona com qualquer valor
int numero = pow(5, 2);                  // 25
int outro_numero = pow(numero, 1.0/2.0); // 5

printf(" 5²  = %i\n"
       " √25 = %i\n", numero, outro_numero);
return 0;
}
