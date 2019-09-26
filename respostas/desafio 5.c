#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n1, n2;    // números que iremos ler
  char operacao; // operação
  int res;       // resposta

  do {

    // lendo dados
    printf("Digite 2 números: ");
    scanf("%i %i", &n1, &n2);

    printf("Você quer somar (+), subtrair (-), multiplicar (*) ou dividir (/)? ");
    scanf("%c %c", &operacao, &operacao);

    // processando dados
    if (operacao == '+')
      res = n1 + n2;
    else if (operacao == '-')
      res = n1 - n2;
    else if (operacao == '/')
      res = n1 / n2;
    else res = n1 * n2;

    // exibindo dados
    printf("\n%i %c %i = %i\n", n1, operacao, n2, res);

    // reiniciando ou interrompendo programa
    printf("Deseja calcular de novo? [S/n] ");
    getchar();
    if ( getchar() == 'n' )
      break;

  } while ( 1 );
  return 0;
}
