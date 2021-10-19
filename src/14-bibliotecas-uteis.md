# Bibliotecas Úteis

Até agora só usamos duas bibliotecas em nossos porgramas em C, e não vimos nem 10% dessas, então para deixar seu conhecimento mais completo aqui vamos mostrar algumas funções dessas duas bibliotecas, além de outras que também podem ser bem interessantes.

## stdio.h

```c
#include <stdio.h>
```

Como já vimos as funções `scanf`, `printf`, `putchar`, `puts`, `getchar`, `gets`, `fprintf` e `fgets`, iremos ignorá-las.

O `std` significa exclusivamente "standard" ("padrão" em português), `i` é de "input" (entrada) e o `o` de "output" (saída), portanto entrada e saída de dados padrão.

### I/O em arquivos

Como o `stdio` serve para entrada e saída de dados, óbviamente também é usada para manipulação de arquivos, usada tanto para ler (input), quanto para escrever (output) neles.

Para ler um arquivo precisamos criar um ponteiro do tipo `FILE`

```c
FILE * arquivo;
```

#### Leitura

> crie um arquivo `j.txt` com "joao" escrito dentro

Para abrir o arquivo `j.txt` no nosso programa, é só usar a função `fopen`.

```c
arquivo = fopen("j.txt", "r");
```

> O `"r"` no segundo parametro é o modo desse arquivo, nesse caso, abrimos um arquivo em modo leitura.

Para ler e exibir o que foi lido é só usar o `fgetc`:

```c
char caractere = fgetc(arquivo);
```

> O `fgetc` retorna um caractere de cada vez, e quando le o caractere, quando você for ler de novo ele lerá somente o próximo, exemplo:

```c
// suponha que o arquivo "texto.txt" tem "abc" escrito dentro
FILE *f = fopen("texto.txt", "r");
char a, b, c;

b = fgetc(f); // -> "a"
c = fgetc(f); // -> "b"
a = fgetc(f); // -> "c"

print("%c %c %c\n", a, b, c);
```

> Saída:

```
c a b
```

Lembre-se que o fim de um arquivo é demarcado por uma constante chamada de `EOF` (significa "end of file" ou "fim do arquivo"), logo, se voce usar um loop, para ler o tal arquivo, usem o `EOF` como "flag"

> "flag" é a condição de interrupção

```c
char caractere;
do {
  caractere = fgetc(arquivo); // -> <caractere> = fgetc(<arquivo>)
  putchar(caractere);
} while (caractere != EOF);
```

E depois de terminar de usar, assim como você tem que liberar a memória com o `free` trabalhando com ponteiros, você tem que fechar o arquivo, ou ele vai ficar ocupando memória à toa

```c
fclose(arquivo);
```

E ficaria assim:

```c
FILE * arquivo;
arquivo = fopen("j.txt", "r");

char caractere;
do {
  caractere = fgetc(arquivo);
  putchar(caractere);
} while (caractere != EOF);
fclose(arquivo);
```

Na minha humilde opnião é muito melhor ler os dados caractere por caractere porque assim se tem mais controle dos dados, mas existem outras funções que auxiliam nisso.

O `fscanf` lê dados do arquivo e joga na variável estipulada:

```c
FILE *arquivo = fopen("texto.txt", "r");

char * texto_do_arquivo = malloc(10);
fscanf(arquivo, "%s", texto_do_arquivo);

printf ("%s", texto_do_arquivo);

fclose(arquivo);
free(texto_do_arquivo);
```

>  Não usei a forma de array aqui porque aparentemente o `fscanf` crachou comigo, mas sinta-se a vontade para testar se isso acontece com você também...

O `fscanf` vai ler até o primeiro espaço ou a primeira quebra de linha (`\n`).

Também dá pra fazer com o já conhecido `fgets`:

```c
FILE *f = fopen("f.txt", "r");

char str [100];
fgets (f, 100, str); // -> fgets ( <arquivo>, <tamanho da string>, <string> )

fclose(f);
```

E por fim com o `fread`, que é uma forma mais direta de ler os dados, mas para usar o `fread` você tem que saber o limite da leitura ( que no nosso caso é o fim do arquivo), e para descobrir isso, nós vamos usar duas funções chamadas `fseek` e `ftell`.

