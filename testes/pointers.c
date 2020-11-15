#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
   /*
   char *list[] = {"joao", "maria", "boiolage"};

   int i = 0;
   printf("[ ");
   while ( i < 3){
      printf(" \"%s\",", list[i]);
   }
   printf("\b ]");

   // variável de tamanho dinâmico
   long long *p = NULL;

   p = malloc(sizeof (long long));

   *p = 0x111111111111111;
   printf("%lli\n", *p);
   free(p);
   */

   /*
   int j[3][3];

   int laux = 0;
   for (int l = 0; l < 3; l++){
      laux = l + l*2;
      for (int c = 0; c < 3; c++){

         j[l][c] = laux+c; // *( *(j + l) +c ) = l + c;

         printf("%i ", j[l][c]); // printf("%i ", *( *(j + l) +c ));

      }
      printf("\n");
   }
   */


   char * str;          // aqui temos um ponteiro vazio.

   str = malloc (6);          // aqui nós alocamos 6 bytes na memória.

   // guardando dados...
   str[0] = 'c';
   str[1] = 'o';
   str[2] = 'i';
   str[3] = 's';
   str[4] = 'a';
   str[5] = '\0';

   printf( str );
   putchar('\n');

   str = realloc (str, 12);        // aqui nós realocamos o espaço de 6 bytes para 12 bytes

   // guardando dados...
   str[0] = 'o';
   str[1] = 'u';
   str[2] = 't';
   str[3] = 'r';
   str[4] = 'a';
   str[5] = ' ';
   str[6] = 'c';
   str[7] = 'o';
   str[8] = 'i';
   str[9] = 's';
   str[10] = 'a';
   str[11] = '\0';
   

   printf( str );
   putchar('\n');

   free( str );           /*
                              essa linha vai no fim do programa e serve
                              para liberar a memória que nó alocamos.
                          */

return 0;
}
