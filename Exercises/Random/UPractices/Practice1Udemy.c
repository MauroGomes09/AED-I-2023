#include <stdio.h>
#include <stdlib.h>

int main() {

    float n1, n2, n3, media;

    printf ( "Digite as notas das tres provas do trimestre: " );
    scanf ( "%f %f %f", &n1, &n2, &n3 );
    
    media = ((n1 + n2 + n3)/3);

    if ( media > 7 )
    {
        printf ( "Aluno aprovado!");
    } else {
        printf ( "Aluno reprovado!");
    }
    return 0;
}