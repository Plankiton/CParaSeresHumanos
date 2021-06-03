# Noções básicas

## O que é "C"?

C é uma linguagem de programação... _"mas o que é linguagem de programação?"_ ...eu sei que é quase impossível você ter chegado até este livro sem saber o que é linguagem de programação, mas, caso você não saiba, é "a forma de falar com o computador". Você escreve o que quer que ele faça em um arquivo e ele vai fazer, e o C é só uma forma de se fazer isso. Existe uma infinidade de linguagens por aí, mas eu estou aqui para lhes mostrar essa que é considerada por muitos uma das melhores linguagens de todos os tempos, e eu estou sendo inserido nesse "muitos".

## Como o C funciona?

O C é uma linguagem compilada... _"mas o que é isso?"_

> Basicamente, significa que o c traduz o que você escreve em um arquivo para uma liguagem que só o computador entende.

...E é considerado por muitos uma linguagem de _médio nível_ (alguns o consideram uma linguagem de _baixo nível_), e com isso não estou referindo-me à qualidade do C, mas ao nível de proximidade com o hardware (a parte física do computador). Quanto mais próximo do hardware, mais baixo é o nível e essa característica do C o torna a linguagem mais indicada para fazer aplicações de sistema (programas que manipulam o hardware) e aplicações gráficas (jogos, editores de imagem...).

> Só para deixar claro o C é uma linguagem de alto nível, mas por ter tanta intimidade com o hardware, as pessoas começaram a considerá-lo em um nível mais baixo.

Só para se ter uma ideia do poder do C, vou listar alguns _softwares_ feitos nessa linguagem:
> Todos os softwares listados são **open source**, dessa forma vocês podem ter certeza de que foi mesmo feito em C, além de poderem editar o código, se quiserem...

1. [Blender](https://blender.org)                - Modelador 3D e engine de jogos.
2. [Linux](https://kernel.org)                   - Núcleo das distribuições linux.
3. [Gimp](httsp://gimp.org)                      - Editor de imagens.
4. [Darwin](https://github.com/apple/darwin-xnu) - Núcleo do Mac OS X
5. [VLC](https://www.videolan.org/vlc/)          - Reprodutor de Vídeos

Existe uma infinidade de aplicativos feitos em C, mas como o foco aqui é ensinar C (e não citar aplicativos feitos em C), eu vou prosseguir...

## Qual é a história do C?

Resumidamente, o C foi criado na década de 1970 por [Ken Thompson](https://pt.wikipedia.org/wiki/Ken_Thompson) e [Dennis Ritchie](https://pt.wikipedia.org/wiki/Dennis_Ritchie) para reprogramar o [UNIX](https://pt.wikipedia.org/wiki/Unix), que era escrito em [assembly](https://pt.wikipedia.org/wiki/Linguagem_assembly).

O C é uma evolução da linguagem [B](https://pt.wikipedia.org/wiki/B_(linguagem_de_programa%C3%A7%C3%A3o)) que foi influenciada pela linguagem [BCPL](https://pt.wikipedia.org/wiki/BCPL). No início, a linguagem C era despadronizada, isso significa que cada compilador de C usava uma _"versão"_ diferente, então, em 1983 a [ANSI](https://pt.wikipedia.org/wiki/American_National_Standards_Institute) resolveu padronizar o C para que ele funcionasse mais coerentemente em compiladores diferentes, e não foi só a ANSI que padronizou, a [ISO](https://pt.wikipedia.org/wiki/ISO) também já fez isso.

## Como se instala o tal "compilador" C?

Neste capítulo vou demonstrar a instalação em alguns sistemas operacionais, mas todos os exemplos do livro foram testados em um sistema linux, então para garantir que tudo vai funcionar perfeitamente eu aconselho que seja lido e testado em um sistema linux (mesmo que seja uma máquina virtual).

### GNU C Collection

O [gcc](https://pt.wikipedia.org/wiki/GNU_Compiler_Collection), já vem com uma gama de ferramentas já inclusas, como o compilador C (`gcc`) e o compilador C++ (`g++`).

Se você usa uma distribuição Linux ou BSD, provavelmente já está instalado, mas, caso não esteja (o que eu duvido muito), é só usar o gerenciador de pacotes para instalar.

#### Debian

```sh
sudo apt install gcc
```

#### Red Hat

```sh
sudo dnf install gcc
sudo yum install gcc
```

#### Arch Linux

```sh
sudo pacman -S gcc
```

#### Mac OS X

Se você não tem [homebrew](https://brew.sh/index_pt-br), rode:

```sh
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

> Instalando gcc:

```sh
brew install gcc
```

#### Windows

Se você não tem o [chocolatey](https://chocolatey.org/), rode no __[PowerShell](https://pt.wikipedia.org/wiki/PowerShell) em modo administrador__:

```PS1
Set-ExecutionPolicy Bypass -Scope Process -Force
iex((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
```

> Instalando gcc

```bat
choco install mingw -y
```

### Tiny C Compiler

Uma outra opção de compilador muito interessante é o [tcc](https://en.wikipedia.org/wiki/Tiny_C_Compiler) é um compilador independente com o intúito de gerar códigos pequenos, mas não é recomendado para aplicações grandes, mas para estudo é uma ótima opção.

#### Debian

```sh
sudo apt install tcc
```

#### Red Hat

```sh
sudo dnf install tcc
sudo yum install tcc
```

#### Arch Linux

```sh
sudo pacman -S tcc
```

#### Mac OS X

```sh
brew install tcc
```

#### Windows

```sh
choco install tcc
```

