#include <stdio.h>
int main (){

   // criando variáveis que serão usadas
   int numero, outro_numero; // dessa forma criamos várias variáveis do mesmo tipo de uma vez

   // lendo variáveis
   printf("digite um número: ");
   scanf("%i", &numero);

   printf("digite outro número: ");
   scanf("%i", &outro_numero);

   // exibindo variáveis
   printf("\n");
   printf("%i + %i = %i\n", numero, outro_numero, numero + outro_numero);
   printf("%i - %i = %i\n", numero, outro_numero, numero - outro_numero);
   printf("%i * %i = %i\n", numero, outro_numero, numero * outro_numero);
   printf("%i / %i = %.2f\n", numero, outro_numero, (float) numero / (float) outro_numero);
   printf("\n");
   printf("A divisão inteira entre %i e %i é %i e o resto dessa divisão é %i\n", 
      numero, outro_numero, numero / outro_numero, numero % outro_numero);

return 0;
}
