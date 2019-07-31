#include <stdio.h>
#include <stdlib.h>

// struct simples
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

// struct as type
/*
typedef struct pessoa {
   char *nome;
   int idade;
   char sexo;
} person;

void infoperson ( person * pessoa ) {
   printf("o nome é %s a idade é %i e o sexo é %s\n",
         pessoa -> nome, pessoa -> idade,
         (pessoa -> sexo == 'f') ? "Feminino": "masculino"
   );

   printf("o nome é %s a idade é %i e o sexo é %s\n",
         (*pessoa).nome, (*pessoa).idade,
         ((*pessoa).sexo == 'f') ? "Feminino": "masculino"
   );
}

int main(int argc, char **argv){
   person pessoa = {"joao", 12, 'm'};

   printf("o nome é %s a idade é %i e o sexo é %s",
         pessoa.nome, pessoa.idade,
         (pessoa.sexo == 'f') ? "Feminino": "masculino"
   );
   infoperson(&pessoa);
return 0;
}
*/


#include <stdio.h>

int soma(int a,int b)
{
return a+b;
}


typedef struct coisa {
   int (*soma)(int,int);
   char j;
} coisa;


int main(void)
{
   struct coisa j;
   j.soma = soma;

   j.j = 'j';
   printf("soma: %c\n",j.j);
   printf("soma: %i\n",j.soma(1,2));

return 0;
}


