#define MIN_SIZE 2

#if defined(MAX_SIZE)
  #define tamanho MAX_SIZE
#elif MIN_SIZE > 2
  #define tamanho 2
#else
  #define tamanho MIN_SIZE+1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char ** argv){
  // printf("%i", tamanho);
#define to_str(texto) #texto
#define putthis(texto) puts(to_str(texto))
#define str_function_template(func) str##func

  int l = str_function_template(len)("abacate");
printf("\"%s\" tem %i letras.\n", "abacate", l);
putthis( "joao e maria" é uma frase);
  return 0;
}
