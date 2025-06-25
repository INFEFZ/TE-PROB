#include <stdlib.h>
#include <stdio.h>

int ordnung(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(void) {
  int array[] = {2, 5, 11, 17, 23, 31, 33, 37, 44, 50, 59, 62}; 
  int anzahl = sizeof(array) / sizeof(int);

  int key = 23;
  int* keyptr = bsearch(&key, array, anzahl, sizeof(int), ordnung);
  
  if (keyptr)
    printf("Gefunden an Index %d\n", (int)((int*)keyptr - array));
  else
    printf("Nicht gefunden\n");
}
