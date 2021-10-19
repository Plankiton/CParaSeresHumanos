# Ponteiros

Os ponteiros ou pointers no inglês, são variáveis que guardam endereços de memória.

Lembra do `&` antes da variável no `scanf`?

```c
int n;
scanf("%i", &n);
```

Este `&` indica um endereço de memória da variável `n`, e para guardar este endereço em uma variável, é necessário que agente crie um ponteiro:

```c
int n = 9;
int * ponteiro_n = &n;
```

Este `*` antes do nome da variável diz para o C que esta variável vai guardar endereços de memória... _"Mas porque colocar um tipo se a variável vai guardar só endereços? Por acaso endereço tem tipo?_ ... Não é bem assim, temos que dar um tipo ao ponteiro porque ele também tem tamanho, e para que consiga armazenar o endereço de uma variável ele tem que ter o mesmo tamanho.

_"Tá, mas ainda não entendi a utilidade desse negócio!"_ , acho que essa mentalidade vai mudar assim que você descobrir que um array é um ponteiro que aloca vários espaços na memória.

Existem algumas regras sobre o uso de ponteiros, por exemplo:

```c
int i = 90;

int * p = &i; // o ponteiro "p" agora aponta para a variável "i"

printf("%i\n", *p);
```
> Quando damos o endereço de memória de uma variável para um ponteiro, nós dizemos que esse ponteiro aponta para essa variável

No exemplo acima, declaramos um ponteiro `p` apontando para `i`, agora nós podemos ter acesso ao valor de `i` apenas adicionando um `*` antes do `p`, e com isso conseguimos exibir o valor de `i` na tela com o `printf`.

E usando esse `*` também podemos alterar o valor de `i`:

```c
int i = 90;

int * p = &i;
*p = 89;
```
> Só que nós estamos alterando o valor diretamente na memória, e uma prova disso é que se você incrementar o ponteiro `p`, terá acesso a outro endereço de memória.

```c
int i = 90;
int * p = &i;

p ++;

*p = 89;
```

Quando você executar o código acima irá ocorrer um erro de segmentação (quando o programa tenta acessar uma memória que não pertence a ele) ou se não ocorrer erro, quer dizer que ele acessou um espaço de memória desconhecido, e quando este ultimo ocorre o valor que está nesse espaço é um lixo do sistema ou o local onde está alocada outra variável.

```c
int a[] = { 2, 4, 5, 6};

printf("%i\n", a[1]); // 4

a ++;
printf("%i\n", * a);  // 4
```

Como um array é um ponteiro, nós podemos usar o array como um ponteiro, _"Mas por que você incrementou o `a` antes de exibi-lo?"_ , porque se eu usá-se o endereço original, o valor exibido seria o `2`, pois o endereço de memória sempre se refere ao primeiro valor.

Mas o método que usei anteriormente não é muito adequado já que uma vez que você incremente o array ele estará apontando para outra posição e assim você tem que decrementar toda vez, o que não é prático, então, a forma mais indicada para isso seria:

```c
int a[] = { 2, 4, 5, 6};

printf("%i\n", a[1]);     // 4

printf("%i\n", *(a+1) );  // 4
```
> Desta forma o valor de `a` não será alterado.

Isso também serve para atribuir valor aos itens de um array.

```c
int a[] = { 2, 4, 5, 6};

a[1] = 90;

*(a+2) = 56
```

Notem que o índice ( o valor entre `[` e `]` ), é somado a `a`, isso acontece porque um array cria uma fila de espaços do mesmo tipo, uma do lado da outra, por isso `*(a+3)` é o mesmo que `a[3]`.

## Alocação dinâmica (arrays dinâmicos)

Em alguns casos, precisamos de mais espaço do que a variável comum para guardar dados, e para esses casos geralmente usamos arrays, mas e se durante a execução eu necessite de um array maior... _"É só criar um array maior e usar ele para a manipulação do novos dados!"_ ... Isso pode até funcionar, mas não é recomendável, pois seria um desperdício de memória.

Para resolver isso nós podemos alocar a quantidade de memória que queremos (em bytes) e usar um ponteiro com este endereço de memória, e se quisermos um espaço maior, é só realocar a memória deste ponteiro, assim nós poderemos aumentar e diminuir o tamanho do array.

> E como prometi no capítulo sobre strings... Esta é a terceira forma de atribuir uma string:

```c
char * str;
str = "string";
```

