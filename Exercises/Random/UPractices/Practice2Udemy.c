#include <stdio.h>
#include <stdlib.h>

int main() {

    float l1, l2, l3;
    printf ( "Digite o comprimento(m) dos tres lados do triangulo:\nLado 1: " );
    scanf ( "%f", &l1 );
    printf ( "Lado 2: " );
    scanf ( "%f", &l2 );
    printf ( "Lado 3: " );
    scanf ( "%f", &l3 );

    if ( l1 == l2 && l1 == l3)
    {
        printf ( "O triangulo eh equilatero!" );
    } else {
        printf ( "O triangulo nao eh equilatero!");
    }
    return 0;
}