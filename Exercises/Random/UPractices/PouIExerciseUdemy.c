#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int PouI = 10;

    printf ( "WHILE:\n" );
    while ( PouI <= 20 && PouI >= 10 )
    {
        printf ( "%d\n", PouI );
        PouI += 2;
    }
    
    PouI = 10;

        printf ( "DO WHILE:\n" );
    do {
        printf ( "%d\n", PouI );
        PouI += 2;
    } while ( PouI <= 20 && PouI >= 10 );

    printf ( "FOR:" );
    for (PouI = 10; PouI <= 20 && PouI >= 10; PouI += 2) {
        printf ( "\n%d", PouI );
    }
    return 0;
}