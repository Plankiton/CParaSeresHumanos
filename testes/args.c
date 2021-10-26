#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void escreva_numeros ( int qntd, ... ){
  va_list args;
  va_start( args, qntd );

  char * formato = malloc( qntd*3+1 );
  for (int i=0;i < qntd*3; i+=3){
    formato[i] = '%';
    formato[i+1] = 'i';
    formato[i+2] = ' ';
  }
  formato[ (qntd * 3) ] = '\n';

  vprintf(formato, args);

  va_end( args );
  free(formato);
}

void print( char * formato, ... ){
  va_list argumentos;
  va_start( argumentos, formato );

  int argc = strlen(formato); // pegando a qntd de args

  for (int i = 0; i<argc; i ++){
    if (formato[ i ] == 'i') // caso o dado esperado for um int
      printf( "%i", va_arg( argumentos,            int ) );
      //             va_arg( <lista de args>,   <tipo> ) );

    if (formato[ i ] == 'f') // float
      printf( "%f", va_arg( argumentos, double ) );

    if (formato[ i ] == 's') // string
      printf(va_arg( argumentos, char *));
  }
  putchar('\n');
  va_end (argumentos);
}

int main(int argc, char *argv[])
{
  print("sfi", "joao ", 4.3, 30);
  escreva_numeros ( 5, 5,6,7, 6, 7);
  return 0;
}
