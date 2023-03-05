#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool judgeCircle ( char* moves ) {
    int x = 0, y = 0;
    for ( int i = 0; i < strlen(moves); i++ ) {
        switch ( moves[i] ) {
            case 'R':
                x++;
                break;
            case 'L':
                x--;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
        }
    }
    return x == 0 && y == 0;
}

int main () {
    char moves [ 20001 ];
    printf ( "Digite a sequencia de movimentos do robo: " );
    scanf ( "%s", moves );
    bool result = judgeCircle ( moves );
    if ( result ) {
        printf( "O robo retornou a origem.\n" );
    } else {
        printf( "O robo não retornou a origem.\n" );
    }
    return 0;
}