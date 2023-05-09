#include <stdio.h>

int main() {

    int dn,ano,anon;

    printf ("Digite sua idade: ");
    scanf ("%d", &dn);
    printf ("Digite o ano atual: ");
    scanf ("%d", &ano);

    anon = ano - dn;

    printf("Seu ano de nascimento: %d",anon);
    return 0;
}