# Operadores

### Aritméticos

Os operadores aritméticos são os operadores matemáticos e são expressos da seguinte maneira em C:

```c
n + N // Adição            -> soma os dois números;
n - N // Subtração         -> subtrai os dois números;
n * N // Multiplicação     -> multiplica dois números;
n / N // Divisão           -> divide dois números;
n % N // resto da divisão  -> retorna o resto da divivão entre dois números.
```
> para evitar erros sempre faça operações com números de tipos iguais.

E nunca se esqueça que em expressões numéricas existe uma ordem de precedência, logo, `6+4/2` é `8` e não `5`, e isso acontece porque assim como na matemática é resolvida primeiro a divisão (`4/2`) e depois é somado `6` a esse valor.

Ordem de precedência:

- parênteses (`( )`)
- multiplicação (`*`), divivão (`/`) e resto (`%`)
- adição (`+`) e subtração (`-`)

```c
6+4/2    //  ->  8
(6+4)/2  //  ->  5
```

### Atribuição

O operadores de atribuição são formas simplificadas de atribuir valores... _"Não entendi..."_

Isso é uma atribuição:

```c
numero = 89;
```

E caso eu queira que este número valia ele mesmo + 1 eu faço:

```c
numero = numero + 1;
```

Mas para poupar esforços o C também aceita:

```c
numero += 1;
```

E isso vale para qualquer operação:

```c
numero += 2; // numero = numero + 2
numero -= 3; // numero = numero - 3
numero *= 7; // numero = numero * 7
numero /= 2; // numero = numero / 2
```

Além desses também existe os operadores de incremento e decremento:

```c
numero ++; // numero = numero + 1
numero --; // numero = numero - 1
```
> os vistos acima são denominados de pós incremento, pois a variável só recebe o valor depois de retorna-lo _"O que?"_ ... Observe:

```c
int numero = 89;
printf("%i\n", numero++ );
```

> Saída:

```
89
```

_"Pera! mas ele não deveria ser 90?"_ ... A variável `numero` só é incrementada depois de retornar o valor dela, isso quer dizer que ela só é incrementada depois dessa parte do programa, mas se você usar o pré-incremento:

```c
int numero = 89;
printf("%i\n", ++numero );
```

> Saída:

```
90
```

```c
numero ++; // pós-incremento
numero --; // pós-decremento

++ numero; // pré-incremento
-- numero; // pré-decremento
```

### Relacionais

Os operadores lógicos são todos aqueles que testam uma expressão relacional e dizem se ela é verdadeira ou falsa.

> lembrando que no C verdadeiro é 1 e falso é 0.

```c
n == N // igual            -> testa se n é igual a N;
n != N // diferente        -> testa se n é diferente de N;

n <  N // menor que        -> testa se n é menor que N;
n >  N // maior que        -> testa se n é maior que N;

n <= N // menor ou igual   -> testa se n é menor ou igual a N;
n >= N // maior ou igual   -> testa se n é maior ou igual a N;
```

Exemplo simples:

```c
printf("%i\n", 1 < 2);
printf("%i\n", 1 > 2);
printf("%i\n", 1 != 2);
printf("%i\n", 1 == 2);
```

> Saída:

```
1
0
1
0
```

> E lembrem-se que os tipos dos dados sendo testados tem que ser o mesmo.

Eles serão usados por vocês nas estruturas condicionais, laços de repetição e com o **operador ternário**.

### Lógicos

Os operadores lógicos são usados para assimilar operações que retornam valores lógicos... _"Como assim?"_ ... São usados para operações verdadeiras e falsas.

> João pede ao seu pai um fone de ouvido e um celular, mas o seu pai só dá o fone de ouvido, e ele fica insatisfeito pois ele queria as duas coisas.

João só ficaria satisfeito ( verdadeiro ) se ele ganhasse o celular e o fone de ouvido, como ele só ganhou o fone ele ficou insatisfeito ( falso ).

O operador usado no exemplo acima é o "and" ( `&&` ) que só é "verdadeiro" se as duas opções forem verdadeiras, exemplo:

```c
printf("%i && %i = %i\n", 1 < 5, 2 > 0, 1 < 5   &&   2 > 0);
printf("%i && %i = %i\n", 1+80 < 5, 2 > 0, 1+80 < 5   &&   2 > 0);
```

