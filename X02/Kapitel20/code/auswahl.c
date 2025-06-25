#include <stdio.h>

void printArray(int* array, int anzahl, int schritt) {
  printf("Arbeitsschritt: %i  Array: ", schritt);
  for (int i = 0; i < anzahl; ++i)
     printf("%i ", array[i]);
  printf("\n");
}

int main(void) {

  int array[] = {8, 3, 9, 7, 6, 4};
  const int anzahl = sizeof(array) / sizeof(array[0]);

  printArray(array, anzahl, 0);

  // Schrittweise durch das gesamte Array
  for (int schritt = 0; schritt < anzahl - 1; ++schritt) {
    int minPos = schritt;

    // Suche nach kleinstem Element
    for (int pos = schritt + 1; pos < anzahl; ++pos) {
      if (array[pos] < array[minPos]) {
        minPos = pos;
      }
    }

    int swap = array[minPos];
    array[minPos] = array[schritt];
    array[schritt] = swap;

    printArray(array, anzahl, schritt + 1);
  }
  return 0;
}
