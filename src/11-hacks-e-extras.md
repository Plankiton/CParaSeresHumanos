# Hacks e Extras

## Comandos do pré-processador

O pré-processador é a ferramenta que prepara o código para a compilação, por isso existem ele tem seus próprios comandos, e caso você queira curiar a versão preprocessada de um arquivo em C use o comando `gcc -E <arquivo> > <saida.c>`


Basicamente todos os comandos do pré-processador começam com `#`, e um desses comandos é o próprio `#include`, que usamos para importar nossas bibliotecas, que além de importar bibliotecas padrões, você pode importar seus próprios arquivos.

```c
#include "minhas_funcoes.c"
#include "/home/robocopgay/biblioteca.c"
```

> Quando você usa as aspas duplas (`"`) você pode passar o caminho para a sua biblioteca (caso ela esteja no mesmo diretório coloque apenas o nome do arquivo)

Outra diretris interessante é o `#declare`, que serve para criar constantes e macros:

```
#define PI 3.14
#define soma (n, n2) n + n2

#define add_item ( array, item )\
array = realloc( sizeof (array) + sizeof (item) );
```

> Note que na ultima linha da ultima macro foi usado o `\` para indicar que a próxima linha pertence a ela.

A vantagem aqui é que se precisa de uma constante, é mais útil usar o `#define` que criar uma variável, pois a variável tem que ocupar um espaço na memória, enquanto o pre-processador apenas substitue o lugar onde a macro ou constante é chamada pelo seu conteúdo.

E a diretris `#undef` _"desdefine"_ uma macro ou constante

```c
#define max 10

int i = max*3;

#undef max
define max 30
```

E existe o `#if`, `#else`, `#elif` e o `#endif`, usados para condicional

```c
#define MIN_SIZE 2

#if defined(MAX_SIZE)          // if -> se
    #define tamanho MAX_SIZE
#elif MIN_SIZE > 2             // else if -> senão se
    #define tamanho 2
#else                          // else -> senão
    #define tamanho MIN_SIZE+1
#endif                         // end -> fim

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv){
    printf("%i", tamanho);
return 0;
}
```

Além desses existem os atalhos específicos para o `#if defined(<macro>)` e o `#if !defined(<macro>)`:

```C
#define MAX_SIZE 35

#ifdef MAX_SIZE
    #define TAMANHO_MAXIMO MAX_SIZE
#endif

#ifndef MIN_SIZE
    #define TAMANHO_MINIMO 0
#endif
```

Outra coisa interessantíssima é criar strings a partir de código, _"Ué? não entendi..."_, muito simples... Quando usamos o operador `#` dentro de uma macro ele transforma o comando em string

```c
#define to_str(texto) #texto

puts( to_str(Hello mundo!!) );
```

> Saída:

```
Hello mundo!!
```

Ou se quiser juntar duas informações use o `##`

```c
#define to_str(texto) #texto
#define str_function_template(func) str##func

int l = str_function_template(len)("abacate");
printf("\"%s\" tem %i letras.\n", "abacate", l);
```

> Saída:

```
"abacate" tem 7 letras.
```

## Chegou a hora de praticar de novo!

### Desafio 5

Faça uma calculadora onde o usuário digite dois números (reais) e no final ele pergunte qual operação matemática fazer ( +, -, / ou * ) e no fim ele pergunte se a pessoa deseja calcular de novo.

> Saída:

```
Digite 2 números: 2 3
Você quer somar (+), subtrair (-), multiplicar (*) ou dividir (/)?
 +
2 + 3 = 5

Deseja calcular de novo? [S/n] n
```

#### Resposta

Primeiramente iremos declarar as variáveis necessárias:

```c
int n1, n2;    // números que iremos ler
char operacao; // operação
int res;       // resposta
```

E iremos ler os dados necessários:

```c
printf("Digite 2 números: ");
scanf("%i %i", &n1, &n2);

printf("Você quer somar (+), subtrair (-), multiplicar (*) ou dividir (/)? ");
operacao = getchar();
```

Agora nós vamos efetuar os devidos cálculos:

```c
if (operacao == '+')
   res = n1 + n2;

else if (operacao == '-')
   res = n1 - n2;

else if (operação == '/')
   res = n1 / n2;

else res = n1 * n2;
```

E exibimos o resultado:

```c
printf("\n%i %c %i = %i\n", n1, operacao, n2, res);
```

E se você é atento notou que faltou perguntar se a pessoa que calcular de novo, mas antes de fazer esta pergunta nó temos que colocar o código que queremos repetir dentro de uma estrutura de repetição, mas não coloque a parte da declaração de variáveis:

```c
do {

   printf("Digite 2 números: ");
   scanf("%i %i", &n1, &n2);

   printf("Você quer somar (+), subtrair (-), multiplicar (*) ou dividir (/)? ");
   operacao = getchar();

   if (operacao == '+')
      res = n1 + n2;
   else if (operacao == '-')
      res = n1 - n2;
   else if (operação == '/')
      res = n1 / n2;
   else res = n1 * n2;

   printf("\n%i %c %i = %i\n", n1, operacao, n2, res);

   printf("Deseja calcular de novo? [S/n] ");

   if ( getchar() == 'n' )
      break;

} while ( 1 );
```

