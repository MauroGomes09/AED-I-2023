#include <stdio.h>

int main() {

    int um, dois;

    printf( "Digite um numero inteiro: " );
    scanf ( "%d", &um );

    printf ( "Digite outro numero inteiro diferente: ");
    scanf ( "%d", &dois );

    if ( um > dois ) {
        printf ( "%d e maior que o numero %d", um, dois );
    } else {
        printf ( "%d e maior que o numero %d", dois, um );
    }
   return 0; 
}