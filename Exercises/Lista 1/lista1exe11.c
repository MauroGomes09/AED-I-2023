#include <stdio.h>

int main(){

    float M,K;

    printf ("Digite a velocidade em m/s: ");
    scanf ("%f", &M);

    K = M * 3.6;

    printf ("Velocidade de %f m/s convertida para km/h tem como valor: %f", M , K );
    return 0;
}