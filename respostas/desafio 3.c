#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){

   // declaração e leitura de variáveis
   int n1, n2, n3; // Essa é a forma de declarar várias variáveis ao mesmo tempo

   printf ("Digite 3 números: ");
   scanf ("%i %i %i", &n1, &n2, &n3);

   // declaração e inicialização dos contadores
   int impar = 0, par = 0, divPor3 = 0; // essa é a forma de inicializar várias variáveis ao mesmo tempo

   // se o número for divisível por 2 incremente par senão incremente impar
   ( n1 % 2 == 0 )? par ++: impar ++;
   ( n2 % 2 == 0 )? par ++: impar ++;
   ( n3 % 2 == 0 )? par ++: impar ++;

   // se é divisível por 3 incremente senão não incremente
   divPor3 = ( n1 % 3 == 0 )? divPor3 + 1: divPor3;
   divPor3 = ( n2 % 3 == 0 )? divPor3 + 1: divPor3;
   divPor3 = ( n3 % 3 == 0 )? divPor3 + 1: divPor3;

   // exibindo resultados
   /*
      geralmente esta é a parte mais fácil, mas nesse caso não,
      pois na hora de escrever a saída nós devemos respeitar o
      plural e o singular para que o nosso programa fique mais
      inteligente.
      */

   // Declarando variáveis que dizem se está no plural (2), singular (1) ou nulo(0)
   int impar_plural, par_plural, divPor3_plural;

   /* 
      Se o contador for  maior que 1, ele é plural, portanto 2,
      senão teste se contador igual a 1 se for verdadeiro (1) é
      singular se for falso (0) não tem nenhum.
      */

   divPor3_plural = ( divPor3 > 1 ) ? 2 : ( divPor3 == 1 );
   impar_plural   = ( impar   > 1 ) ? 2 : ( impar   == 1 );
   par_plural     = ( par     > 1 ) ? 2 : ( par     == 1 );

   // agora que temos as quantidades e sabemos se são plurais ou não é só exibir os resultados

   printf(
         "\n%i%c%s %s", 

         impar,                            // quantidade de impares
         (impar_plural == 0 )? '\b' : ' ', // se a quantidade for 0 ele apaga o 0 ("\b") senão ele escreve um espaço

         (impar_plural == 0 )?         "nenhum é"   :     ((impar_plural == 1 )?         "é"   :            "são"),
         //  se for nulo         escreve "nenhum é"  senão     se for singular     escreve "é" senão  escreve "são"

         (impar_plural == 2)? "ímpares": "ímpar" // se for plural escreve "ímpares" senão escreve "ímpar"
         );

   printf(
         "\n%i%c%s %s", 

         par,
         (par_plural == 0 )? '\b' : ' ',
         (par_plural == 0 )? "nenhum é" : ((par_plural == 1 )? "é" : "são"),
         (par_plural == 2)? "pares": "par"
         );

   printf(
         "\ne %i%c%s %s", 

         divPor3,
         (divPor3_plural == 0 )? '\b' : ' ',
         (divPor3_plural == 0 )? "nenhum é" : ((divPor3_plural == 1 )? "é" : "são"),
         (divPor3_plural == 2)? "divisíveis por 3": "divisível por 3"
         );

   return 0;
}
