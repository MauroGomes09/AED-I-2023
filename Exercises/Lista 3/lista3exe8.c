#include <stdio.h>
#include <stdlib.h>

int main() {

    float x, menor, maior;
    int i;

        printf ( "Digite 10 numeros: " );
        scanf ( "%f", &x );

        menor = x;
        maior = x;

    for ( i = 0; i < 9; i++) {
        printf ( "Digite 10 numeros: " );
        scanf ( "%f", &x );

        if ( menor >= x ) {
            menor = x;
        } else if ( maior <= x ) {
            maior = x;
        }
    }
    printf ( "Menor valor lido: %f", menor);
    printf ( "\nMaior valor lido: %f", maior);
    return 0;
}