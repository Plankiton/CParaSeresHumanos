#include <stdio.h>
#include <stdlib.h>
int main(){
   int n;

   scanf("%i", &n);

   ( n % 2 == 0 )? printf("o número %i é par", n) : printf("digite outro número: ");

   int reserva = n;
   n = ( n % 2 == 0 ) ? n : scanf("%i", &reserva);
   n = reserva;

   printf("\n numero final: %i", n);
return 0;
}
