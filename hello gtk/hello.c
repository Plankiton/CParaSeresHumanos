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
