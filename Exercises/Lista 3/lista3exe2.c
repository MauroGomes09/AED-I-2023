#include <stdio.h>

int main() {

    int x = 1;

    while ( x > 0 && x <= 100) {
        printf ( "%d\n", x );
        x += 1;
    }

    x = 1;

    do {
        printf ( "%d\n", x );
        x += 1;
    } while ( x >= 1 && x <= 100 );

    for ( x = 1; x <= 100; x++) {
        printf ( "%d\n", x );
    }
    return 0;
    
}