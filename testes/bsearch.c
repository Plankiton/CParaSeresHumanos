#include <stdio.h>
#include <stdlib.h>

int comparador (const void *val, const void *chave){
  return ( *(int*)val - *(int*)chave );
}

int main (int argc, char ** argv){
int array[] = {3, 4, 7, 8};
int *valor_encontrado;
int n = 3;
valor_encontrado = (int *) bsearch( &n, array, sizeof(array)/sizeof(int), sizeof(int), comparador );

if (valor_encontrado)
  printf("O %i está na posição %i\n",n, valor_encontrado - array);
else
  printf("O %i não está no array", n);
return 0;
}
