#include <stdio.h>

void swap ( int *a, int *b ) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

int partition ( int array[], int low, int high ) {
   int pivot = array[high];
   int i = ( low - 1 );
   int j;
   for ( j = low; j <= high- 1; j++ ) {
       if ( array[j] < pivot ) {
           i++;
           swap ( &array[i], &array[j] );
       }
   }
   swap ( &array[i + 1], &array[high] );
   return ( i + 1 );
}

void quickSort ( int array[], int low, int high ) {
   if ( low < high ) {
       int pi = partition ( array, low, high );
       quickSort ( array, low, pi - 1 );
       quickSort ( array, pi + 1, high );
   }
}

int main() {
   int array[] = {9, 5, 1, 4, 3};
   int n = sizeof(array)/sizeof(array[0]);
   int i;

   printf("Array desordenado: ");
   for (i = 0; i < n; i++)
       printf("%d ", array[i]);

   quickSort(array, 0, n-1);

   printf("\nArray ordenado: ");
   for (i = 0; i < n; i++)
       printf("%d ", array[i]);

   return 0;
}