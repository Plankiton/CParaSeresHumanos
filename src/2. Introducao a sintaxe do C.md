# Introdução à sintaxe do C


### Hello mundo em C

> Hello_mundo.c

```c
#include <stdio.h>            // importação de biblioteca externa

int main () {                 // declaração da função main
   printf("Hello mundo!!\n"); // função que escreve coisas na tela
   return 0;                  // retorno da função
}                             // fim da função
```

Compilando o arquivo

> linux/BSD/Mac OSX
```sh
gcc Hello_mundo.c -o hello
```
> Windows
```bat
gcc Hello_mundo.c -o hello.exe
```

Todos os exemplos e desafios são compilados da mesma forma: `gcc <arquivo.c> -o <nome do binário>`

> Caso o arquivo não compile com o `gcc` use o `g++`

Executando o arquivo (lembre-se de estar no mesmo diretório do arquivo compilado)

> linux/BSD/Mac OS X
```sh
./hello
```
> Windows
```bat
hello.exe
```
>
> Saída
```
Hello mundo!!
```
>

> Todos os exemplos e desafios são executados da mesma forma mostrada acima, apenas troque o `hello` pelo nome do binário gerado.

No programa apresentado, nós vimos a estrutura básica de todo programa em C, no qual temos a importação do módulo `stdio.h` (conjunto de funções para saída e entrada de dados), a função `main`(função que é chamada na execução do programa), e os comandos da função que serão executados (tudo o que está entre `{` e `}`), que no nosso caso é o `printf`(função de saída de dados que escreve texto na tela), e por fim o `return` que diz para o sistema operacional se ocorreu tudo como o planejado na execução da função `main`.
> Notem que todos os comandos dentro do bloco (tudo o que está entre `{` e `}`) da função `main` estão separados por `;`, caso você se esqueça desse caractere, o seu programa não será compilado.

A função `main` é essencial para o funcionamento de programas escritos em C, pois ela é a função que é chamada na execução do programa.

Mas, caso você ainda não tenha entendido, eu vou explicar de uma maneira mais simples.

> Imagine que Terezinha, uma cozinheira muito habilidosa, vai preparar um ovo frito. A primeira coisa que ela faz é pegar uma frigideira com óleo e colocar no fogo. Depois, ela vai quebrar o ovo dentro da frigideira e jogar sal. Depois de todos os passos feitos ela dá uma olhada para saber se o ovo queimou, ou se tudo ocorreu como desejado.

Terezinha simboliza o sistema operacional executando um programa feito em C:  a frigideira é a função `main`, os ovos, o óleo, o sal e a fritura do ovo são todos os comandos executados pela função. 
Terezinha sabe se o ovo está queimado ou não porque a frigideira dá um retorno (quando o ovo está mais escuro, ela sabe que queimou): esse é o papel do comando `return` da função `main`.

> A partir daqui, você vai se deparar com diversos códigos soltos (para economizar espaço), mas quando for testá-los na sua máquina, coloque-os dentro da função `main`:

```c
#include <stdio.h>

int main(){
   <comandos apresentados>
   return 0;
}
```

O `;` é o que delimita o fim de um comando no C e ele ignora os espaços ou quebras de linha em excesso antes do `;`, logo, isso:

```c
           printf
(
"Hello mundo!!\n"
         )
;
```

É o mesmo que isso:

```c
printf("Hello mundo!!\n");
```

> Então as regras para o uso do `;` são:
>
> 1. Devem estar no final das linhas com comandos.
> 2. Não devem estar em linhas que começarem com `#`.
> 3. Não devem estar em linhas que terminam com chaves se essas chaves pertencem a blocos de código (pois existem outras estruturas que usam chaves).


Mas mesmo sabendo disso tome cuidado com os espaços, pois em alguns casos muito específicos a falta deles pode confundir o compilador, por exemplo:

```c
int i = -2 - -3;
```
> não se preocupe com o `int i =`, saiba apenas que `i` é uma variável, isso será explicado mais tarde...

O `-3` é um número negativo, mas o `-` entre `-2` e `-3` é o sinal de subtração, se não houvesse espaço entre o `-` solto e os outros números, o programa acima não seria compilado pois o C não saberia o que você quer que ele faça.

