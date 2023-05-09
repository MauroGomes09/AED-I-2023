#include <stdio.h>

int main() {

    int md3 = 0;
    

    while ( md3 < 15 && md3 >= 0 )
    {
        md3 += 3;
        printf ( "%d\n", md3 );
    }
    return 0;
}