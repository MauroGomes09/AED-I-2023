#include <stdio.h>

int main() {
    int A;

    printf ( "Digite qual opcao voce deseja pro cafe da manha: ");
    scanf ( "%d", &A );

    switch ( A ) {
    case 1:
        printf ( "Opcao 1 = Capuccino" );
        break;
    case 2:
        printf ( "Opcao 2 = Cafe com Leite" );
        break;
    case 3:
        printf ( "Opcao 3 = Cafe Preto" );
        break;
    default:
        printf ( "Opcao escolhida invalida" );
        break;
    }
    return 0;
}