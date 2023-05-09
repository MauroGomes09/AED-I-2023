#include <stdio.h>
#include <math.h>

int main(){

float lc,ac;

printf ( "Digite o tamanho de um dos lados do quadrado: " );
scanf ("%f",&lc);

ac = pow(lc,2);

printf ("A area do quadrado tem valor de: %f m2", ac);
return 0;
}