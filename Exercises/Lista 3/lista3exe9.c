#include <stdio.h>

int main()  {

    int i, x;

    printf ( "Digite um numero inteiro: " );
    scanf ( "%d", &x );

    for ( i = 0; i < x * 2; i++)
    {
        if ( i % 2 != 0 ) {
            printf ( "Os %d primeiros numeros naturais impares sao: %d\n", x, i );
        } 
    }
    return 0;
}