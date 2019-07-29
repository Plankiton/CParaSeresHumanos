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

   // ...

   char str [] = "joao";
   char j = str[0];

   printf("%c\n", j);
   */

   // ... ++

   char str [] = "jnjnj";
   char k[] = "o joao maria eu";
   char j[2];
   j[0] = 'j';
   printf("%s\n"
         "%s\n"
         "%s", j, k, str);
return 0;
}