> Eu escolhi o `do..while` porque o código sempre vai ser executado pelo menos uma vez.

E o código final ficou assim:

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n1, n2;    // números que iremos ler
  char operacao; // operação
  int res;       // resposta

  do {

    // lendo dados
    printf("Digite 2 números: ");
    scanf("%i %i", &n1, &n2);

    printf("Você quer somar (+), subtrair (-), multiplicar (*) ou dividir (/)? ");
    scanf("%c %c", &operacao, &operacao);

    // processando dados
    if (operacao == '+')
      res = n1 + n2;
    else if (operacao == '-')
      res = n1 - n2;
    else if (operacao == '/')
      res = n1 / n2;
    else res = n1 * n2;

    // exibindo dados
    printf("\n%i %c %i = %i\n", n1, operacao, n2, res);

    // reiniciando ou interrompendo programa
    printf("Deseja calcular de novo? [S/n] ");
    getchar();
    if ( getchar() == 'n' )
      break;

  } while ( 1 );
  return 0;
}
```

### Desafio 6

Faça um programa que leia 5 números e retorne a soma entre os 3 menores divididos pelo maior.

> Saída:

```
digite 5 numeros: 10 36 88 89 43

(10+36+43)/89 = 1.0
```

#### Resposta

Primeiramente precisamos ler os dados

```c
int n[5];
printf("digite 5 numeros: ");
scanf("%i%i%i%i%i", &n[0], &n[1], &n[2], &n[3], &n[4]);
```

Agora vamos pegar o maior número digitado (já que é mais simples que pegar os 3 menores).

```c
int maior = 0;
for (int i=0; i<5; i++){
  maior = (n[i] > n[maior])?i:maior;
}
```

Agora a parte mais complidada, existem duas formas de fazer isso, a primeira é comparar manualmente e atribuir a variáveis.

```c
int menor1 = maior, menor2 = maior, menor3 = maior;
maior = n[maior];
```

> temos que dar o `maior` como valor, porque para comparar temos que ter certeza de que pode existir um valor menor, caso atribuamos o `0` a variável sempre vai ter o menor valor

```c
for (int i=0; i++; i<5){
  if (n[i] < n[menor1])
    menor1 = n[i];
maior = n[maior]
}

for (int i=0; i++; i<5){
  if (n[i] < n[menor2] && i != menor1)
    menor1 = n[i];
}

for (int i=0; i++; i<5){
  if (n[i] < n[menor3] && i != menor2 && i != menor1)
    menor1 = n[i];
}
```

Essa forma com certeza funciona, mas existe uma forma mais inteligente de fazer:

```
maior = n[maior];
int menores [] = {maior, maior, maior};
for (int j=0; j<3; j++){
  for (int i=0; i<5; i++){
    if (n[i]<menores[j]){

      menores[j] = n[i];
      n[i] = maior;

    }
  }
}
```

E por fim vamos exibir os resultados:

```c
printf("(%i+%i+%i)/%i = %1.1f\n",
    menores[0],
    menores[1],
    menores[2],
    maior,
    (float)(menores[0]+menores[1]+menores[2])/maior
    );
```

> Código final:

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  // criando e lendo dados
  int n[5];
  printf("digite 5 numeros: ");
  scanf("%i%i%i%i%i", &n[0], &n[1], &n[2], &n[3], &n[4]);

  // pegando o maior valor
  int maior = 0;
  for (int i=0; i<5; i++)
    maior = (n[i] > n[maior])?i:maior;

  // pegando os menores valores
  maior = n[maior];
  int menores [] = {maior, maior, maior};
  for (int j=0; j<3; j++){
    for (int i=0; i<5; i++){

      // caso o numero atual for menor que o menor
      if (n[i]<menores[j]){
        menores[j] = n[i];

        /* o numero atual é o menor de todos
         * e por isso tem que deixar de ser,
         * ou não haverá como pegar o segundo
         * menor e muito menos o terceiro já
         * que ele seria o menor.
         */
        n[i] = maior;
      }

    }

  }

  printf("(%i+%i+%i)/%i = %1.1f\n",
      menores[0],
      menores[1],
      menores[2],
      maior,
      (float)(menores[0]+menores[1]+menores[2])/maior
      );

  return 0;
}

```

### Desafio 7

Faça um algoritmo que leia números inteiros indefinidamente e só pare quando o valor lido for maior que 1000, nos resultados devem ser informados o maior, o menor, e a media entre eles, além de dizer quais foram repetidos e se repetidos o número de vezes que foi repetido, além de todos os números primos da lista.

```
digitte números... (para parar digite um numero >= 1000)
9
8
4
2
9
8
11
390
23
42
13
1000
```
