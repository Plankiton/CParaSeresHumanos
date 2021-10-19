# Entrada e saída de dados

### printf

_"Mas e se eu quiser imprimir uma variável?"_ ... é só usar a formatação de texto do `printf` ... _"Mas como se usa isso?"_ ... para imprimir uma variável `int` é só escrever um `%i` ou `%d` dentro da string. Se for um `char`, escreva `%c` na string, se for `float`, escreva `%f`, se for uma notação científica (geralmente usada no tipo `double`), escreva `%E`( se estiver usando o "e" maiúsculo) e `%e` para o "e" minúsculo, após escrever a formatação desejada, é só listar as variáveis separando por vírgula ligo após a string... _"Eu não entendi nada do que tu disse!"_ ...Relaxa... Olhe o exemplo e suas dúvidas em relação a isso irão desaparecer:

```c
int numero = 90;
char caractere = 'A';
float real = 9.23;
double real_em_dobro_E = 9.4E13;
double real_em_dobro_e = 9.4e13;

printf("numero inteiro: %i", numero);
printf("numero real: %f", real);
printf("numero real notação cientifica com \"E\": %E", real_em_dobro_E);
printf("numero real notação cientifica com \"e\": %e", real_em_dobro_e);
printf("caractere: %c", caractere);
```

> saída:

```
numero inteiro: 90
numero real: 9.23
numero real notação cientifica com "E": 9.4E13
numero real notação cientifica com "e": 9.4e13
caractere: A
```

### scanf

O scanf é semelhante ao printf, mas serve para ler dados:

```c
int numero;

scanf("%i", &numero);
```

Tá, eu sei que você está se perguntando _"e esse_ `&` _serve pra que?"_ Esse `&` diz para o `scanf` colocar o valor no lugar da memória onde está o número. O `&` simboliza um endereçamento de memória, o `scanf` coloca o valor direto no local da memória onde está a variável.

E como você pode perceber o `%i` se refere a um número inteiro. Todos os tipos de variáveis são simbolizados pelos símbolos (`%i`, `%c`, `%f`...) do `printf`.

Também é possível ler várias variáveis com um único comando:

```c
int numero;
char caractere;
float real;

printf("digite um numero um caractere e um numero real: \n");
scanf("%i %c %f", &numero, &caractere, &real);

printf("\nnumero inteiro: %i", numero);
printf("numero real: %f", real);
printf("caractere: %c", caractere);
```
> Na hora de ler um `char`, às vezes o `scanf` buga, isso ocorre quando ele recebe lixo do teclado, você só precisa ler a variável duas vezes, isso geralmente ocorre com `char`, mas se acontecer com outro tipo, a resolução para o problema é a mesma:

```c
fflush(stdin); // esse comando vai limpar o lixo da memória
```

> Saída:
>
```
digite um numero, um caractere e um numero real:
3458
J
5.8769
>
numero inteiro: 3458
numero real: 5.8769
caractere: J
```

Esses não são os únicos métodos de entrada e saída de dados, mas veremos outros em outros capítulos, esses são o bastante para prosseguirmos nossos estudos.

### Formatos do printf e scanf

#### %s

Strings ou texto, exemplo:

```c
printf("string: '%s'\n", "string");
```

#### %d e %i

Inteiros, exemplo:

```c
printf("int: %i\n", 90);
```

#### %f

Reais, exemplo:

```c
printf("float: %f\n", 9.3);
```

E como são números com `.` você pode formatar a saída deles, o `9.3` vai ser exibido como `9.300000`, mas eu quero que saia `9.3`

```c
printf("float: %.1f\n", 9.3);
```

> Notem que entre o `%` e o `f` existe um `.1`, isso quer dizer que só é para exibir `1` numero após a "vírgula"(que no C é um `.`).

O protótipo é mais ou menos assim:

```c
printf("%.<decimais>f\n", <numero>);
```

#### %c

Caracteres, exemplo:

```c
printf("char: %c\n", 'A');
```

#### %o

