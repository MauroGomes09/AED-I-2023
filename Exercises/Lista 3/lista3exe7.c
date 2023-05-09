#include <stdio.h>

int main() {

    int i, x;
    float media;

    for ( i = 1; i <= 10; ) {
        printf ( "Digite 10 inteiros positivos: " );
        scanf ( "%d", &x );
    if ( x > 0 ) {
        media += x;
        i++;
    } else {
        printf ( "Numero digitado negativo = invalido\n" );
    }
    }
    media = media / 10;
    printf ( "Media dos valores digitados: %f", media );
    return 0;
}