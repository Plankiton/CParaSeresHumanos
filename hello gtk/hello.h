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
