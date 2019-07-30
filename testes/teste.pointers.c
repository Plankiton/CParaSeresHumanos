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
   */

   // variável de tamanho dinâmico
   long long *p = NULL;

   p = malloc(sizeof (long long));

   *p = 0x111111111111111;
   printf("%lli\n", *p);
   free(p);

return 0;
}
