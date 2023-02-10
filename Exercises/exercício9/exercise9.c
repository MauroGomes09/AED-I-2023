#include <stdio.h>

int main () {

    int X, rev, num;

    printf ( "Digite um numero inteiro:" );
    scanf ( "%d", &X );

    rev = X;
    num = 0;

    while ( rev != 0 ) {
        num = num * 10 + rev % 10;
        rev = rev / 10;
    }

    if ( num == X ) {
        printf ( "%d considera-se como palindromo", X);
    } else {
        printf ( " %d nao considera-se como palindromo", X); }
        return 0;
    }
