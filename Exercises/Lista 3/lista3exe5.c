#include <stdio.h>

int main() {

    int i;
    float x, soma;

    for ( i = 1; i <= 10; i++)
    {
        printf ( "Digite 10 valores: ");
        scanf ( "%f", &x );
        soma += x;
    }
    printf ( "Valor da soma dos 10 valores: %f", soma );
    return 0;
}