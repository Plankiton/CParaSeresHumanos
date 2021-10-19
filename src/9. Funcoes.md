# Funções

A estrutura de uma função já foi explicada anteriormente de uma forma bastante resumida:

```c
int main(){
   printf("Hello mundo!!");
return 0;
}
```

Basicamente uma função é uma rotina, que pode ser usada durante a execução de um código, um exemplo é a função `printf`, que nada mais é do que um conjunto de códigos que escrevem coisas na tela, uma rotina que é executada sempre que é chamada.

A estrutura de uma função é simples:

```c
//  tipo do retorno  nome     parametros
    int              soma ( int n1, int n2) {
      return n1 + n2;
   }

   int main () {
      printf("%i\n", soma( 34, 54));
      return 0;
   }
```
> Claro que você pode declarar a quantidade de parâmetros que quiser.

E se você não quiser retornar nenhum valor declare a função como `void`.

Mas se você for criar uma função, certifique-se de que ela foi declarada antes da função `main`, e se mesmo assim você ainda queira que a sua função fique depois do `main`, você tem que antes declarar a função:

```c
void oi () ;

int main () {
   oi();
   return 0;
}

void oi () {
   printf("oi!!\n");
}
```

E um extra sobre a função `main` é que é possível receber dados como parâmetros... _"Como assim?"_ ... Digamos que queremos que o nosso programa escreva coisas na tela...

> Execução do nosso programa:

```sh
./escreva Hello mundo!!
```

> Saída:

```
Hello mundo!!
```

Os parâmetros `Hello` e `mundo!!` foram passados para a função `main` pela linha de comando, e para que agente possa receber e usar esses parâmetros você precisa declará-los a área de parâmetros do `main`.

```c
int main (int arg_counter, char * arg_variable []) {

   for (int i = 1; i <= arg_counter; i ++)
      printf("%s ", arg_variable[i]);

   printf("\b\n");
return 0;
}
```

> O `arg_counter` é a quantidade de argumentos recebidos, o `arg_variable` é um parâmetros com os argumentos, e esses parâmetros ou argumentos, são strings.

> No exemplo acima usamos `arg_counter` e `arg_variable` para o nome dos parâmetros, e você pode usar o que você quiser, mas a maioria das pessoas usam `argc` (`arg_counter`) e `argv` (`arg_variable`).

Por fim, é sempre interessante saber como seria um ponteiro para uma função:

```c
#include <stdio.h>

int (* Soma) (int n1, int n2);

int somador (int n, int n2){
  return n + n2;
}

int main(){
  Soma = somador;
  printf("%i + %i = %i", 2, 3, Soma(2, 3));
return 0;
}
```

