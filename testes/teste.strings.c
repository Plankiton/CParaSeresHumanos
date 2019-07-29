#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
   /*

   // ponteiros e strings
   char j [20];
   char * str = &j[0];
   while (strlen(j) < 20){
      *str = 'j';
      str ++;
   }
   * str = '\0';
   printf("%s", j);

   // strings e strings

   char str [] = "jnjnj";
   char k[] = "o joao maria eu";
   char j[2];
   j[0] = 'j';
   printf("%s\n"
         "%s\n"
         "%s", j, k, str);
   */

   // atribuindo strings a strings sem o string.h
   char * string;

   string = "joao";
   puts(string);
return 0;
}
