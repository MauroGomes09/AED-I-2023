#include <stdio.h>

int main() {

    int num;
    float resultado;

    printf ( "Digite um numero inteiro: " );
    scanf ( "%d", &num );

    if ( num > 0 )
    {
        resultado = log(num);
        printf ( "Logaritmo natural do numero %d: %f", num, resultado );
    } else {
        printf ( "Numero Invalido" );
    }
    return 0;
}