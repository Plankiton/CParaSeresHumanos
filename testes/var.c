#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
    int n, m, s;
    n = m = s = 666;

   printf ("%i %i %i\n", n, m, s);

   float f = 1 / 3;

   printf ("%f\n", f);
   printf ("%f\n", (f = 1.0 / 3.0));
return 0;
}
