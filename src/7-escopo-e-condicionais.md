# Escopo e Condicionais

## Os blocos e o escopo

Até agora eu apenas mencionei o que é um bloco lá no inicio do livro para explicar a função `main`, mas acho que aquilo não foi o suficiente para encerrar o assunto.

A primeira característica de um bloco, que a propósito já foi abordada, é que ele é uma sequencia de comandos entre `{` e `}`, mas uma coisa que você não sabia é que ele pode ser usado sem a necessidade de uma estrutura:

```c
int numero;

{
   numero = 89;
}

numero += 67;
```

_"mas que diferença isso fez para o programa?"_ , neste caso acima nenhuma, mas os blocos podem ser úteis para a organização do código e também para o isolamento de variáveis:

```c
int n = 46;
{
   char a = n;
   printf("char: %c\n", a);
}
printf("char: %c\n", a);
```

O programa a cima não irá compilar por que a variável `a` só existe dentro do bloco, logo, o segundo `printf` não vai conseguir imprimir a variável.

Isso acontece por causa de uma coisa que chamamos de escopo, e o escopo determina o nível de acesso de uma variável no código, isso significa a variável `a` do código anterior só podia ser acessada dentro do bloco onde foi declarada, e é o que chamamos de variável local.

```c
int coisa = 0;

int main () {

   int outra_coisa = 90;

   // bloco
   {
      int A = 100;
   }
   return 0;
}
```

O escopo do código anterior seria assim:
> Trate o "X" como "pode acessar" o bloco dentro da função `main` é o "bloco" da tabela e tudo o que está fora da função `main` é a área "global".

|             | bloco | `main` | global |
|-------------|-------|--------|--------|
|`coisa`      |  X    |   X    |   X    |
|`outra_coisa`|  X    |   X    |        |
|`A`          |  X    |        |        |

> A variável `coisa` é global porque está fora de todos os blocos possíveis, portanto pode ser acessada em qualquer bloco do programa, enquanto a variável `outra_coisa` é local da função `main`, logo, todo e qualquer bloco dentro do `main` pode ter acesso a ela, e a variável `A` só existe dentro do bloco isolado.

```c
int a = 78973;
{
   char a = 'a';
   printf("char a : %c\n", a);
}
printf("int a : %i\n", a);
```

> Saída:
```
char a : a
int a : 78973
```
> O que aconteceu aqui foi que a variável `a` do tipo inteiro foi declarada fora do bloco, logo, ela existia também dentro do bloco, até que outra variável `a` foi declarada dentro do bloco também, e o valor do `a` de dentro do bloco não sob-escreve o `a` de fora do bloco porque ela só existe dentro do bloco, e quando o bloco acaba a variável `a` do tipo `char` deixa de existir e o `a` inteiro continua existindo...

Eu sei que é um pouco confuso, mas isso acontece simplesmente por que as variáveis de escopos diferentes são declaradas áreas diferentes da memória.

E nunca se esqueça que essas regras vistas neste capítulo serve para todo e qualquer bloco...

## Condicionais

Até agora nós fizemos códigos mais sequenciais, onde todos os comandos eram executados e a única forma de decisão que usamos foi o operador ternário.

```c
int n;

printf("digite um número: ");
scanf("%i", &n);

// com o ternário
printf("o número %i é %s ", n, (  n % 2 == 0   ) ?     "par"    :  "ímpar"   );
//                             (operação lógica) ? caso verdade : caso falso

// com condicionais
printf("o número %i é ", n)
if (n % 2 == 0) {         // se n for par
   printf("par \n");      //   escreva "par"
} else {                  // senão
   printf("ímpar \n");    //   escreva "ímpar"
}
```

Note que os condicionais são muito mais intuitivos, e por isso são mais fáceis de usar que o ternário... _"Ué? Então por que você mostrou o ternário primeiro?"_ ...Porque eu precisava de uma estrutura que não exigisse um conhecimento sobre blocos e escopo e que tornasse o você mais preparado para esse assunto, pois se você entendeu o ternário você com certeza entendeu os condicionais.

_"Mas com o ternário ficou muito mais curto!"_ ...Sim, mas e se sempre que o número for ímpar ele tenha também de pedir outro número ao usuário?...
> Não se questione sobre esta funcionalidade a mais, ela é só uma forma de dificultar um pouco o exemplo.

```c
// com ternário
int n;

printf("digite um número: ");
scanf("%i", &n);

   (  n % 2 == 0  )? printf("o número %i é par", n) : printf("digite outro número: ");
//   se n for par         diga que ele é par      senão        peça outro número

int reserva = n;
n = ( n % 2 == 0 ) ?   n       :      scanf("%i", &reserva);
//   se n for par    n é n   senão      leia outro número

n = reserva;
```
> antes que você se pergunte o por quê de eu ter criado a variável `reserva`, se o código estivesse assim:
```c
n = ( n % 2 == 0 ) ? n : scanf("%i", &n);
```
> O `scanf` iria ler o valor, colocar dentro do n, mas quando ele finalizasse esta instrução ele retornaria um `1` ou um `0` para informar se deu certo ou não, e esse feedback do `scanf` substituiria o valor lido por ele, e sempre que o número fosse ímpar o `n` seria `1` ou `0`, então a variável `reserva` serve de reserva para o valor de `n`.

```c
// com condicionais
int n;

printf("digite um número: ");
scanf("%i", &n);

if (n % 2 == 0) {                    // se n for par
   printf("o número %i é par", n);   // diga que ele é par
} else {                             // senão
   printf("digite outro número: ");  // peça outro número
   scanf("%i", &n);                  // e leia esse número
}
```

Note que o código feito com condicionais ficou muito mais organizado e simples de entender, além de eliminar a necessidade da variável auxiliar `reserva`...

Existem 3 formas de fazer um condicional no C:

```c
int condicao = (67 != 5);  /*
                              e se você prestou atenção 
                              no capítulo de operadores 
                              sabe que o valor dessa 
                              variável é 1.
                           */
int outra_condicao = (8 > 2);

// simples

if ( condicao ) {
   // comandos
}

// composto
if ( condicao ) {
   // comandos
else {
   // outros comandos
}

// aninhado
if ( condicao ) {
   // comandos
else if ( outra_condicao ) {
   // comandos
} else {
   // outros comandos
}
```

> Mas o bloco não é obrigatório para o uso do condicional, caso você queira um `if` mais compacto:
```c
if (condicao) /* comando */;
```

> Caso você precise executar mais de um comando você vai ter que usar um bloco, mas você usar a forma acima em conjunto com as anteriores, logo, o seguinte código é válido:

```c
int i = 3847;

if (i % 2 == 0) printf("O número é par!\n");

else if ( ( (float) i / 3.0 == 0.0 ) && ( i % 2 == 1 ) ) {
   printf("O número é ímpar e divisível por 3!");
   printf("\n");
}

else printf("O número é ímpar!");
```