> Isto só funciona com strings, arrays de outros tipos tem que ser atribuídos item a item.


O próprio exemplo da atribuição de uma string é um exemplo de alocação dinâmica, mas ela é feita automaticamente:

```c
char * str;          // aqui temos um ponteiro vazio.
str = "coisa";       /* 
                        aqui nós alocamos 6 bytes na memória para
                        guardar { 'c', 'o', 'i', 's', 'a', '\0' }
                     */

printf("%s\n", str);

str = "outra coisa"; /*
                        aqui nós realocamos o espaço de 6 bytes
                        para 12 bytes e assim podemos guardar 
                        { 
                           'o', 'u', 't', 'r', 'a', ' ',
                           'c', 'o', 'i', 's', 'a'
                        }
                     */

printf("%s\n", str);
```

Se fossemos fazer o código acima usando puramente ponteiros, nós faríamos assim:

> Lembrando que ao alocar espaços e referenciando com ponteiros, nós estamos criando arrays.

Antes de mais nada você tem que incluir o `stdlib.h` no seu arquivo (para evitar erros, sempre faça qualquer `include` no inicio do arquivo)

```c
#include <stdlib.h>           // biblioteca necessária para usar as funções de alocação.
```
> Para garantir inclua esta biblioteca em todos os exemplos a partir daqui.

Agora sim, podemos continuar...

```c

char * str;                   // aqui temos um ponteiro vazio.

str = malloc (6);             // aqui nós alocamos 6 bytes na memória.

// guardando dados...
*( str + 0 ) = 'c';   // str[0] = 'c';
*( str + 1 ) = 'o';   // str[1] = 'o';
*( str + 2 ) = 'i';   // str[2] = 'i';
*( str + 3 ) = 's';   // str[3] = 's';
*( str + 4 ) = 'a';   // str[4] = 'a';
*( str + 5 ) = '\0';  // str[5] = '\0';

printf( str );
putchar('\n');

str = realloc (str, 12);        // aqui nós realocamos o espaço de 6 bytes para 12 bytes

// guardando dados...
str = "outra coisa";
str[12] = '\0';

printf("%s\n", str);

free( str );           /*
                           essa linha vai no fim do programa e serve
                           para liberar a memória que nó alocamos,
                           para não ocorrerem erros sempre temos
                           que liberar a memória.
                       */

```

> Note que o ultimo printf está antes do `free`, pois se ele estiver depois, vai dar erro já que o espaço alocado anteriormente seria apagado.

A saída de ambos os códigos é a mesma:

```
coisa
outra coisa
```

_"Ah então eu vou sempre usar a primeira forma, porque é mais fácil!"_ , use, mas não se esqueça que a primeira forma só funciona com strings, para outros tipos de arrays você terá que usar a segunda forma.

Só para fixar melhor veja como funcionariam o array dinâmico com o tipo `int`.

```c

// alocando a memória que o array terá
int * array_dinamico = malloc ( sizeof (int) * 4); /*
                                                aqui nós alocamos um espaço que caiba 4 inteiros,
                                                pois o nosso array inicial terá 4 posições.
                                              */

array_dinamico [0] = 2;
*( array_dinamico + 1) = 3;
array_dinamico [2] = 23;
array_dinamico [3] = 894;

// realocando memória para que caibam 5 posições
array_dinamico = realloc ( array_dinamico , sizeof (int) * 5);

array_dinamico [0] = 2;
*( array_dinamico + 1) = 3;
array_dinamico [2] = 23;
array_dinamico [3] = 894;
*( array_dinamico + 4) = 34;
```

> Lembre-se de alocar a quantidade certa de memória para o ponteiro, ao contrário dos arrays aqui você tem que saber a quantidade exata de bytes reservar, um macete muito útil é:

```c
<tipo> * <variável> = malloc ( sizeof (<tipo>) * <quantidade de posições>);
```

> Desta forma a quantidade de bytes necessária será sempre respeitada.

E de quebra vai aí uma dica extra sobre arrays dinâmicos, eles podem ser atribuídos diretamente, é só colocar um `(<tipo> [])` antes do array que você quer atribuir:

> Mas cuidado, arrays normais não aceitam isso, só use em arrays dinâmicos

```c
// Array normal
int a[3] = {0, 1, 2};
a = (int []){1, 2, 3};          // Não funciona!

// Array dinâmico
int * ad = {0, 1, 2};
ad = (int []){1, 2, 3};         // Funciona!
```

