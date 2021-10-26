#include <stdio.h>

int (* Soma) (int n1, int n2);

int somador (int n, int n2){
  return n + n2;
}

int main(){
  Soma = somador;
  printf("%i + %i = %i", 2, 3, Soma(2, 3));
return 0;
}
