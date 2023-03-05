// C Program to count number of
// ways to reach Nth stair
#include <stdio.h>
 
// A simple recursive program to
// find n'th fibonacci number
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
 
// Returns number of ways to reach s'th stair
int countWays(int s)
{
    return fib(s + 1);
}
 
// Driver program to test above functions
int main()
{
    int s;
    printf ( "Digite o numero de degraus(s): " );
    scanf ( "%d", &s );
    printf("Number of ways = %d", countWays(s));
    getchar();
    return 0;
}