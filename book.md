# C para seres humanos

## índice

## Sobre o livro

Antes de começar, este livro está sendo destinado a iniciantes no mundo da programação, por isso todos os termos apresentados aqui estão sendo explicados da forma mais simples possível, mas os conhecimentos aqui apresentados iram atender qualquer um que sejam iniciantes em linguagem C (mesmo que você já saiba programar em outra linguagem).

## O que é "C"?

C é uma linguagem de programação... _"mas o que é linguagem de programação?"_ ...eu sei que é quase impossível você ter chegado até este livro sem saber o que é linguagem de programação, mas caso você não saiba, é "a forma de falar com o computador", você escreve o que quer que ele faça em um arquivo e ele vai fazer, e o C é só uma forma de fazer isso, existe uma infinidade de linguagens por aí, mas eu estou aqui para lhes mostrar essa que é considerada por muitos uma das melhores linguagens de todos os tempos... _e eu estou sendo inserido nesse "muitos"_ ...e o C merece todo esse crédito.

### Como o C funciona?

O C é uma linguagem compilada... _"mas o que é isso?"_ ...para explicar isso de forma simples preste atenção no exemplo:

> João precisa mandar um robô limpar o seu quarto, mas o robô só recebe comandos em *binário* (que é a "linguagem" dos computadores), e pra isso você tem que traduzir "limpe meu quarto" e o **interpretador** do robô transformaria em "01101100 01101001 01101101 01110000 01100101 00100000 01101101 01100101 01110101 00100000 01110001 01110101 01100001 01110010 01110100 01101111", no outro dia João manda o robô ir de novo limpar seu quarto, e ele manda "limpe meu quarto" de novo e o robô tem que traduzir de novo para binário, e no outro dia de novo, então João usa ao invés do interpretador um **compilador** e essa frase fica lá no robô, agora sempre que ele quiser que o robô limpe o quarto ele diz, mas o robô não precisa mais traduzir para binário, pois o binário que corresponde a esse comando já está lá.

Em termos técnicos, um **interpretador** traduz o código do seu programa e depois executa toda vez que é executado, enquanto o **compilador** traduz uma vez e ele gera um **binário**(linguagem do computador), e sempre que você quiser executar, o **binário** será executado, e isso vai reduzir o tempo de execução do código.

E por ser uma linguagem compilada o C é mais rápido que qualquer linguagem interpretada, além disso o C é considerado uma linguagem de _médio nível_ (alguns o consideram uma linguagem de _baixo nível_), e com isso não estou referindo-se a quualidade do C mas ao nível de proximidade com o hardware (a parte física do computador) e quanto mais próximo mais baixo é o nível, e essa característica do C o torna a linguagem mais indicada para fazer aplicações de sistema (programas que manipulam o hardware) e aplicações gráficas (jogos, editores de imagem...).

Só para ter uma idéia do poder do C vou listar alguns _softwares_ feitos em C:
> todos os softwares listados são **open source**, pois assim vocês podem ter certeza de que foi mesmo feito em C, além de poderem editar o código se quiserem...

