#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
   /*
   char j [20];
   char * str = &j[0];
   while (strlen(j) < 20){
      *str = 'j';
      str ++;
   }
   * str = '\0';
   printf("%s", j);


   char str [] = "joao";
   char j = str[0];

   printf("%c\n", j);
   */
   char str [] = "joao";
   char j[2];
   char * lj = &j[0];

   *lj = str[0];
   lj ++;
   *lj = '\0';

   printf("%s\n", j);
return 0;
}
