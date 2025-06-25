#include <stdlib.h>
#include <stdio.h>

int aufsteigend(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int absteigend(const void* a, const void* b) {
  return (*(int*)b - *(int*)a);
}

void printArray(int* array, int anzahl) {
  for (int i = 0; i < anzahl; ++i)
     printf("%i ", array[i]);
  printf("\n");
}

int main(void) {
   int array[] = {7, 3, 8, 6, 9, 2, 1, 4};
   int anzahl = sizeof(array) / sizeof(int);
   
   printArray(array, anzahl);
   qsort(array, anzahl, sizeof(int), aufsteigend);
   printArray(array, anzahl);
   qsort(array, anzahl, sizeof(int), absteigend);
   printArray(array, anzahl);
}