> Saída:

```
1 && 1 = 1
0 && 1 = 0
```

Os operadores lógicos são o `&&`, que equivale a "and"("e"), já visto anteriormente, o `||`, que equivale a "or"("ou") e o `!`, que equivale a "not"("não").
> considere os uns e zeros abaixo apenas o resultado de alguma operação relacional...


|             |`&&`|             | resultado final |
|-------------|----|-------------|-----------------|
| `1`         |`&&`| `1`         | 1               |
| `0`         |`&&`| `1`         | 0               |
| `1`         |`&&`| `0`         | 0               |
| `0`         |`&&`| `0`         | 0               |


|             |`\|\|`|             | resultado final |
|-------------|----|-------------|-----------------|
| `1`         |`\|\|`| `1`         | 1               |
| `0`         |`\|\|`| `1`         | 1               |
| `1`         |`\|\|`| `0`         | 1               |
| `0`         |`\|\|`| `0`         | 0               |


|`!`|             | resultado final |
|---|-------------|-----------------|
|`!`| `1`         | 0               |
|`!`| `0`         | 1               |

Exemplo:

```c
printf("%i && %i = %i\n", 1 < 5, 2 > 0, 1 < 5   &&   2 > 0);

printf("%i || %i = %i\n", 1 < 5, 2 > 6, 1 < 5   ||   2 > 6);

printf("!(%i && %i) = %i\n", 1 < 5, 2 > 6, !(1 < 5   &&   2 > 6));
```

> Saída:

```
1 && 1 = 1
1 || 0 = 1
!(1 && 0) = 1
```

### Ternário ou condicional

```c
int  numero = 80;
char imparOuPar = (  numero % 2 == 0  ) ? 'p'               : 'i'              ;
//                ( <expressão logica> ) ? <se for Verdade>  : <se for Mentira>
```

O código acima representa um uso simples do operador ternário e eu sei que você deve estar um pouco confuso com isso, mas eu explico:

> Antes de mais nada, saiba que **todo número par tem o resto da divisão por 2 igual 0** , então, no exemplo acima, caso `( numero % 2 == 0 )` seja verdadeiro, o operador vai retornar `'p'` de par, caso a expressão seja falso, ele vai retornar `'i'` de ímpar, portanto, o C vai testar a expressão lógica entre `(` e `)` se essa expressão for verdadeira, o valor da operação vai ser o que está entre `?`, e caso contrário, o valor será o que está após `:`

Outro exemplo do uso seria:

```c
int nota = 6;
char status = ( nota >= 7 ) ? 'p' : 'r';

printf("João %s de ano", (status=='p')? "passou" : "reprovou" );
```

No código acima, se a nota do João for maior ou igual a 7, o programa escreve `"João passou de ano"` na tela, se não, ele escreve `"João reprovou de ano"`.

## Chegou a hora de praticar!

Agora chegou a hora de praticar, e não pule essa parte, pois o seu aprendizado só é absoluto se você praticar, então, para potencializar o seu aprendizado em C e em qualquer linguagem de programação:

> Dicas:
>
> 1. Se tiver dificuldade em algo na hora da resolução do exercício, primeiro volte ao assunto antes de consultar a resposta;
> 2. Sempre escreva todo o código: não use o `ctrl+C` e `ctrl+V` enquanto ainda está aprendendo, pois quando você escreve,  está acostumando o seu cérebro com a sintaxe da linguagem;
> 3. Sempre que você conseguir resolver o desafio, antes de pular para o próximo, tente resolvê-lo de novo de outra maneira;
> 4. Caso não consiga resolver, veja a resposta e depois tente fazer de novo de outra maneira;
> 5. Crie seus próprios desafios para dificultar os que estão aqui.

Todos os desafios serão resolvidos e explicados linha a linha, exceto o último de cada rodada, pois esse você vai ter que resolver sozinho, obrigatoriamente, para tentar provar para si mesmo que aprendeu e se você não conseguir, leia de novo os conteúdos anteriores e tente novamente. Caso você passe para a próxima parte sem resolvê-lo,  terá dificuldades posteriores em outros assuntos.

### Desafio 1

Faça uma calculadora onde o usuário digite dois números (reais) e no final ele exiba todas as operações matemáticas com esses números:

