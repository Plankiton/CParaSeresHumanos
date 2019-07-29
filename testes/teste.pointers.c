#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){

   char *list[] = {"joao", "maria", "boiolage"};
   char * aux;

   int i = 0;
   printf("[ ");
   while ( i < 3){
      aux = list[i];
      printf(" \"%s\",", aux);
      i ++;
   }
   printf("\b ]");


return 0;
}
