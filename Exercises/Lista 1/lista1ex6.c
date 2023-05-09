#include <stdio.h>

int main() {

float C, F;

printf ("Digite a temperatura em graus Celsius: ");
scanf ("%f", &C);

F = C * (9.0/5.0)+32.0;

printf ("A temperatura de %f Graus Celsius convertida para Graus Fahrenheit tem como valor: %f", C, F);

return 0;
}