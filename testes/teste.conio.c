#include <string.h>
#include <conio.h>
#include <stdio.h>

int main(){
    char c, str[] = "";

    while (1){
        c = getch();
        if (c == 27) break;

        strcat(str, (char []){c, 0} );
    }

    printf(str)

    return 0;
}