## Comentários

Comentários são "anotações ou esclarecimentos" escritas(os) no código para descrever a função de algo e geralmente são úteis quando se  quer analisar algum código antigo seu, ou o código de outra pessoa. Os comentários sempre são ignorados pelo compilador, eles são apenas para auxiliar o programador.

```c
// comentários de uma única linha
/*
   comentários 
   de 
   multiplas 
   linhas
*/
```

É sempre aconselhável o uso de comentários, principalmente se você pretende fazer um projeto _open source_ (como já dito, projetos de código aberto).

## Variáveis

> Imagine um armário com diversos espaços para guardar coisas, alguns só podem guardar esferas, outros só podem pra guardar bonecas, outros só podem guardar cubos e cada espaço desses possui um nome.
>
> Toda vez que alguém quer um espaço no armário deve  pedir para o dono, mas o dono só reserva o espaço se pedir da maneira correta, que é:
>
>`<tipo do espaço> <nome do espaço> com <coisa que queremos no espaço> dentro`
>
> Exemplos:
>
> `esfera bola_de_futebol com `:soccer:` dentro`
>
> `boneca gemeas         com `:dolls:` dentro`
>
> `cubo   dado           com `:game_die:` dentro`

O armário é a memória do seu computador, os espaços são as variáveis e o nome em cada espaço é o nome da variável, que só consegue armazenar tipos específicos de dados, no exemplo são `esfera`, `cubo` ou `boneca`, e a situação descrita para a reserva de um espaço é a declaração:

```c
// <tipo do espaço>  <nome do espaço>  com  <coisa que queremos no espaço> dentro
   int               numero            =    80                                  ;
```

No exemplo acima, reservei um espaço que só guarda números inteiros (`int`) com o nome `numero` e com o valor `80` dentro. E no C, existem 3 tipos primitivos, ou seja, 3 tipos de dados básicos, o `int`, o `float` e o `char`.

```c
// <tipo do espaço>  <nome do espaço>  com  <coisa que queremos no espaço> dentro
   int               numero            =    80                                  ;
   char              caractere         =    'A'                                 ;
   float             numero_real       =    99.9                                ;
```

Variáveis do tipo `int` recebem números sem ponto, como `2`, `8` ou `234` enquanto as do tipo `float` recebem números com ponto como `2.5`, `8.3` ou `23.0`, já variáveis do tipo `char` recebem um caractere, **apenas um** , logo, se tentar colocar um `"hello"` ou até mesmo um `"h"`, ele vai retornar um erro, pois todo e qualquer caractere entre `"` é uma string enquanto um `char` é um único caractere entre `'`, não se preocupe com as strings, por enquanto...

E se você deseja alterar o valor da variável, só precisa colocar o nome da variável recebendo o valor:

```c
int i = 5; // declaração da variável "i" valendo "5"

i = 92;    // agora a variável vale 92
```

Esse exemplo acima serve para todos os tipos primitivos, mas lembre-se de colocar valores do tipo certo na variável. Se você declarou uma variável inteira, na hora de alterar o valor, tem que trocar por um inteiro.

Além disso, também existe o tipo `double` que é descendente do tipo `float`, mas com mais capacidade de espaço... _"Mas como assim espaço? Números não são infinitos?"_ ... Os números são infinitos sim, mas a memória ram do computador não é, e mesmo que fosse, seria um desperdício liberar um espaço infinito para uma única variável, então todas as variáveis dentro do C tem um espaço limitado.

Cada variável ocupa uma certa quantidade de bytes na memória ram:

