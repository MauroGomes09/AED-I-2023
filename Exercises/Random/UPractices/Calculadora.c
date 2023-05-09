#include <stdio.h>
#include <stdlib.h>

int main() {

    float n1, n2;
    int calculator;
    
    printf ( "Digite dois valores:\nValor 1: " );
    scanf ( "%f", &n1 );
    printf ( "Valor 2: " );
    scanf ( "%f", &n2 );
    printf ( "Digite qual expressao deseja realizar com os dois valores informados:\n1 - Somar\n2 - Subtrair\n3 - Dividir\n4 - Multiplicar\nOpcao escolhida: " );
    scanf ( "%d", &calculator);

    switch (calculator) {
    case 1:
        printf ( "Resultado da soma: %.2f", n1 + n2 );
        break;
    case 2:
        printf ( "Resultado da subtracao: %.2f", n1 - n2 );
        break;
    case 3:
        printf ( "Resultado da divisao: %.2f", n1 / n2);
        break;
    case 4:
        printf ( "Resultado da multiplicacao: %.2f", n1 * n2 );
        break;
    default:
        printf ( "Opcao invalida" );
        break;
    }
    return 0;
}