```c
fseek(arquivo, 0, SEEK_END); // mudando o "cursor" para o fim do arquivo
size_t tamanho_arquivo = ftell(arquivo); // pegando a posição do cursor
fseek(arquivo, 0, SEEK_SET); // colocando o cursor no inicio de novo
```

Feito isso é só ler usando o `fread`

```c
fread(      texto,        sizeof (char),              tamanho_arquivo, arquivo );
//   ( <ponteiro>, <tmh do tipo do ptr>, <limite da leitura em bytes>, <arquivo> )
```

E vai ficar assim:

```c
FILE *arquivo = fopen("f.txt", "r");

fseek(arquivo, 0, SEEK_END); // mudando o "cursor" para o fim do arquivo
size_t tamanho_arquivo = ftell(arquivo); // pegando a posição do cursor
fseek(arquivo, 0, SEEK_SET); // colocando o cursor no inicio de novo

char * texto = malloc( tamanho_arquivo );

fread( texto, sizeof (char), tamanho_arquivo, arquivo );

free(texto);
fclose(arquivo);
```

> O conteúdo do arquivo vai ser escrito na variável `texto`

#### Escrita

Para abrir um arquivo em modo escrita ao invés de colocar o `r` no parametro do `fopen`, colocamos um `w`:

```c
FILE *arquivo = fopen("texto.txt", "w");
```

> Nesse caso, se o arquivo não existir, ele será criado, mas se existir um arquivo ele perderá todos os seus dados.

Para escrever um `char` em um arquivo usamos a função `fputc`

```c
fputc('a', arquivo); // -> fputc( <char>, <arquivo> )
```

Para escrever uma string use o `fputs`

```c
fputs("string com coisas", arquivo); // -> fputs(<string>, <arquivo>)
```

Ou se quiser escrever um dados formatado use o já estudado `fprintf`

```c
fprintf ( arquivo, "%i > %i = %s", 4, 3, (4 > 3? "True": "False"));
```

E por fim você pode usar o irmão do `fread`, o `fwrite`:

```c
char texto [] = "texto aleatorio para colocar no arquivo";
fwrite( texto, sizeof (char), sizeof(texto), arquivo );
```

Mas esses não são os únicos modos de abertura de um arquivo

```c
"r"  // -> read: somente leitura
"w"  // -> write: somente escrita, mas apaga o conteúdo do arquivo antes de escrever
"a"  // -> append: somente escrita
"r+" // -> read/write: leitura e escrita
"w+" // -> read/write: leitura e escrita, mas apaga o conteúdo do arquivo antes de escrever
"a+" // -> read/append: leitura e escrita
```

> Faça seus testes com cada um deles, para ver funcionando na prática

Você já deve ter percebido que as mesmas funções que usamos em arquivos, são usadas na `stdout`, `stdin` e `stderr`, não é mesmo?
Isuuso acontece, porque essas 3 variáveis são arquivos, e por esse motivo você pode usar todas as funções usadas em arquivos colocando elas no lugar, mas lembre-se, o `stdout` e o `stderr` estão em modo `"w"`, enquanto o `stdin` está em modo `"r"`, portanto, você só pode escrever no `stdout` e no `stderr`, e só pode ler o `stdin`. Divirta-se!

### Posicionamento em arquivos

Para "finalizar" este assunto, existem algumas funções que podem ser úteis na manipulação de arquivos, como o `fseek` (que já foi visto de maneira superficial)

> Não vamos finalizar totalmente porque ainda faltam algumas funções, que agente vai ver no capítulo de `stdarg.h`

```c
FILE *j = fopen("j.txt", "r");

fseek( j, 0, SEEK_SET); // passa o cursor para o inicio do arquivo
fseek( j, 0, SEEK_CUR); /* passa o cursor para a posição atual do ponteiro
                           se ja tiver lido 3 caracteres, o cursor volta para
                           o caractere 3
                        */
fseek( j, 0, SEEK_END);
```

Caso queira retornar para o inicio do arquivo, você pode usar a versão simplificada do `fseek` que se chama `rewind`

```c
FILE * arquivo = open("j.txt", "r");
rewind( arquivo );
```

A função `ftell`, também já vista retorna a posição atual do cursor

```c
FILE *j = fopen("j.txt", "r");

char c;
while ((c = fgetc(j)) != 'a')
  putchar(c);

printf("\n%li\n", ftell(j));
```

