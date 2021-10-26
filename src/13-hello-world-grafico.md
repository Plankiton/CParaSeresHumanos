# Hello World Grafico

Geralmente na internet em geral, a maioria dos projetos feitos em C usa uma ferramenta para automatizar a compilação, vou demonstar aqui com o `make`, mas alguns projetos usam outras ferramentas (geralmente todos tem um `README` para auxiliar na compilação).

O "mini projeto" que vamos escrever é um "hello mundo" gráfico, usando gtk, eu preferi fazer um gráfico para exemplificar o uso de bibliotecas externas e para dar um gostinho da programação GUI para vocês...

> hello.h: header com os protótipos de funções

```c
#include <gtk/gtk.h>
#include <string.h>

// Lista de texto que vai aparecer na tela
typedef struct lista lista;
struct lista {
    char *texto;
    lista *prox;
};

// Função que troca o texto na interface
void mudar_rotulo(GtkWidget *, char *);

// Função que organiza a lista de textos
void organize_lista(lista *, int tamanho);
```

Basicamente o header (ou cabeçalhio) acima serve para declarar as funções e estruturas da nossa biblioteca.

> hello.c: biblioteca com as funções usadas pelo programa

```c
#include "hello.h"

void
mudar_rotulo(GtkWidget * rotulo, char * texto){
    g_print ("hello: ");
    g_print (texto);
    g_print ("\n");

    // Mudando o texto do "rotulo"
    gtk_label_set_text(GTK_LABEL(rotulo), texto);
}

void
organize_lista(lista * lista_de_textos, int len){
    // Organizando o acesso aos posteriores
    for (int i = 0; i<len; i++){
        lista_de_textos[i].prox = &lista_de_textos[i+1];
        lista_de_textos[i].prox = &lista_de_textos[i+1];
    }
    lista_de_textos[len-1].prox = &lista_de_textos[0];
}
```

> main.c: O nosso programa

```c
#include "hello.h"

GtkWidget *janela;
GtkWidget *conteiner;

GtkWidget *botao;
GtkWidget *rotulo;

lista * lista_de_textos;

void
hello (void){
    // Muando o texto do rotulo
    mudar_rotulo(rotulo, lista_de_textos->texto);

    // Mudando o texto atual para o proximo da lista
    lista_de_textos = lista_de_textos->prox;
}


int
main (int argc, char *argv[]){

    // criando a lista de textos
    lista_de_textos = (lista []){
     {.texto = "Hello mundo!!", NULL},              // 1
     {.texto = "Eu amo C!!", NULL},                 // 2
     {.texto = "C para seres humanos!", NULL},      // 3
     {.texto = "Outra coisa aleatória!", NULL},     // 4
     {.texto = "Acesse robocopgay.github.io", NULL} // 5
    };
    organize_lista(lista_de_textos, 5);

    // inicializando configurações padrões da biblioteca
    gtk_init (&argc, &argv);

    // criando a janela principal
    janela = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    // quando o usuário fechar a janela, ela será fechada
    gtk_signal_connect (GTK_OBJECT (janela), "destroy",
            GTK_SIGNAL_FUNC (gtk_main_quit), NULL);

    // criando um rótulo com o texto "..."
    rotulo = gtk_label_new("...");
    // criando um botão com o texto "Clique em mim"
    botao = gtk_button_new_with_label ("Clique em mim");

    // criando um conteiner para guardar os componentes acima (rotulo, botao)
    conteiner = gtk_vbox_new((gint *)5,(gint *)5);

    // quando o usuário clicar no botão ele vai chamar a função hello
    gtk_signal_connect (GTK_OBJECT (botao), "clicked",
            GTK_SIGNAL_FUNC (hello), NULL);

    // adicionando componentes ao conteiner
    gtk_container_add(GTK_BOX(conteiner), rotulo);
    gtk_container_add(GTK_BOX(conteiner), botao);

    // adicionando o conteiner à janela
    gtk_container_add (GTK_CONTAINER (janela), conteiner);

    // tornando os componentes visíveis
    gtk_widget_show_all (janela);

    // iniciando a execução do aplicativo gráfico
    gtk_main();
    return 0;
}
```

Não se preocupe em entender a parte de interface gráfica, eu coloquei mais por que se você for compilar a aplicação acima com os comandos de sempre (`gcc main.c -o hello`), o programa acima não irá compilar, isso acontece porque o GTK+ (A biblioteca de interface gráfica utilizada pelo programa) é uma biblioteca externa, e não está disponível por padrão no seu computador.

E para consertar esse problema, primeiro temos que baixar o GTK:

> E me desculpem galera de Windows, mas eu não sei como usar GTK no sistema de vocês, fiz diversas pesquisas a respeito e tentei instalar e usar, mas não consegui, então estão por conta própria para tentar compilar.

## MacOSX

```sh
$ brew install gtk+
```

## Debian

```sh
$ sudo apt install libgtk-2-dev
```

## Red Hat

```sh
$ sudo dnf install gtk2-devel
```

## Arch Linux

```sh
$ sudo pacman -S gtk2
```

## Compilando

E para compilar nós usaríamos:

```bash
$ gcc -o hello-gtk hello.c main.c $(pkg-config --libs --cflags gtk+-2.0)
```

Isso geraria um binario `hello-gtk`, e para automatizar isso:

> Makefile: arquivo de compilação

```Makefile
CC=gcc
LIBS=$(pkg-config --libs gtk+-2.0)
CFLAGS=$(pkg-config --cflags gtk+-2.0)

all: hello-gtk

hello-gtk:
    @echo CC -o $@ hello.c main.c LIBS CFLAGS
    ${CC} -o $@ hello.c main.c ${LIBS} ${CFLAGs}
```

E agora para compilar é só digitar `make` dentro do diretório do projeto.

Outra coisa interessante do make é dar opções para ele como:

```
install:
    @cp hello-gtk /usr/bin/ -v
clean:
    @rm hello-gtk
opcao-aleatoria:
    @echo opcao aleatoria
```

E é só adicionar a opção na execução do make:

```
$ make opcao-aleatoria
opcao aleatoria
```

Outra solução é colocar algumas configurações em um arquivo separado, que geralmente é chamado de config.mk (mas isso é opcional):

> config.mk:

```Makefile
VERSION="0.1"
CC=gcc
LIBS=$(pkg-config --libs gtk+-2.0)
CFLAGS=$(pkg-config --cflags gtk+-2.0)
```

> Makefile:

```Makefile
all:
    ${CC} -o hello-${VERSION} hello.c main.c ${LIBS} ${CFLAGS}
```
