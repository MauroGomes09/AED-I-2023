#include <stdio.h>

int main() {

    int x,suc,ant,soma;

    printf ("Digite um numero inteiro: ");
    scanf ("%d", &x);

    suc = (3*x) + 1;
    ant = (2*x) - 1;

    soma = suc + ant;

    printf ("Soma do sucessor de seu triplo com o antecessor de seu dobro: %d",soma);
    return 0;
}