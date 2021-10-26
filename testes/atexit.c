#include <stdio.h>
#include <stdlib.h>

void tmp_file_remove (void){
  remove("/tmp/at_exit_lock");
}

int main(){
  FILE * tmp = fopen("/tmp/at_exit_lock", "w");
  atexit(tmp_file_remove);

  // pausando a execução
  puts("não click em enter ainda... olhe se há um arquivo \"at_exit_lock\" na pasta /tmp/");
  getchar();

  puts("agora veja se ainda está lá");
  fclose (tmp);
  return 0;
}
