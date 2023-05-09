#include <stdio.h>

int main() {

    int x, soma=0;

    printf ( "Digite um numero inteiro: " );
    scanf ( "%d", &x );

    if ( x > 0 )
    {
        while ( x > 0 ) {

       soma += x % 10;

       x = x / 10;

       }
        
        printf ( "A soma dos algarismos eh: %d ", soma );

    } else {
        printf ( "Numero invalido" );
    }
    return 0;
}