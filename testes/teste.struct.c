#include <stdio.h>
#include <stdlib.h>

/*
struct pessoa {
   char *nome;
   int idade;
   char sexo;
};

int main(int argc, char **argv){
   struct pessoa person = {"joao", 12, 'm'};

   printf("o nome é %s a idade é %i e o sexo é %s",
         person.nome, person.idade,
         (person.sexo == 'f') ? "Feminino": "masculino"
   );
return 0;
}
*/

typedef struct pessoa {
   char *nome;
   int idade;
   char sexo;
} person;

int main(int argc, char **argv){
   person pessoa = {"joao", 12, 'm'};

   printf("o nome é %s a idade é %i e o sexo é %s",
         pessoa.nome, pessoa.idade,
         (pessoa.sexo == 'f') ? "Feminino": "masculino"
   );
return 0;
}
