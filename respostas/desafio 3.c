#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){

   // declaração e leitura de variáveis
   int n1, n2, n3;

   printf ("Digite 3 números: ");
   scanf ("%i %i %i", &n1, &n2, &n3);

   // declaração e inicialização dos contadores
   int impar = 0, par = 0, divPor3 = 0;

   // se o número for divisível por 2 incremente par senão incremente impar
   ( n1 % 2 == 0 )? par ++: impar ++;
   ( n2 % 2 == 0 )? par ++: impar ++;
   ( n3 % 2 == 0 )? par ++: impar ++;

   // se é divisível por 3 incremente senão não incremente
   divPor3 = ( n1 % 3 == 0 )? divPor3 + 1: divPor3;
   divPor3 = ( n2 % 3 == 0 )? divPor3 + 1: divPor3;
   divPor3 = ( n3 % 3 == 0 )? divPor3 + 1: divPor3;

   // Hora de exibir os resultados

   printf(
      "%i%c%s %s,", 

      impar,
      (impar == 0 )? '\b' : ' ',

      (impar == 0 )?  "nenhum é" :
         ( (impar == 1 )? "é" : "são" ) ,

      (impar > 1)? "ímpares": "ímpar"
   );

   printf(
      " %i%c%s %s", 

      par,
      (par == 0 )? '\b' : ' ',
      (par == 0 )? "nenhum é" :
         ( (par == 1 )? "é" : "são" ),

      (par > 1)? "pares": "par"
   );

   printf(
      " e %i%c%s %s\n", 

      divPor3,
      (divPor3 == 0 )? '\b' : ' ',

      (divPor3 == 0 )? "nenhum é" :
         ( (divPor3 == 1 )? "é" : "são" ),

      (divPor3 > 1)? "divisíveis por 3": "divisível por 3"
   );

   return 0;
}
