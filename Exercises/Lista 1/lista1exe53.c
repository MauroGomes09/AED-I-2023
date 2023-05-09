#include <stdio.h>

int main() {

    float comprimento, largura, preco, custoTotal;

    printf ( "Digite o comprimento do terreno(m): " );
    scanf ( "%f", &comprimento );

    printf ( "DIgite a largura do terreno(m): " );
    scanf ( "%f", &largura );

    printf( "Digite o preco do metro de tela:R$ " );
    scanf ( "%f", &preco );

    custoTotal = (( comprimento + largura )* 2 ) * preco;

    printf ( "Custo total para cercar o terreno com tela: %f", custoTotal );
    return 0;
}