#include <stdio.h>

int main()  {

    int cont = 10;

    while ( cont > 0 ) {
        printf( "\n%d", cont );
        cont--;
    }

    cont = 10;

    do
    {
        printf ( "\nValor do contador = %d", cont );
        cont--;
    } while (cont >= 1 );

    printf ( "\nContagem regressiva de 10 a 1: " );
    for ( cont = 10; cont > 0; cont-- ) {
        printf ( "\n%d", cont );
    }
    return 0;   
}