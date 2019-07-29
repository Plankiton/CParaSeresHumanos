#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){

   char *list[] = {"joao", "maria", "boiolage"};

   int i = 0;
   printf("[ ");
   while ( i < 3){
      printf(" \"%s\",", list[i]);
   }
   printf("\b ]");


return 0;
}
