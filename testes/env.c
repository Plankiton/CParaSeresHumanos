#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv){
  /*
  puts(getenv("PATH"));
  */

  FILE *response = popen("echo hello mundo!", "r"); // popen( <comando> )

  char comando [20];
  fgets( comando, 20, response );
  printf("o a resposta do comando usado foi:\n%s\n", comando);
  return 0;

}
