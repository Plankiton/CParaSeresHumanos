#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  // criando e lendo dados
  int n[5];
  printf("digite 5 numeros: ");
  scanf("%i%i%i%i%i", &n[0], &n[1], &n[2], &n[3], &n[4]);

  // pegando o maior valor
  int maior = 0;
  for (int i=0; i<5; i++)
    maior = (n[i]>maior)?n[i]:maior;

  // pegando os menores valores
  int menores [] = {maior, maior, maior};
  for (int j=0; j<3; j++){
    for (int i=0; i<5; i++){

      // caso o numero atual for menor que o menor
      if (n[i]<menores[j]){
        menores[j] = n[i];

        /* o numero atual é o menor de todos
         * e por isso tem que deixar de ser,
         * ou não haverá como pegar o segundo
         * menor e muito menos o terceiro já
         * que ele seria o menor.
         */
        n[i] = maior;
      }

    }

  }

  printf("(%i+%i+%i)/%i = %1.1f\n",
      menores[0],
      menores[1],
      menores[2],
      maior,
      (float)(menores[0]+menores[1]+menores[2])/maior
      );

  return 0;
}
