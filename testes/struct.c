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


/*
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
*/
/*

#include <stdio.h>
#include <stdlib.h>

typedef struct {
   char * n;
} j;

void add ( j * _j, int n){
   _j = realloc(_j, sizeof (j) * n);
}

int main(int argc, char **argv){

   j c [4];

   for (int i = 0; i < 4; i ++)
      c[i].n = "jojaodjf";
   for (int i = 0; i < 4; i ++)
      puts(c[i].n);
   puts("\n\n");

   j * n;
   n = malloc(sizeof(j));

   add (n, 4);
   for (int i = 0; i < 4; i ++)
      n[i].n = "huhuhu";
   for (int i = 0; i < 4; i ++)
      puts(n[i].n);

   add (n, 7);
   for (int i = 0; i < 7; i ++)
      n[i].n = "boiolage";
   for (int i = 0; i < 7; i ++)
      puts(n[i].n);
return 0;
}
   */

int main(int argc, char *argv[])
{
    typedef struct {
        char * nome;
        int idade;
        float peso;
        float altura;
    } pessoa;

    //                      .nome, .idade, .peso, .altura
    pessoa pessoa_normal = (pessoa){"joao",     13,  80.5,    1.60};
    printf ("nome: %s idade: %i peso: %f altura: %f\n", pessoa_normal.nome, pessoa_normal.idade, pessoa_normal.peso, pessoa_normal.altura);
    pessoa_normal = (pessoa){
        .altura = 1.6,
        .peso = 110,
        .idade = 80,
        .nome = "vanessa",
    };
    printf ("nome: %s idade: %i peso: %f altura: %f\n", pessoa_normal.nome, pessoa_normal.idade, pessoa_normal.peso, pessoa_normal.altura);
    return 0;
}
