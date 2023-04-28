#include <stdio.h>

void insertionSort ( int array[], int n ) {
   int i, key, j;
   for ( i = 1; i < n; i++ ) {
       key = array [ i ];
       j = i - 1;

       while ( j >= 0 && array[ j ] > key ) {
           array [ j + 1 ] = array [ j ];
           j = j - 1;
       }
       array[ j + 1 ] = key;
   }
}

int main() {
   int array[] = {9, 5, 1, 4, 3};
   int n = sizeof(array)/sizeof(array[0]);
   int i;

   printf("Array desordenado: ");
   for (i = 0; i < n; i++)
       printf("%d ", array[i]);

   insertionSort(array, n);

   printf("\nArray ordenado: ");
   for (i = 0; i < n; i++)
       printf("%d ", array[i]);

   return 0;
}