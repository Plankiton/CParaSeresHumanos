#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int *n = (int *) malloc((sizeof (int)));
  int l = 1;
  int an;

  int maior = 0;

  printf("Digite números... (para parar digite um >= 1000)\n");
  while (1) {
    scanf("%i", &an);

    // fazendo checagem
    if (an>=1000)
      break;

    // adicionando item ao vetor
    n = realloc(n, (sizeof (int))*l);
    n[l-1] = an;
    l ++;

    // maior numero
    if (maior < an)
      maior = an;
  };

  // menor e media
  int soma = 0;
  int menor = maior;
  for (int i = 0; i < l-1; ++i) {
    if (n[i] < menor)
      menor = n[i];
    soma += n[i];
  }
  float media = (float) soma / (float) (l-1);

  printf("=:%i <:%i >:%i /:%1.1f l:%i\n", soma,maior, menor, media, l-1 );
  free(n);
  return 0;
}