1. [Blender](http://blender.org)                - Modelador 3D e engine de jogos.
2. [Linux](http://kernel.org)                   - Núcleo das distribuicões linux.
3. [Gimp](http://gimp.org)                      - Editor de imagens.
4. [Darwim](http://github.com/apple/darwin-xnu) - Núcleo do Mac OSX
5. [Vlc](http://www.videolan.org/vlc/)          - Reprodutor de Vídeos

Existe uma infinidade de aplicativos feitos em C, mas como o foco aqui é ensinar C (e não citar aplicativos feitos em C), eu vou proceguir...

### Qual é a história do C?

Resumidamente o C foi criado da década de 1970 por [Ken Thompson](https://pt.wikipedia.org/wiki/Ken_Thompson) e [Dennis Ritchie](https://pt.wikipedia.org/wiki/Dennis_Ritchie) para reprogramar o [UNIX](https://pt.wikipedia.org/wiki/Unix), que era escrito em [assembly](https://pt.wikipedia.org/wiki/Linguagem_assembly).

O C é uma evolução da linguagem [B](https://pt.wikipedia.org/wiki/B_(linguagem_de_programa%C3%A7%C3%A3o)) que foi influenciada pela linguagem [BCPL](https://pt.wikipedia.org/wiki/BCPL), a linguagem C no início era despadronizada, isso significa que cada compilador de C usava uma _"versão"_ diferente do C, então em 1983 a [ANSI](https://pt.wikipedia.org/wiki/American_National_Standards_Institute) resolveu padronizar o C para que ele funcionasse mais coerentemente em compiladores diferentes, e não foi só a ANSI que padronizou o C, a [ISO](https://pt.wikipedia.org/wiki/ISO) também já fez isso.

## Instalando o gcc

### Linux/BSD

Se você usa uma distribuição Linux ou BSD, provavelmente já está instalado, mas caso não esteja (o que eu duvido muito) é só usar o gerenciador de pacotes para instalar.

exemplo (debian/ubuntu):
```sh
sudo apt install gcc
```

### Mac OSX

Se você não tem homebrew rode:

```sh
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

> Instalando gcc:

```sh
brew install gcc
```

### Windows

Se você não tem o chocolatey:

> Instalando pelo cmd:
```bat
@"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoProfile -InputFormat None -ExecutionPolicy Bypass -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))" && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"
```
> Instalando pelo PowerShell:
```bat
Set-ExecutionPolicy Bypass -Scope Process -Force; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
```

> Instalando gcc
```bat
choco install mingw
```

## Introdução a sintaxe do C


### Hello mundo em C

> Hello_mundo.c
>
```C
#include <stdio.h>            // importação de biblioteca externa

int main () {                 // declaração da função main
   printf("Hello mundo!!\n"); // função que escreve coisas na tela
   return 0;                  // retorno da função
}                             // fim da função
```
>

Compilando o arquivo

> linux/BSD/Mac OSX
```sh
gcc Hello_mundo.c -o hello
```
> Windows
```bat
gcc Hello_mundo.c -o hello.exe
```

Executando o arquivo

> linux/BSD/Mac OSX
```sh
./hello
```
> Windows
```bat
hello
```
>
> Saída
```
Hello mundo!!
```
>

No programa apresentado, nós vimos a estrutura básica de todo programa em C, onde temos o _header_ (onde ocorre a importação do módulo `stdio.h`), a função `main`, o bloco de código da função `main`, que é tudo que está entre `{` e `}` e nele estão _"os comandos"_, que serão executados (no exemplo é o `printf`, que escreve a nossa mensagem na tela) e o `return`, que envia um inteiro para o sistema operacional ( a função `main` sempre vai ser do tipo `int` e sempre tem que retornar um inteiro, que são números sem vírgula ou ponto como 1, 23, 90...).

A função `main` é essencial para o funcionamento de programas escritos em C, pois ela é a função que é chamada na execução do programa.

O C é uma linguagem estruturada em funções, isto quer dizer que todo o código tem que estar dentro de funções, mas declaração variáveis e comandos do pré-processador (que será melhor abordado mais tarde no livro) são opcionais.

### Variáveis

> Imagine um armário, com diversos espaços para guardar coisas, alguns só dá para guardar bolas (pois são circulares), outras só dá pra guardar bonecas (pois são do formato de bonecas), outros só podem guardar caixas (pois são do formato de caixas) e cada espaço desses tem o nome das coisas que estão no armário.
>
> toda vez que alguém quer um espaço no armário tem que pedir para o dono do armário reservar o espaço e diz que quer um espaço:
>

`circular bola_de_praia = `
![](bola_de_praia.png | height=50)
`;`


O armário é a memória do seu computador, os espaços são as variáveis e o nome em cada espaço é o nome da variável, e só conseguem armazenar tipos expecíficos de dados (no exemplo são bolas ou bonecas), e a situação descrita para a reserva de um espaço é a declaração, se ainda assim ficou confuso olhe o esquema abaixo e tire suas conlusões:

```C
// tipo do espaço   nome do espaço  =  coisa que queremos no espaço
   int              numero          =  80;
```

No exemplo acima eu reservei um espaço que só guarda numeros inteiros (`int`) com o nome `numero` e com o valor `80` dentro.

E no C existem 4 tipos primitivos, ou seja 4 tipos de dados básicos, e eles são o `int`, o `float`, o `char` e o `boolean`
