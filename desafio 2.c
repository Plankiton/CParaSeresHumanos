#include <stdio.h>

int main (){

   int numero, outro_numero;
   char operacao = '+';

   printf("Digite um número inteiro: ");
   scanf("%i", &numero);

   printf("Digite outro número inteiro: ");
   scanf("%i", &outro_numero);

   printf("Digite a operação [+/-]: ");
   scanf("%c", &operacao);
   scanf("%c", &operacao);

   int res = ( operacao == '+' ) ? numero + outro_numero : numero - outro_numero ;

   printf ( "a %s entre %i e %i é %i\n", 
         ( operacao == '+' ) ? "soma" : "subtração", 
         numero, 
         outro_numero, 
         res 
   );

   return 0;
}