> saída:

```
digite um número: 3
digite outro número: 4

3 + 4 = 5
3 - 4 = 5
3 * 4 = 12
3 / 4 = 0.75

A divisão inteira entre 3 e 4 é 0 e o resto dessa divisão é 3
```

#### Resposta

Antes de mais nada, nós temos que digitar nossa estrutura padrão:

```c
#include <stdio.h>
int main (){

return 0;
}
```

Depois, nós temos que pedir dois números para o usuário:

```c
printf("digite um número: ");
printf("digite outro número: ");
```

Agora, iremos ler os dois números, mas antes, temos que criar as variáveis que vão guardar esses números:

```c
float numero, outro_numero; // dessa forma criamos várias variáveis do mesmo tipo de uma vez
```

Agora, nós podemos ler os números:

```c
printf("digite um número: ");
scanf("%f", &numero);

printf("digite outro número: ");
scanf("%f", &numero);
```

Finalmente, iremos exibir os resultados:

```c
printf("\n");
printf("%f + %f = %f\n", numero, outro_numero, numero + outro_numero);
printf("%f - %f = %f\n", numero, outro_numero, numero - outro_numero);
printf("%f * %f = %f\n", numero, outro_numero, numero * outro_numero);
printf("%f / %f = %f\n", numero, outro_numero, (float) numero / (float) outro_numero);
printf("\n");
printf("A divisão inteira entre %f e %f é %i e o resto dessa divisão é %i\n", 
   numero, outro_numero, numero / outro_numero, numero % outro_numero);

```

E o código final ficou assim:

```c
#include <stdio.h>
int main (){

   // criando variáveis que serão usadas
   int numero, outro_numero; // dessa forma criamos várias variáveis do mesmo tipo de uma vez

   // lendo variáveis
   printf("digite um número: ");
   scanf("%i", &numero);

   printf("digite outro número: ");
   scanf("%i", &outro_numero);

   // exibindo variáveis
   printf("\n");
   printf("%i + %i = %i\n", numero, outro_numero, numero + outro_numero);
   printf("%i - %i = %i\n", numero, outro_numero, numero - outro_numero);
   printf("%i * %i = %i\n", numero, outro_numero, numero * outro_numero);
   printf("%i / %i = %.2f\n", numero, outro_numero, (float) numero / (float) outro_numero);
   printf("\n");
   printf("A divisão inteira entre %i e %i é %i e o resto dessa divisão é %i\n",
   numero, outro_numero, numero / outro_numero, numero % outro_numero);

return 0;
}
```

### Desafio 2

Faça uma calculadora na qual o programa peça dois números e depois uma operação (a escolha deve ser entre soma e subtração).

> Saída:

```
Digite um número inteiro: 8
Digite outro número inteiro: 2
Digite a operação [+/-]: +

A soma entre 8 e 2 é 10

```

#### Resposta

A primeira coisa que devemos fazer é obviamente escrever a estrutura padrão:

```c
#include <stdio.h>

int main (){

   return 0;
}
```

Agora, temos que declarar as variáveis que irão guardar os dados:

```c
int numero, outro_numero;
char operacao;
```

E temos que pedir os dados para o usuário:

```c
printf("Digite um número inteiro: ");
scanf("%i", &numero);

printf("Digite outro número inteiro: ");
scanf("%i", &outro_numero);

printf("Digite a operação [+/-]: ");
fflush(stdin);

scanf("%c", &operacao);
```
> no meu caso ocorreu aquele bug do `scanf` que eu mencionei no capítulo de entrada e saída de dados, mas caso no seu não aconteça apague a linha com o `fflush`.

Agora, iremos testar se a operação escolhida foi soma ou subtração e depois salvar o resultado em outra variável (`res`):

```c
int res = ( operacao == '+' ) ? numero + outro_numero : numero - outro_numero ;
//   ...se operacao for +            some          senao   subtraia
```

E finalmente exibimos os resultados:

```c
printf ( "a %s entre %i e %i é %i\n", 
   ( operacao == '+' ) ? "soma" : "subtração", 
   numero,
   outro_numero,
   res
);
```

O código final ficou assim:

