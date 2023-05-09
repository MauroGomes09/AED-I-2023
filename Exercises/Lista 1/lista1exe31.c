#include <stdio.h>

int main(){

    int x,suc,ant;

    printf ("Digite um numero inteiro: ");
    scanf ("%d", &x);

    suc = x + 1;
    ant = x - 1;

    printf ("Sucessor: %d",suc);
    printf ("\nAntecessor: %d",ant);
    return 0;
}