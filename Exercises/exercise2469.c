#include <stdio.h>

int main() {

    float Celsius, Fahrenheit, Kelvin;

    printf ( "Digite o valor em graus Celsius:" );
    scanf ( "%f", &Celsius );

    Fahrenheit = (Celsius * 1.80) + 32;
    Kelvin = Celsius + 273.15;

    printf ( "Valor convertido em Kelvin(%f) e convertido em Fahrenheit(%f)", Kelvin, Fahrenheit );
    return 0;
}