```c
#include <stdio.h>

int main (){

   // declarando variáveis
   int numero, outro_numero;
   char operacao = '+';

   // lendo variáveis
   printf("Digite um número inteiro: ");
   scanf("%i", &numero);

   printf("Digite outro número inteiro: ");
   scanf("%i", &outro_numero);

   printf("Digite a operação [+/-]: ");
   // resolvendo bug do scanf
   scanf("%c", &operacao);
   // lendo variável
   scanf("%c", &operacao);

   // calculando resultado
   int res = ( operacao == '+' ) ? numero + outro_numero : numero - outro_numero ;
   //   ...se operacao for +            some          senao   subtraia

   // exibindo resultado
   printf ( "a %s entre %i e %i é %i\n", 
         ( operacao == '+' ) ? "soma" : "subtração", 
         numero, 
         outro_numero, 
         res 
   );

   return 0;
}
```


### Desafio 3

Faça um programa que leia 3 números e diga quantos deles são ímpares ou pares e quantos deles são divisíveis por 3 (se divididos por 3 o resto tem que ser 0).

> Saída:

```
Digite 3 números: 2 1 3
2 são ímpares, 1 é par e 1 é divisível por 3
```

Você já deve ter percebido que este é complicado, mas calma... É só pensar bem, e uma dica, explore bem o ternário antes.

#### Resposta

A primeira coisa que iremos fazer é declarar e ler os números ( depois de escrever a estrutura padrão é claro ) :

```c
int n1, n2, n3; // Essa é a forma de declarar várias variáveis ao mesmo tempo

printf ("Digite 3 números: ");
scanf ("%i %i %i", &n1, &n2, &n3);
```

Agora nós iremos declarar contadores para os ímpares, pares e divisíveis por 3 e iniciá-los com `0` (se não fizer isso suas variáveis vão receber lixos da memória):

```c
int impar = 0, par = 0, divPor3 = 0; // essa é a forma de inicializar várias variáveis ao mesmo tempo
```

Declarados os contadores, iremos testar os números pares e ímpares:

```c
// se o número for divisível por 2 incremente par senão incremente impar
( n1 % 2 == 0 )? par ++: impar ++;
( n2 % 2 == 0 )? par ++: impar ++;
( n3 % 2 == 0 )? par ++: impar ++;
```

Agora testamos os divisíveis por 3:

```c
divPor3 = ( n1 % 3 == 0 )? divPor3 + 1: divPor3;
divPor3 = ( n2 % 3 == 0 )? divPor3 + 1: divPor3;
divPor3 = ( n3 % 3 == 0 )? divPor3 + 1: divPor3;
```

E por fim exibimos os valores:

Aqui nós temos duas opções, exibimos os dados de forma preguiçosa:

```c
printf ( "%i são ímpares\n", impar);
printf ( "%i são pares\n", par);
printf ( "%i são divíveis por 3\n", divPor3);
```
> E nesse caso, quando o contador vale 0 ou 1, vai ficar "0 são <algo>" ou "1 são <algo>".

Ou tentamos adaptar a resposta para que ela respeite os plurais e singulares e assim criando um programa mais inteligente:

> Ambos os códigos de exibição dos dados funcionarão da mesma forma, basicamente temos que exibir uma resposta assim:

> `<contador> <são (se plural)|| é (se singular)> <info que o contador se refere>`

> E caso o contador for `0` essa resposta tem que ser assim: `nenhum é <info que o contador se refere>`

> mas para economizar linhas de código essas duas formas de frase teriam que ser uma só, logo, eu temos que montar um esqueleto assim:

> `<contador><caractere auxiliar><string indicando a quantidade> <info a que o contador se refere>`

> Então a string do `printf` ficou assim: `"%i%c%s %s\n"`
>
> Agora que temos o "esqueleto" da resposta, temos que dar valores a esses campos e o primeiro é o contador ( `par`, `impar` e `divPor3` )
>
> O segundo é o caractere auxiliar e ele tem que apagar o contador caso ele for nulo (igual a `0`) com o caractere `\b`, caso contrário ele insere um espaço (' '):
>
> `( <contador> == 0 ) ? '\b' : ' ' `
>
> O terceiro é a string indicando a quantidade, e nesse caso temos três opções, se o contador for 0 essa string tem que ser `"nenhum é"`, se o contador não for `0` ele testa se o contador é igual a 1, e caso for verdadeiro essa string vai valer `"é"` (indicando que é singular), senão ele obviamente é plural (contador maior que `1`) então essa string vai valer `"são"`:
>
> `(<contador> == 0)? "nenhum é" : ( ( <contador> == 1 )? "é" : "são" )`.
>
> Por fim é só testar se é plural ou singular e colocar a informação a que o contador se refere no plural ou singular:
>
> `(<contador> > 1)? <info no plural> : <info no singular>`

