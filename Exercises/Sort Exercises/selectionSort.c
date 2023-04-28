#include <stdio.h>

void selectionSort ( int array[], int n ) {
   int i, j, indiceLow, temp;
   for ( i = 0; i < n-1; i++ ) {
       indiceLow = i;
       for ( j = i+1; j < n; j++ ) {
           if  ( array[j] < array[indiceLow] ) {
               indiceLow = j;
           }
       }
       temp = array[i];
       array[i] = array[indiceLow];
       array[indiceLow] = temp;
   }
}

int main() {
   int array[] = {9, 5, 1, 4, 3};
   int n = sizeof(array)/sizeof(array[0]);
   int i;

   printf("Array desordenado: ");
   for (i = 0; i < n; i++)
       printf("%d ", array[i]);

   selectionSort(array, n);

   printf("\nArray ordenado: ");
   for (i = 0; i < n; i++)
       printf("%d ", array[i]);

   return 0;
}