Mas caso você precise de mais controle nesse posicionamento é só usar as funções `fgetpos` e `fsetpos`

```c
// j.txt -> "abcdefghijklmnop"
FILE * arquivo = fopen("j.txt", "r+");

fpos_t posicao; // tem que ser deste tipo para funcionar

fgetpos(arquivo, &posicao); // pegando a posição
printf("posicao: %p\ncaractere: %c", &posicao, fgetc(arquivo));
fseek( arquivo, 0, SEEK_SET );

fsetpos(arquivo, &posicao + 4); // mudando posição para o 4 caractere
fgetpos(arquivo, &posicao);     // pegando a posição de novo

getchar();

printf("posicao: %p\ncaractere: %c\n", &posicao, fgetc(arquivo));
fclose ( arquivo );

getchar();
```

> Saída:
```
posicao: 0x7ffddf294270
caractere: a
posicao: 0x7ffddf294270
caractere: e
```

### Operações com arquivos

Para apagar o arquivo é só usar a função `remove`

```c
remove("j.txt");
```

E para renomear é só usar `rename`

```c
rename(       "j.txt",  "joao.txt");
//    ( <nome antigo>, <nome novo>)
```

A função `reopen` é muito útil para mudar o destino de arquivos, exemplo:

```c
freopen("j.txt", "w", stdout);
fprintf("joao é uma pessoa!!\n", stdout); // o resultado não será impresso na tela, mas no arquivo "j.txt"
```

Além de todas essas, lembra de quando imprimimos mensagens na saída de erro (`stderr`) com `fprintf`? na `stdio.h` existe uma que faz isso automaticamente; é o `perror`

```c
perror("ferrou!!");
```

