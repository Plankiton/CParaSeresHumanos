/*
#include <stdio.h>
#include <stdarg.h>

void print ( int len, char* strings[static len] ) {
   int i = 0;
   while (i != len)
         printf("%s", strings[i++]); // aqui deveria retornar uma string, mas ele simplesmente da erro e sai.
}


// void print ( char * s, ... ) {
//   va_list args;
//
//   va_start ( args, s);
//
//   int i = 0;
//   while (s[i++] != '\0')
//         printf("%s", va_arg(args, char *)); // aqui deveria retornar uma string, mas ele simplesmente da erro e sai.
//
//   va_end ( args);
//}

int main(int argc, char **argv){
   print(3, (char*[3]){"a","b dsjflajf sdjfljsf sdlfjlks fd","c\n"} );
return 0;
}
*/

#include <stdio.h>
#include <stdarg.h>

void print(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char const* arg;
    while ( (arg = va_arg(args, char*)) ) {
        printf(fmt, arg);
    }

    va_end ( args);
}

int main(int argc, char **argv){
   print ( "%i ", 5, 5, NULL);

 return 0;
}
