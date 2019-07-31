#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
   FILE * arq;

   arq = fopen("j.txt", "w+");
   fputs("coisas\njoao\ncoisas de novo", arq);
   fclose(arq);

   arq = fopen("j.txt", "r");
   char * texto;

   texto = malloc(sizeof(arq));
   fscanf(arq, "%s", texto);

   printf(texto);

   // liberando memória alocada
   fclose(arq);
   free(texto);
return 0;
}