Numeros octais, exemplo:

```c
printf("int: %o\n", 018);
```

> Numeros octais iniciam com `0`, logo `012` é o mesmo que `10`

#### %u

Numeros sem sinal, exemplo:

```c
printf("int: %u\n", 18);
```

#### %x

Numeros hexadecimais, exemplo:

```c
printf("int: %x\n", 0xDB7B5);
```

> Todo hexadecimal começa com `0x`.

#### %l

Numeros longos (sempre acompanhado pelo tipo alongado), exemplo:

```c
// Reais longos
printf("double: %lf\n", (double) 9.3);

// Inteiros longos
printf("long int: %li\n", 698);
```

### Putchar e puts

Basicamente o "put" significa coloque, logo, `putchar` é coloque um `char`:

```c
char c = '\n';

putchar ('j');
putchar ('o');
putchar ('ã');
putchar ('o');
putchar ( c );
putchar ('!');
putchar ( c );
```

> Saída:

```
joao
!
```

E seguindo a mesma lógica, `puts` é coloque uma string ( o `s` é uma abreviação ).

```c
char * str = "string coisada";

puts ( "joao" );
puts ( "!" );

puts ( str );
```

> Saída:

```
joao
!
string coisada
```

> Uma particularidade do `puts` é que ele adiciona um `\n` no fim da string.

### Getchar e gets

Assim como o `scanf`, o `getchar` e o `gets`, são funções para leitura de dados, mas que só servem para ler variáveis do tipo `char` e strings.

É assim que se usa o `getchar`:

```c
char j;

j = getchar();
```

E o `gets` é usado assim:

```c
char str [20];
gets(str);
```
> Mesmo o `gets` sendo uma função contraindicada pela comunidade, ela ainda funciona, então caso o gcc aponte erros pelo uso do `gets`, saiba que ela vai funcionar normalmente.

### Fprintf e fgets

O `f` antes do `printf` significa formatação, logo, um `fprintf` é um `printf` formatado, e essa formatação é basicamente um parâmetro a mais indicando o lugar onde você quer escrever a informação.

```c
fprintf(stdout, "Hello mundo!!\n"); // printf ( "Hello mundo!!" )
```

> O `stdout` é um "stream" ( local para onde vai a string do `fprintf` ), e o `printf` é um `fprintf` com o `stdout` como "stream", e o `stdout` é a saída padrão (a tela).

Mas também é possível enviar a saída para outros streams, dentre eles nós temos o `stderr`, que é a saída padrão de erros:

```c
char coisa [30];

puts("escreva de 1 a 10 caracteres: ");
scanf ("%s", &coisa );

if (coisa [0] == '\0' ) {
   fprintf ( stderr, "ERROR: você não digitou nenhum caractere!");
   return 1;
}

if (coisa [10] != '\0' ) {
   fprintf ( stderr, "ERROR: você digitou caracteres demais!");
   return 1;
}
```

> No programa acima são pedidos caracteres de 1 a 10, então se o caractere da posição `0` corresponder ao fim de uma string (`'\0'`) quer dizer que 0 caracteres foram lidos, e se o 11º caractere (posição `10`) for o fim da string (`'\0'`) quer dizer que existem mais de 10 caracteres na string.

Note que quando ocorreu um erro o valor retornado foi o `1`, indicando para o sistema operacional que aconteceu um erro.

O `fgets` seria um `gets` formatado, e ele funciona da seguinte maneira:

```c
char str[10];

fgets ( stdin, 10, str ); // gets (str)
```

> O `stdin` é a entrada de dados padrão (o teclado).

_"Ué? Então por que eu deveria usar esse `fgets` aí se o `gets` é mais simples?"_ ...Muito simples, lembra que o `gets` tem um problema, tanto que ele é contra-indicado pelo próprio compilador? Pois é, o `fgets` não tem esse problema, porque nele além de você indicar a string a ser lida e o "stream", ele exige que você coloque o tamanho da string, assim evitando colocar dados no lugar errado.

