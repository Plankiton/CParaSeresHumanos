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
  /*

  char str[10];
  strncpy(str, "joao e maria", 4);
  str[4] = '\0';

  puts(str);
  */
  /*
  char str[] = "abcdefghijklmnop";
  printf("%s\n", strchr(str, 'g'));
  */
  /*
char str[] = "bcdefgh";
printf("a primeira vogal de \"%s\" está na %i posição\n",str, strcspn(str, "aeiou")+1);
*/
  char str[] = "joao maria ronaldo";
  puts(strstr(str, "maria"));

return 0;
}
