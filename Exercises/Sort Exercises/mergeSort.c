#include <stdio.h>

void merge ( int array[], int left, int middle, int right ) {
   int i, j, k;
   int n1 = middle - left + 1;
   int n2 = right - middle;

   int L[n1], R[n2];

   for ( i = 0; i < n1; i++ )
       L[i] = array[left + i];
   for ( j = 0; j < n2; j++ )
       R[j] = array[middle + 1 + j];

   i = 0;
   j = 0;
   k = left;

   while ( i < n1 && j < n2 ) {
       if ( L[i] <= R[j] ) {
           array[k] = L[i];
           i++;
       } else {
           array[k] = R[j];
           j++;
       }
       k++;
   }

   while ( i < n1 ) {
       array[k] = L[i];
       i++;
       k++;
   }

   while ( j < n2 ) {
       array[k] = R[j];
       j++;
       k++;
   }
}

void mergeSort ( int array[], int left, int right ) {
   if ( left < right ) {
       int middle = left + (right - left) / 2;

       mergeSort ( array, left, middle );
       mergeSort ( array, middle + 1, right );

       merge ( array, left, middle, right );
   }
}

int main() {
   int array[] = {9, 5, 1, 4, 3};
   int n = sizeof(array)/sizeof(array[0]);
   int i;

   printf( "Array desordenado: " );
   for (i = 0; i < n; i++)
       printf ( "%d ", array[i] );

   mergeSort ( array, 0, n-1 );

   printf ( "\nArray ordenado: " );
   for ( i = 0; i < n; i++ )
       printf ( "%d ", array[i] );

   return 0;
}