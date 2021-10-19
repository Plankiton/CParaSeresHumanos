# Conceitos interessantes

## Modificadores de tipo

E mais uma vez falaremos de tipos primitivos, como havíamos visto, os tipos primitivos têm tamanhos diferentes na memória, e estes tamanhos podem ser expandidos ou reduzidos.

### Long

O `long` alonga (expande) a capacidade de variáveis do tipo `int`, `float` e `double`.

> Lembrando que os valores de tamanho variam de computador para computador.

```c
int inteiro = 0;              // 4 bytes
long int l_inteiro = 0;       // 8 bytes

double real = 10E49;          // 6 bytes
long double l_real = 10e49;   // 8 bytes
```

E para alcançar o máximo de tamanho de uma variável para a sua arquitetura use o `long long int` ou simplesmente `long long`.

### Short

O `short` encurta a capacidade de variáveis do tipo `int`.

```c
int inteiro = 0;              // 4 bytes
short int s_inteiro = 0;      // 2 bytes
```

### Signed e unsigned

`signed` e `unsigned` significam respectivamente "com sinal" e "sem sinal".

```c
int c = 90;
int i = +90;
int j = -90;
```

Sempre que você declara um número, ele por padrão é `signed`, portanto suporta números negativos e positivos, e o `unsigned` só suporta números positivos.

```c
int inteiro = 0;               // intervalo: -2147483648 a 2147483647
unsigned int us_inteiro = 0;    // intervalo: 0           a 4294967295
```

## Entrada e saída de dados

Você já viu anteriormente uma forma de saída de dados: o `printf`:

```c
printf("Hello mundo!!\n");
```

> Sem este `\n`, caso você escreva outra coisa os dois irão aparecer juntos.

### Caractere de scape ( "\\" )

O caractere de scape, no C, é o `\` e ele dá "poderes" ao seu texto, pode ser usado em variáveis do tipo `char` e em strings, mas para ilustrá-lo eu irei representá-lo sempre dentro de um `printf`.

#### \n

```c
printf("\n1ª linha\n2ª linha\n3ª linha\n");   // \n: quebra de linha.
```

Esse `\n` é uma quebra de linha, ou seja, sempre que tiver um `\n` o `printf` vai pular uma linha e escrever o que estiver na frente.

> saída:
```
1ª linha
2ª linha
3ª linha
```

#### \t

```c
printf("\tjoao"); // \t: espaçamento ou tabulação (efeito da tecla "tab").
```

Esse `\t` é uma tabulação, o que estiver a frente dele irá se deslocar para a direita (->).

> saída:
```
   joao
```

#### \b

```c
printf("joao\b");  // \b: apaga um caractere da linha (efeito da tecla "backspace").
```

Esse `\b` é um backspace, o caractere anterior a ele será apagado.

> saída:
```
joa
```

#### \r

```c
printf("coisas mais coisas\r outras coisas"); // \r: elimina tudo o que está antes dele na linha.
```

Esse `\r` vem de "remove", todos os caracteres da mesma linha e anteriores a ele serão apagados.

> saída:
```
 outras coisas
```

#### \v

```c
printf("coisas\voutrascoisas\vjoao\v."); // \v: tabulação vertical.
```

O `\v` vai quebrar a linha assim como o `\n`, mas em vez de iniciar a nova no inicio da linha, ele inicia no "final" da anterior, formando uma "escadinha".

> saída:
```
coisas
      outrascoisas
                  joao
                      .
```

#### \\"

```c
printf("\"joao\" é um nome feio"); // \": exibe as aspas duplas.
```

Exibe as aspas duplas ( `"` ), pois se você escrever simplesmente `"` o C vai achar que aquele é o fim da string.

> saída:
```c
"joao" é um nome feio
```

#### \\\'

```c
printf("it\'s estranho"); // \': exibe as aspas simples ou apótrofos.
```

Exibe a aspa simples (que alguns chamam de apóstrofo).

> saída:
```
it's estranho
```

#### \\\\

```c
printf("isso é uma contra-barra: \\");     // \\: exibe a contra-barra
```

> saída:
```
isso é uma contra-barra: \
```

