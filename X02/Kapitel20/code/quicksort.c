#include <stdio.h>

void printArray(int* array, int start, int ende) {
  for (int i = 0; i < start; ++i)
    printf("  ");
  
  for (int i = start; i <= ende; ++i)
    printf("%i ", array[i]);
  
  printf("\n");
}

void zerlege(int* array, int startLinks, int startRechts) {
  int laufLinks = startLinks;
  int laufRechts = startRechts;
  int vergleichsWert = array[(startLinks + startRechts) / 2];
  
  do {
    while (array[laufLinks] < vergleichsWert)
       ++laufLinks;

    while (array[laufRechts] > vergleichsWert)
       --laufRechts;

    if (laufLinks <= laufRechts) {
      int swap = array[laufLinks];
      array[laufLinks] = array[laufRechts];
      array[laufRechts] = swap;
      ++laufLinks;
      --laufRechts;
    }
  } while (laufLinks <= laufRechts);
  
  printArray(array, startLinks, startRechts);

  // Teilarrays rekursiv sortieren
  if (startLinks < laufRechts)
    zerlege(array, startLinks, laufRechts);
    
  if (laufLinks < startRechts)
    zerlege(array, laufLinks, startRechts);
}

void quickSort(int* array, int n) {
  zerlege(array, 0, n - 1);
}

int main(void) {
  int array[] = {7, 3, 8, 6, 9, 2, 1, 4};
  int numInArray = sizeof(array) / sizeof(int);

  printArray(array, 0, numInArray - 1);
  quickSort (array, numInArray);
  printArray(array, 0, numInArray - 1);

  return 0;
}
