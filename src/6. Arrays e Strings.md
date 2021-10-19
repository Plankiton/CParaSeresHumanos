# Arrays e Strings

## Arrays

Arrays são variáveis com vários espaços... _"Como assim?"_ ... Lembra do armário das variáveis? No caso do array, em vez de reservar um espaço, você pede vários espaços de uma vez, tipo:

> `cubo dado [] com ` :game\_die:`,`:game\_die:`,`:game\_die:` dentro`
>
```c
int algarismos [] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 0 };
```

E também é possível acessar um item específico do array adicionando a posição entre `[` e `]`.

```c
int algarismos [] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

int tres = algarismos[2]
```

Agora, a variável `tres` está com o item `3`, _"Mas o 3 está da 3º posição!"_ , eu entendo, esse é um erro que todo iniciante comete, a questão é que a contagem começa do `0`:

```c
//                    [0] [1] [2] [3] [4] [5] [6] [7] [8] [9]
int algarismos [] = {  1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 0};
```

E desta forma é possível modificar um valor do array:

```c
algarismos[9] = 9;
```

Mas para modificar o array inteiro é necessário modificar item por item, portanto, a seguinte forma não funcionará:

```c
int algarismos [] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

algarismos = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
```

Os arrays não podem ser impressos ou atribuídos, isso significa que todos os itens tem de ser imprimidos um por um:

```c
a [] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

printf (
   "%i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n",
   a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[0]
);
```

E antes que alguém pergunte _"Só existe array inteiro?"_, não, você pode fazer arrays com qualquer tipo primitivo.

Se você prestou atenção no capítulo sobre variáveis você deve conhecer o comando `sizeof`, que diz a quantidade de bytes de uma variável, se você usar com arrays também:

```c
int i [3];
printf ("o tamanho de "i" é %i", sizeof i);
```

_"Mas e se eu quiser saber a quantidade de elementos do meu array?"_ ... você só precisa dividir o tamanho do array pelo tamanho do tipo desse array... _"Como assim?"_ ... O tamanho de uma variável `int` é o mesmo do tipo `int`, logo, o tamanho do tipo é o tamanho de uma variável com esse tipo...

```c
int i;
int array_i [8];

int tmh_i = sizeof i;           // tamanho de i
int tmh_ari = sizeof array_i;   // tamanho de array_i

int qnt_elem = tmh_ari / tmh_i; // quantidade de elementos
```

Ou, se você for preguiçoso igual eu:

```c
int array_i [8];

int qnt_elem = sizeof array_i / sizeof array_i[0]; // quantidade de elementos
```
> lembrem-se de que `array_i` é um array do tipo `int`, ou seja, tem elementos do tipo `int`, logo, se eu usar o tamanho de um desses elementos eu também vou ter acesso ou tamanho do tipo...

## Strings

Uma string é uma cadeia de caracteres ou um array de caracteres ou um "vetor" de caracteres.

_"Mas se é um array, por que eu preciso ler essa parte se você já explicou os arrays?"_ ... Muito simples, as strings são arrays e possuem todas as características de arrays, mas elas têm algumas particularidades.

```c
char Char = 'A';          // isso é um caractere
char String [] = "coisa"; // isso é uma cadeia de caracteres

// essa é a maneira de tradicional de escrever a string
char other_str [] = {'c', 'o', 'i', 's', 'a', '\0'};
```

> tanto a variável `String` quanto a `other_str` são strings, mas, caso você use a segunda forma, não se esqueça do `\0` no fim, pois este caractere é o que delimita o fim de uma string.

Caso não queira dar valor para a string, você deverá dizer qual o seu tamanho (assim como em qualquer outro tipo de array), exemplo:

```c
char String [10];
```

> Caso você necessite usar a forma acima, lembre-se de colocar um numero a mais no comprimento da string, pois o último caractere é reservado para simbolizar o fim de uma string, por isso esta string só tem 9 caracteres válidos.

_"Tá, mas como eu dou um valor para ela?"_ ... Você pode fazer isso de três maneiras.

A primeira forma é a tradicional para dar valores a um array:

```c
char s [13];

s[0] = 'c';
s[1] = 'o';
s[2] = 'i';
s[3] = 's';
s[4] = 'a';
s[5] = 's';
s[6] = '\0';
```
> E só pra relembrar: NÃO SE ESQUEÇA DO `\0`... Tô parecendo até flashback de naruto com esse caractere ...

Na segunda, você tem que importar a biblioteca `string.h` e depois usar a função `strcpy` para atribuir o valor, dessa maneira:

```c
#include <string.h>

char str[13];
strcpy(str, "coisas");
```

> O `include` acima pode ficar tanto dentro da função `main` quanto fora, só é importante colocar antes do uso da função `strcpy`.

E a terceira, você vai ter que esperar pelo capítulo de ponteiros para entender, logo, use as mostradas acima por enquanto.

Note que você não é obrigado a colocar a quantidade exata de caracteres na string, mas não coloque uma string maior que o tamanho tamanho estipulado.

_"Legal, mas se eu quiser ler uma string? Ou imprimir uma string?"_ ... Muito simples, é só usar o `%s` no `scanf` e no `printf`, mas em relação ao `scanf` temos uma leve diferença:

```c
char str [20];
scanf("%s", &str);

printf("a string lida foi: %s\n", str);
```

Uma coisa que eu sei que você ficou na dúvida no capítulo sobre variáveis foi o por que de `'A'` ser diferente de `"A"`.

```c
char Char = 'A';
char String = "A";
```
'A' é diferente de "A", pois a string tem sempre um caractere nulo no fim:

|        | [0] |  [1] |
|--------|-----|------|
| Char   | 'A' |      |
| String | 'A' | '\0' |