Para outras informações sobre a biblioteca veja a [referência](https://pt.wikibooks.org/wiki/Programar_em_C/Entrada_e_sa%C3%ADda_simples) que está no [wikibooks](https://pt.wikibooks.org) sobre ela.

## stdlib.h

```c
#include <stdlib.h>
```

A `stdlib.h` é com certeza uma das bibliotecas mais importantes do C, portanto, merece ser dicecada aqui.

E as funções que já vimos dela foram as de gerenciamento de memória (`malloc`, `free`, `realloc`), logo, não iremos revê-las.

### Conversões entre string e outros tipos

```c
double     d = atof ("8.9"); // atof(<valor>): de string para double
int        i = atoi ("89");  // atoi(<valor>): de string para inteiro
long       l = atol ("999"); // atol(<valor>): de string para long
long long ll = atoll ("99"); // atoll(<valor>): de string para long long
```

### Sistema

Caso queira abortar o programa, você pode usar a função `exit`, e assim como no `return` do main, você escolhe o valor que quer retornar para o SO

```c
int i;

scanf("%i", &i);
if (i%2)
  exit(0); // se for impar saia
else
  exit(1); // senao saia e retorne um erro
```

Outra função relacionada ao fechamento do programa é a função `atexit`, que registra funções que serão executadas quando o programa finalizar, sendo que estas funções não podem retornar valores e nem receber parametros.

```c
#include <stdio.h>
#include <stdlib.h>

void tmp_file_remove (void){
  remove("/tmp/at_exit_lock");
}

int main(){
  FILE * tmp = fopen("/tmp/at_exit_lock", "w");
  atexit(tmp_file_remove);

  // pausando a execução
  puts("não click em enter ainda... olhe se há um arquivo \"at_exit_lock\" na pasta /tmp/");
  getchar();

  puts("agora veja se ainda está lá");
  fclose (tmp);
  return 0;
}
```

Outra semelhante à `atexit` é a `at_quick_exit`, que vai ser executada quando o programa for interromido usando a função `quick_exit`

```c
#include <stdio.h>
#include <stdlib.h>

void tmp_file_remove (void){
  remove("/tmp/at_exit_lock");
}

int main(){
  FILE * tmp = fopen("/tmp/at_exit_lock", "w");
  atexit(tmp_file_remove);

  // pausando a execução
  puts("não click em enter ainda... olhe se há um arquivo \"at_exit_lock\" na pasta /tmp/");
  getchar();

  fclose (tmp);
  quick_exit(0);

  // essa parte não vai executar
  puts("agora veja se ainda está lá");
  return 0;
}
```

Outra variável de sistema muito útil é a `getenv`, que retorna o valor de uma variável de ambiente.

```c
char path = getenv("PATH"); // caminhos para executáveis no linux ($PATH)
```

E as mais úteis de todas, com essas você vai conseguir executar comandos do sistema operacional

```c
system( "echo hello mundo!" ); // system( <comando> )
```

Mas a `system` executa e manda o resultado para a `stdout`, se você quiser acessar o valor de retorno, tem que usar a função `popen` (que retorna um `stream`, logo, você vai ter que tratá-la como um arquivo)

> A função popen não funciona no C99, se seu compilador usa C99, não irá compilar.

```c
FILE *response = popen("echo hello mundo!", "r"); // popen( <comando> )

char comando [20];
fgets(comando, 20, response);
printf("o a resposta do comando usado foi:\n%s\n", comando);
```

Ainda faltam algumas funções mas essas são as mais importantes (contando com as de alocamanto de memória),  para outras informações sobre a biblioteca, consulte a [referência](https://pt.wikipedia.org/wiki/Stdlib.h) feita por alguém na [wikipedia](http://wikipedia.org/wiki/Stdlib.h).

## math.h

```c
#include <math.h>
```

Com certeza toda linguagem que se presa tem uma biblioteca de matemática, a `math.h` tem diversas funções para resolução de problemas matemáticos desde arredondamento até trigonométricos.

### Funções de arredondamento

Digamos que o valor de uma operação dê `1.7`, se quisermos arredondá-lo para cima usamos a função `ceil`:

```c
printf("%f\n", ceil(1.7));
```

Mas se quisermos arredondá-lo para um número menor usamos a função `floor`:

```c
printf("%f\n", floor(1.7));
```

E se quiser apenas cortar a parte decimal use o `trunc`:

```c
printf("%f\n", trunk(1.7));
```

Outra opção é arredondar para o número inteiro mais próximo, seja ele acima ou abaixo:

```c
printf("%f\n", round(1.7));
```

A função `round` tem algumas variações como o `lround` que arredonda para um `long int` e o `llround` que arredonda para um `long long int`.

### Potencia e radiciação

Para realizar uma potenciação é só usar a função `pow`

```c
printf("40 ao quadrado é %.0f", pow(40, 2));
```

E caso queira fazer uma raiz quadrada é só usar a função `sqrt`

```c
float n = pow(40, 2);
printf("a raiz quadrada de %.0f é %.0f", n, sqrt(n) );
```

E raiz cúbica é `cbrt`

```c
float n = pow(40, 3);
printf("a raiz quadrada de %.0f é %.0f", n, cbrt(n) );
```

E caso você queira fazer uma raiz de índice `5`, `4` ou qualquer outro número, lemre-se que uma radiciação é apenas uma potencia elevada à um expoente "ao contrário":

> 2 normal é igual a 2/1, 2 ao contrário é igual a 1/2

```c
// vou usar o expoente 2 mas funciona com qualquer valor
int numero = pow(5, 2);                  // 25
int outro_numero = pow(numero, 1.0/2.0); // 5

printf("5²  = %i\n√25 = %i\n", numero, outro_numero);
```

> E não esqueça dos `.0` após o número se você não fizer isso o valor do expoente vai ser um inteiro e portanto, será `0`, lunca se esqueça de checar os tipos primitivos...

E existe uma rotina exclusiva para cálculo de hipotenusa:

```c
int cateto_oposto = 8, cateto_adjacente = 6;
int hipotenusa = hypot( cateto_oposto, cateto_adjacente );
```

A biblioteca de matemática tem diversas outras funções, logo, caso necessite fazer algoritmos matemáticos consulte a [referência da math.h](https://www.ufrgs.br/reamat/ComputacaoCientifica/livro/iapcel-a_biblioteca_mathh.html) feita pela [UFRGS](https://www.ufrgs.br)

## stdarg.h

```c
#include <stdarg.h>
```

A `stdarg.h` é uma biblioteca para tratamento de argumentos (ou parametros) de funções.

Até aqui você deve está se perguntando, _"como fazer funções como o `printf` ou o `scanf` que recebem um número indeterminado de argumentos?"_, exatamente usando esta biblioteca, mas preste atenção para entender como você pode usá-la em seus algorítmos.

Para essa biblioteca, vou explicar de uma maneira diferente, aqui nós vamos criar o `print`, que assim como o `printf`, irá esquever coisas na tela.

> Como vai ser a chamada do `print`

```c
// print ( <formato>, <dados> );

print( "isfsf", 90, " + ", 8.3, " = ", 90.0 + 8.3 );

// i -> %i/%d/%li
// s -> %s
// f -> %f/%lf
```

Na declaração da função tem que ter pelo menos 1 argumento fixo, e no nosso caso é o `formato`, todos os outros argumentos serão substituídos por um `...`

```c
void print( char * formato, ... );
```

Para acessar os dados no `...` nós primeiro temos que guardar eles em uma variável do tipo `va_list`

```c
void print( char * formato, ... ){
  va_list argumentos;
}
```

Esse va_list é um ponteiro com todos os argumentos, mas para pegarmos os certos temos que dizer para ele de onde começar a pesquisar usando o `va_start`

```c
void print( char * formato, ... ){
  va_list argumentos;
  va_start( argumentos, formato );
}
```

Agora iremos checar quantos dados estamos esperando, e depois pegar-los com a função `va_arg`

> Caso for usar valores em `char`, na hora de usar o `va_arg`, usem com `int`, ele não aceita `char` porque é muito pequeno.

```c
#include <string.h> // -> strlen
void print( char * formato, ... ){
  va_list argumentos;
  va_start( argumentos, formato );

  int argc = strlen(formato); // pegando a qntd de caracteres da string

  for (int i = 0; i<argc; i ++){
    if (formato[ i ] == 'i') // caso o dado esperado for um int
      printf( "%li", va_arg( argumentos,      long int ) );
      //             va_arg( <lista de args>,   <tipo> ) );

    if (formato[ i ] == 'f') // float
      printf( "%lf", va_arg( argumentos, double ) );

    if (formato[ i ] == 's') // string
      printf(va_arg( argumentos, char *));
  }
  putchar('\n');
  va_end( argumentos ); // fechando os argumentos
}
```

> O `va_arg`, assim como o `fgetf`, retorna o dado e passa para o próximo automaticamente.

E fim, essas são as únicas funções que existem nessa biblioteca. Mas como eu prometi no capítulo sobre `stdio.h` agora eu irei explicar sobre as funções que usam o `va_list` da `stdarg.h`

As funções do `stdio.h` que usam `va_list` fazem o mesmo que as outras, só que aceitam esse tipo de argumento, como o `vprintf`

```c
void escreva_numeros ( int qntd, ... ){
  va_list args;
  va_start( args, qntd );

  char * formato = malloc( qnt*3+1 );
  for (int i=0; i<qntd; i+=2){
    formato[i] = '%';
    formato[i+1] = 'i';
    formato[i+2] = 'i';
  }
  formato[ qnt*3 ] = '\n';

  vprintf(formato, args);

  va_end( args );
  free(formato);
}
```

E funciona da mesma maneira com as funções `vscanf` (`scanf`), `vsscanf` (`sscanf`), `vfscanf` (`fscanf`) ...

## string.h

```c
#include <string.h>
```

Esta é mais uma das bibliotecas que eu já falei, mas não me aprofundei, portanto irei ignorar as funções já mencionadas (`strlen`, `strcpy`).

A primeira função interessante é a `strncpy`, que ao invés de copiar a string inteira, copia apenas um número de caracteres

```c
char str[10];
strncpy(str, "joao e maria", 4); // copia até o 4 caractere
str[4] = '\0';                   // setando o fim da string

puts(str);
```

> Saída:

```
joao
```

Outra que também é bacana é a `strcat`, que serve para concatenar strings

```c
char str[] = "joao";
strcat(str, " e maria"); // strcat( <destino>, <destinatario> );
```

E existe a variação `strncat`, que concatena até um certo número de caracteres

```c
char str[] = "joao";
strncat(str, " e maria rosa", 8);
```

Uma função muito útil dessa biblioteca é a `strcmp` que compara duas strings

```c
char str [] = "joao", str2 [] = "maria";
int res = strcmp( str, str2 ); // strcmp( <str>, <str2> )

if ( res == 0 )
  puts("as strings são iguais");
else if ( res < 0 )
  puts("\"%s\" é menor que \"%s\"", str, str2);
else if ( res > 0 )
  puts("\"%s\" é maior que \"%s\"", str, str2);
```

E também existe a `strncmp` que funciona da mesma forma que a anterior, mas compara só até um certo caractere.

```c
char str [] = "joao", str2 [] = "joao e maria";
int res = strncmp( str, str2, 4 ); // strncmp( <str>, <str2>, <numero> )

if (res == 0)
  puts("os primeiros 4 caracteres da string 2 são iguais aos da string 1");
```

Outras opções são usar funções de pesquisa em strings, como o `strchr` que irá retornar um ponteiro para a primeira ocorrencia de um caractere

```c
char j[] = "abcdefghijklmnop;joao\0";
puts(strchr(j, 'g'));
puts(strchr(j, ';')+1);

char * f = strchr(j, ';');
* f = '\0'; /* finalizando a string
               na primeira ocorrencia
               de ";" */

puts(j);
```

> Saída:

```
ghijklmnop;joao
joao
abcdefghijklmnop
```

Outra bem bacana é a `strcspn` onde você passa uma certa lista de caracteres e ela irá retornar a primeira ocorrencia de qualquer caractere da lista

```c
char str[] = "bcdefgh";
printf("A vogal \"%c\" está na %iª posição de \"%s\"\n",
    str[ strcspn(str, "aeiou") ], strcspn(str, "aeiou")+1, str);
```

> Saída:

```
A vogal "e" está na 4ª posição de "bcdefgh"
```

Uma semelhante a `strchr` é a `strstr`, que retorna a string da primeira ocorrencia de um caractere até o seu fim

```c
char str[] = "joao maria ronaldo";
puts(strstr(str, "maria"));
```

## ctype.h

```c
#include <ctype.h>
```

Esta biblioteca possui funções para reconhecimento de tipos de caractere (`char`), e carrega diversas funções para esse reconhecimento.

```c
isnum    ('2'); // se é numerico
isalpha  ('s'); // se é alfabético
isblank ('\t'); // se é vazio
iscntrl ('\n'); // se é caractere especial
isdigit  ('4'); // se é numero decimal
isgraph  ('!'); // se tem representação gráfica
isprint  ('2'); // se dá para escrever na tela
ispunct  ('.'); // se é pontuação
isspace ('\v'); // se é um espaço branco
isxdigit ('0'); // se é hexadecimal
islower  ('a'); // se é letra minúscula
isupper  ('A'); // se é letra maiúscula

tolower  ('A'); // transforma em letra minúscula
toupper  ('a'); // transforma em letra maiúscula
```

É necessário que eu esclareça alguns pontos, caracteres como `` ou `ç` são grandes demais para caber em um `char`, caso precise desses caracteres unicode, use strings para representá-los.

## conio.h

```c
#include <conio.h>
```

Esta é uma biblioteca exclusiva para sistemas baseados em [MS-DOS](https://pt.wikipedia.org/wiki/MS-DOS), como o windows, ou o [reactOS](https://pt.wikipedia.org/wiki/ReactOS), e serve para a entrada e saída de dados com o console.

A função mais interessante é sem dúvidas a `getch`, que basicamente espera um caractere.

```c
char c;

printf("digite um caractere");
c = getch();
```

> Ele não espera um "enter", ele apenas recebe o caractere e pronto.

Outra forma legal de usar esta função é pra controlar a entrada do usuário, por exemplo, quero ler um texto eternamente e parar quando a pessoa clicar na tecla <kbd>esc</kbd>.

```c
#include <conio.h>
#include <stdio.h>

int main(){
    puts("digite coisas aqui:");

    char c, *str = malloc(1);
    int i = 0;
    while ((c = getch()) != 27){ /* enquanto o caractere lido
                                    for diferente da
                                    tecla <ESC>
                                 */
        putchar(c);
        str = realloc(str, sizeof str + sizeof c);
        str[i++] = c;
    }

    printf("\n%s\n", str);
    free(str);
    return 0;
}
```

Bom, basicamente é isso, todas as outras funções são apenas alternativas a já existentes como o `cgets` que funciona igual a `gets` do `stdio.h`, ou a `cprintf`... enfim.


# Considerações finais

Espero que este livro tenha ajudado você, este não é o fim definitivo, os seus estudos não devem acabar aqui, então tenha paciência e antes de ir embora vou da um bônus para você se animar e começar seus projetos em C.

