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
