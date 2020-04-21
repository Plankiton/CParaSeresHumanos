#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double intmod, semente, numrnd;
int main(void)
{
    time_t inicio; //define variavel tipo “long” adequada para time
    time(&inicio); //pega os segundos do relogio do sistema
    semente = inicio; //ao mover, converte tipo “long” para “double”
    for (int n=0; n<20; n++) //vai gerar 20 numeros
    {
        numrnd = modf( semente * 7 / 11, &intmod ) + 0.1 ; //intmod tem que ser "double"
        semente = numrnd * 11; // modf retorna resto em numero decimal
        printf("Numero gerado %i \n", (int) (modf (numrnd * 11.0, &intmod) * 10000000) % 101);
    };
}