> O "esqueleto" final do printf ficou assim:

```c
printf ( "%i%c%s %s",
         <contador>,                                              // %i
         (<contador> == 0)? '\b' : ' ',                           // %c
         (<contador> == 0)? "nenhum é" :
               ( ( <contador> == 1 )? "é" : "são" ),              // %s
         (<contador> > 1)? <info no plural> : <info no singular>  // %s
);
```

E é assim que fica a exibição dos resultados seguindo o esqueleto acima:

```c
// Hora de exibir os resultados

printf(
   "%i%c%s %s,", 

   impar,
   (impar == 0 )? '\b' : ' ',

   (impar == 0 )?  "nenhum é" :
      ( (impar == 1 )? "é" : "são" ) ,

   (impar > 1)? "ímpares": "ímpar"
);

printf(
   " %i%c%s %s", 

   par,
   (par == 0 )? '\b' : ' ',
   (par == 0 )? "nenhum é" :
      ( (par == 1 )? "é" : "são" ),

   (par > 1)? "pares": "par"
);

printf(
   " e %i%c%s %s\n", 

   divPor3,
   (divPor3 == 0 )? '\b' : ' ',

   (divPor3 == 0 )? "nenhum é" :
      ( (divPor3 == 1 )? "é" : "são" ),

   (divPor3 > 1)? "divisíveis por 3": "divisível por 3"
);
```

E o código final ficou assim:

```c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){

   // declaração e leitura de variáveis
   int n1, n2, n3;

   printf ("Digite 3 números: ");
   scanf ("%i %i %i", &n1, &n2, &n3);

   // declaração e inicialização dos contadores
   int impar = 0, par = 0, divPor3 = 0;

   // se o número for divisível por 2 incremente par senão incremente impar
   ( n1 % 2 == 0 )? par ++: impar ++;
   ( n2 % 2 == 0 )? par ++: impar ++;
   ( n3 % 2 == 0 )? par ++: impar ++;

   // se é divisível por 3 incremente senão não incremente
   divPor3 = ( n1 % 3 == 0 )? divPor3 + 1: divPor3;
   divPor3 = ( n2 % 3 == 0 )? divPor3 + 1: divPor3;
   divPor3 = ( n3 % 3 == 0 )? divPor3 + 1: divPor3;

   // Hora de exibir os resultados

   printf(
      "%i%c%s %s", 

      impar,
      (impar == 0 )? '\b' : ' ',

      (impar == 0 )?  "nenhum é" :
         ( (impar == 1 )? "é" : "são" ) ,

      (impar > 1)? "ímpares": "ímpar"
   );

   printf(
      "%i%c%s %s", 

      par,
      (par == 0 )? '\b' : ' ',
      (par == 0 )? "nenhum é" :
         ( (par == 1 )? "é" : "são" ),

      (par > 1)? "pares": "par"
   );

   printf(
      " e %i%c%s %s\n", 

      divPor3,
      (divPor3 == 0 )? '\b' : ' ',

      (divPor3 == 0 )? "nenhum é" :
         ( (divPor3 == 1 )? "é" : "são" ),

      (divPor3 > 1)? "divisíveis por 3": "divisível por 3"
   );

   return 0;
}
```

### Desafio 4

Faça um programa que leia 3 números e diga qual é o maior e qual é o menor, e se a pessoa digitar números iguais, ele tem que avisar "foram digitados números iguais".

> Saída:

```
Digite 3 números:2
3
3

O número 1 é o menor
O número 3 é o maior

foram digitados números iguais
```

Este você tem que fazer sozinho, todas as coisas necessárias para fazê-lo foram ensinadas. Boa sorte e se não conseguir fazer, releia os capítulos anteriores com muito cuidado, e depois tente de novo.
