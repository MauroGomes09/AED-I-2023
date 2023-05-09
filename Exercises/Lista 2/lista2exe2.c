#include <stdio.h>

int main() {

    float numero, raiz;

    printf ( "Digite um numero: " );
    scanf ( "%f", &numero );

    if ( numero >= 0 ) {
        raiz = sqrt(numero);
        printf ( "A raiz quadrada do numero %.2f tem o seguinte valor: %.2f", numero, raiz );
    } else {
        printf ( "O numero fornecido e invalido" );
    }
    return 0;
}