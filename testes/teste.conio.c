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
