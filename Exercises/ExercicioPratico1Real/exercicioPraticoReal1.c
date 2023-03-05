/* Robô de volta a origem
Regras: 1 <= comprimento da string de movimentos <= 2*10^4
moves contém apenas os caracteres 'U','D','L','R' 
R, L, U , D - sempre move o robô uma vez
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char passosRight [ 20 ];
char passosLeft [ 20 ];
char passosUp [ 20 ];
char passosDown [ 20 ];

int *up, *down, *right, *left;

bool judgeCircle ( char*moves) {

   if ( passosRight == passosLeft && passosUp == passosDown )
   {
    return true;
   } else {
    return false;
   }
}

int addUp ( int *up ) {
    int *up;
    printf ( "Você adicionou um passo para cima" );
}

int addDown ( int *down ) {
    int *down;
    printf ( "Você adicionou um passo para baixo" );
}

int addRight ( int *right ) {
    int *right;
    printf ( "Voce adicionou um passo para a direita" );
}

int addLeft ( int *left ) {
    int *left;
    printf ( "Voce adicionou um passo para a esquerda" );
}

int main ()  {

    int option;

do
{
    printf ( "========================================= Robot Game ==========================================\n" );
    printf ( "O robo esta na posicao de origem, escolha a sequencia de movimentos que deseja que ele realize:\n" );
    printf ( "- Digite 1 para move-lo para cima(UP)\n" );
    printf ( "- Digite 2 para move-lo para baixo(DOWN)\n" );
    printf ( "- Digite 3 para move-lo para a direita(RIGHT)\n" );
    printf ( "- Digite 4 para move-lo para a esquerda(LEFT)\n" );
    printf ( "- Digite 5 para sair do menu\n" );
    printf ( "- Selected option: " );
    scanf  ( "%d", &option );

    switch ( option )
    {
    case 1:
        addUp();
        break;

        case 2:
        addDown();
        break;

        case 3:
        addRight();
        break;

        case 4:
        addLeft();
        break;

        case 5:
        printf ( "Voce esta saindo do menu... " );
        break;
    
    default:
        printf ( "Opcao invalida, tente novamente\n" );
        break;
    }
} while ( option != 5 );

    printf ( "Apos a sequencia, se o robo retornou a posicao de origem, entao o resultado sera verdadeiro, caso ele esteja em uma posicao diferente, o resultado sera falso" );
    printf ( "Resultado: %c", judgleCircle() );

    return 0;
}