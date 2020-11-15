#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
  /* 
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
   */
  /*
  char caractere;

  FILE * arquivo;
  arquivo = fopen("j.txt", "r");

  while ( (caractere = fgetc(arquivo)) != EOF )
    putchar(caractere);
  */
  /*
  FILE * arquivo = fopen("texto.txt", "r");
  if (!arquivo){
    printf("joao");
    return 1;
  }

  char * texto_do_arquivo = malloc(10);

  fscanf(arquivo, "%s", texto_do_arquivo);

  printf("%s", texto_do_arquivo);

  fclose(arquivo);
  free (texto_do_arquivo);
  */

  /*
  FILE *arquivo = fopen("texto.txt", "r");

  fseek(arquivo, 0, SEEK_END); // mudando o "cursor" para o fim do arquivo
  size_t tamanho_arquivo = ftell(arquivo); // pegando a posição do cursor
  fseek(arquivo, 0, SEEK_SET); // colocando o cursor no inicio de novo

  char * texto = malloc( tamanho_arquivo );

  fread( texto, sizeof (char), tamanho_arquivo, arquivo );
  puts(texto);

  free(texto);
  fclose(arquivo);
  */

  /*
  char j;
  char str [100];
  fgets(str, 100,stdin);
  FILE *f = fopen("j.txt", "r+");
  fputs(str, f);
  while ((j = fgetc(f))!=EOF)
    fputc('a', stdout);
  putchar('\n');
  fclose( f );
  */
  /*
FILE *j = fopen("j.txt", "r");

char c;
while ((c = fgetc(j)) != 'a')
  putchar(c);

printf("\n%li\n", ftell(j));
return 0;
*/

  /*
FILE * arquivo = fopen("j.txt", "r+");

fpos_t posicao; // tem que ser deste tipo para funcionar

fgetpos(arquivo, &posicao); // pegando a posição
printf("posicao: %p\ncaractere: %c", &posicao, fgetc(arquivo));

fsetpos(arquivo, &posicao + 4); // mudando posição para o 4 caractere
fgetpos(arquivo, &posicao);     // pegando a posição de novo

getchar();

printf("posicao: %p\ncaractere: %c\n", &posicao, fgetc(arquivo));
fclose ( arquivo );

getchar();
*/
  /*
  freopen("j.txt", "w", stdout);
  puts("joao é boiola!!\n");
  */
/* setbuf example */
  char buffer[BUFSIZ];
  FILE *pFile1, *pFile2;

  pFile1=fopen ("myfile1.txt","w");
  pFile2=fopen ("myfile2.txt","a");

  setbuf ( pFile1 , buffer );
  fputs ("This is sent to a buffered stream",pFile1);
  fflush (pFile1);

  fputs ("This is sent to an unbuffered stream",pFile2);

  fclose (pFile1);
  fclose (pFile2);

  return 0;
}
