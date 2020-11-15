#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct termios orig_termios;
void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}
void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);
  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main(int argc, char *argv[])
{
    enableRawMode();
    puts("digite coisas aqui:");

    char c, *str = malloc(1);
    int i = 0;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 27){
        putchar(c);
        printf("%i %c", c, c);
        str = realloc(str, sizeof str + sizeof c);
        str[i++] = c;
    }

    printf("\n%s\n", str);
    free(str);
    return 0;
}
