#include <stdio.h>
#include <stdlib.h>
int main(){
   int a [] = {0, 5, 6, 7, 8, 9};
   /*
   printf("%i", a[2]);
   a[2] = 8;
   printf("%i", a[2]);
   */

  printf("%i\n", *(void*)2 - a );

return 0;
}