```c
/*
um byte tem 8 bites e um bite só pode ser 0 ou 1, isso quer dizer que 
sempre que o computador reserva 1 byte ele está reservando 8 espacinhos
com zeros e ums.
*/

int inteiro = 0; /* -> 4 bytes -> você só consegue colocar 
                       números de -2147483648 a 2147483647,
                       pois se o número estiver fora desse
                       intervalo ele teria mais de 4 bytes.
                 */

char caractere = 'A'; /* 1 byte -> só aceita um caractere,
                           porque um caractere ocupa um
                           byte.
                      */

float real = 3.14; /* 4 bytes -> só suporta valores entre 
                        10E-38 e 10E38 (isso significa 10
                        vezes 10 elevado a -38 a 38, o "E"
                        substitui o "vezes 10 elevado a"
                        para simplificar para o computador).
                   */

double real_2 = 10E49; /* 6 bytes -> o double tem mais
                              espaço que um float
                              e por isso pode suportar
                              números entre 10E-4932 e
                              10E4932
                           */
```
> Essas quantidades demonstradas acima não são iguais em todas as arquiteturas (tipo de processador), isto quer dizer que se o seu computador é de 32 bits o tamanho das variáveis pode ser diferente de um de 64 bits, logo, para que você tenha certeza do tamanho delas (em bytes) é só usar o `sizeof`:

```c
int inteiro;
int tmh_inteiro = sizeof inteiro; // tamanho da variável inteiro
```

> Caso você não queira criar uma variável unicamente para pegar o seu tamanho é possível usar o `sizeof` para pegar o tamanho do tipo diretamente:

```c
int tmh_inteiro = sizeof (int); // tamanho da variável inteiro
```

> Note que o tipo está entre parênteses, isso é obrigatório ou o C vai achar que você está se referindo a uma variável.

E a galera que já conhece um pouco de programação deve estar se perguntando _"Mas e os booleanos? No C não existe verdadeiro e falso?"_  sim, mas no C o `int` faz esse papel, sendo que o **0** equivale a **falso** e o **1** equivale a **verdadeiro**.

As variáveis em C (e acho que em todas as linguagens) têm algumas regras quanto à escolha do seu nome, estas regras são:

1. Variáveis não podem iniciar com números;
2. Variáveis não podem ter espaços (substitua os espaços por `_`);
3. Variáveis só podem conter letras, números e travessões (evite usar letras com acento também);
4. Variáveis não podem ser iguais à palavras reservadas.

> Palavras reservadas do C:

```c
auto break case char if const continue  default do double else enum
extern float for goto if int long register return short signed void
sizeof static struct  switch  typedef union unsigned volatile while
```

Sendo assim, variáveis com nomes como `2letras`, `char`, `jo%ao` ou `peso da pedra` estão erradas, mas variáveis como `_2letras`, `Char`, `joao` ou `peso_da_pedra` estão certas, e tome muito cuidado com o uso de maiúsculas e minúsculas, pois o C as diferencia, portanto, `char` é uma palavra reservada, mas `Char` não é.

Uma forma de atribuição do C que pode ser meio confuso pode ser dado pelo seguinte código:

```c
int c = 80;
int i = (c = 30); // i vai valer 30
c = c + (i = 20); // c vai valer 50
```

> Isso ocorre, porque o C atribui o `30` a variável `c` e retorna o valor para `i`.

### Conflito entre tipos

Um problema (na minha opinião) do C é a forte tipagem, que significa que os tipos têm que ser respeitados a todo o custo, logo, se queremos que um dado seja transformado em outro, precisamos fazer conversões de tipos.

```c
int Um = (int) 1.5; // apenas o 1 será atribuído
```

Quando você atribui a uma variável um valor que pertence a outro tipo, o C vai converter isso para o tipo da variável:

```c
int i = 1.5; // i vai valer 1
float f =  i / 3; /*
                     o resultado dessa divisão seria 0.3333...
                     Mas como os dois  números são inteiros o
                     resultado  é  0, e por  isso é  atribuído
                     o valor 0.0 à variável f
                  */
```

> Portanto, sempre use variáveis do mesmo tipo para operações matemáticas, caso sejam de tipos diferentes use a conversão de tipos.

Para que o resultado seja atribuído da forma correta, você deve fazer a conversão de tipos ou usar o tipo certo no calculo:

```c
float f = 1.0 / 2.0;                     // usando o tipo certo (float)
f = (float) 1 / (float) 2;             /* usando a conversão de tipos 
                                                       também conhecida como
                                                       "type cast"
                                                  */
                                                  
int  n = 5, n1 = 2;

f = n / n1;                                 // f = 2.0
f = (float) n / (float) n1;          // f = 2.5
```
>

