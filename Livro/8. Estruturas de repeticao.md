# Estruturas de repetição

Estruturas de repetição são estruturas que permitem que você repita comandos, e isso te permite automatizar algumas coisas como atribuir valor a arrays ou fazer contagem...

## While

```c
// exibindo uma contagem até 5

// sem estruturas de repetição
printf("%i\n", 1);
printf("%i\n", 2);
printf("%i\n", 3);
printf("%i\n", 4);
printf("%i\n", 5);

// com uma estrutura de repetição
int contador = 1;
while (contador <= 5){          // enquanto o contador for menor ou igual 5
   printf("%i\n", contador);    //   escreva o contador
   contador ++;                 //   e incremente o contador
}
```
> No caso acima temos duas formas de exibir uma contagem... _"Mas deu a mesma quantidade de linhas, então não vale a pena aprender esse negócio difícil aí, a primeira opção é mais simples!!"_ ... E se ao invés de contar até 5 nós precisássemos contar até mil? Você ainda acha aceitável escrever isso sem usar uma estrutura de repetição ?

A estrutura usada é o `while`, que significa "enquanto", basicamente ele funciona assim:

```c
condicao = (2 != 3);
while ( condicao ) {   // enquanto a condição for verdade execute
   // comandos
}
```

E se a condição for verdadeira o `while` vai executar os comandos do bloco, mas se ela for falsa ele vai sair do loop (estrutura de repetição).

E assim como nos condicionais, se você precisar

No caso da contagem foi necessário adicionar `1` ao contador, pois se a `condicao` sempre for verdadeira o programa vai entrar em um loop infinito, e foi isso que aconteceu com o nosso exemplo anterior, pois o `2` sempre será diferente do `3`.

Mas isso não quer dizer que loops infinitos sejam sempre ruins,Digamos que agente queira que um programa leia dados, mas não sabemos a quantidade exata de vezes ler, então criamos um loop infinito e damos um "flag"(uma forma de interrupção do loop) a ele, no nosso exemplo flag será a resposta para a pergunta "Deseja continuar?", caso a pessoa digite "n" loop será interrompido.

Eu vou ilustrar a situação acima de duas maneiras usando o `while`.

```c
// usando o teste lógico do while
{
   char flag = 's';

   while (flag == 's'){
      printf("Deseja continuar? [s/N] ");
      scanf("%c", &flag);
   }
}

// usando o break
{
   char flag;

   while (1) {
      printf("Deseja continuar? [s/N] ");
      scanf("%c", &flag);

      if (flag != 's') break; // se a resposta for não interrompa
   }
}
```
> O break é um comando que interrompe loops

E assim como nos condicionais o `while` também tem uma forma compacta:

```c
int cont = 0;
while (cont <= 10) printf("%i\n", cont++);
```

## Do..while

A estrutura popularmente conhecida como `do`..`while` é basicamente um `while` de cabeça para baixo.

```c
// exibindo uma contagem até 5
int i = 1;

// while

while ( i <= 5 )         // enquanto ( i menor ou igual a 5 )
   printf ( "%i\n", i++ );  //     escreva i

// do..while
do {                         // faça {
   printf ( "%i\n", i );     //    escreva i
} while ( i<=5 );            // } enquanto ( i menor ou igual a 5 )
```

O `do`..`while` funciona da mesma forma que o `while`, com uma única diferença, ele faz o teste lógico no final, logo, ele executa o que está no bloco e só depois testa a condição:

```c
int i = 90;

do {
   printf("%i\n", i);
} while ( i <= 10 );
```

> Saída:

```
90
```

_"Ué? Por que ele imprimiu?"_ , Porque ele faz o teste lógico ( `i <= 10` ) no fim da execução do bloco, se este fosse um `while` comum o teste seria feito antes, e só executaria o bloco se este teste fosse verdadeiro.

_"Aah! Então é inútil usar este laço!!"_ ... Sinto discordar, mas este laço foi criado para agilizar algumas tarefas, lembra do código com flag? Que vimos no capítulo anterior?

```c
char flag = 's';

while (flag == 's'){
   printf("Deseja continuar? [s/N] ");
   scanf("%c", &flag);
}
```

Para que o código acima funcione nós somos obrigados o valor `'s'` à variável `flag`, com o `do`..`while` isso não é necessário:

```c
char flag;

do {
   printf("Deseja continuar? [s/N] ");
   scanf("%c", &flag);
} while (flag == 's');
```

E o código com `while` e sem usar o teste lógico (o que usamos o `break` para sair do loop) é um `do`..`while` escrito manualmente!

## For

O `for` é uma forma mais automatizada de loop, ele é mais usado para contagem, mas também é possível usá-lo com flag.

Em uma comparação direta com o `while`:

```c
// exibindo uma contagem até 5

// while
{
   int i = 0;
   while (i <= 5) printf("%i\n", i++);
}

// for
{
   for ( int i = 0; i <= 5; i++) printf("%i\n", i);
}
```

_"Caramba!! O que aconteceu aqui?"_ ... Se você não estiver entendido o código acima eu irei mostrar da forma tradicional:

```c
// exibindo uma contagem até 5

// while
{
   int i = 0;            // dando o valor 0 a i
   while (i <= 5) {      // enquanto i menor ou igual a 5
      printf("%i\n", i); // escreva i
      i ++;              // incremente i
   }
}

// for
{
   for ( int i   =   0; i <= 5;     i++      ) { 
// para      i entre 0    e  5  incremente i
      printf("%i\n", i); 
   }
}
```

_"Ainda não entendi o `for`"_ ... Note que temos três espaços entre os parenteses separados por `;`, no primeiro espaço você declara uma variável, no segundo você digita o teste lógico, e no terceiro você digita um incremento.

Basicamente o `for` é uma gambiarra do `while`, ainda utilizando o exemplo anterior observe um for escrito no estilo se um `while`:

```c
int i = 0;

for ( ; i <= 5 ; ){
   printf("%i\n", i);
   i++;
}
```

> Os espaços entre `;` podem ficar em branco, mas convenhamos que é um tanto inútil usar um `for` desta maneira...

E as formas diversas de usar o `for` são essas:

```c
// usar variável já existente
int i;
for (i = 1; i <= 5; i++) printf("%i\n", i);

// criando variável local exclusiva para o uso do for
for ( int i = 1; i <= 5; i++) printf("%i\n", i);

// forma while
int i = 1;
for ( ; i <= 5; ) printf("%i\n", i++);

// forma de loop infinito com flag
int i = 1;
for (;;) {
   printf ("%i\n", i++);
   if ( i == 5 ) break;
}
```

Deu pra perceber que o `for` é bem eclético não é mesmo? Mas definitivamente a forma em que ele é mais útil é a tradicional:

```c
for ( int <nome da variável> = <valor inicial>; <teste lógico>; <incremento>) {
   // comandos
}

// forma compacta
for ( int <nome da variável> = <valor inicial>; <teste lógico>; <incremento>) /* comando */;
```

