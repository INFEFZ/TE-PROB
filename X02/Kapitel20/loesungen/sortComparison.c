#include <stdio.h>
#include <stdlib.h>

int nComp;
int nExch;

int* allocateRandomArray(int count) {
  int* array = malloc(sizeof(int) * count);
  for (int i = 0; i < count; ++i) {
    array[i] = rand() % count;
  }
  return array;
}

void bubbleSort(int* array, int count) {
  int vertauschungWarNotwendig = 1;
  while (vertauschungWarNotwendig) {
    vertauschungWarNotwendig = 0;
    
    for (int i = 0; i < count - 1; ++i) {
      ++nComp;
      if (array[i] > array[i + 1]) {
        ++nExch;
        int temp = array[i + 1];
        array[i + 1] = array[i];
        array[i] = temp;
        vertauschungWarNotwendig = 1;
      }
    }
  }
}

void selectionSort(int* array, int count) {
  // Schrittweise durch das gesamte Array
  for (int schritt = 0; schritt < count - 1; ++schritt) {
    int minPos = schritt;

    // Suche nach kleinstem Element
    for (int pos = schritt + 1; pos < count; ++pos) {
      ++nComp;
      if (array[pos] < array[minPos]) {
        minPos = pos;
      }
    }

    ++nExch;
    int swap = array[minPos];
    array[minPos] = array[schritt];
    array[schritt] = swap;
  }
}

void zerlege(int* array, int startLinks, int startRechts) {
  int laufLinks = startLinks;
  int laufRechts = startRechts;
  int vergleichsWert = array[(startLinks + startRechts) / 2];
  
  do {
    while (array[laufLinks] < vergleichsWert) {
      ++nComp;
      ++laufLinks;
    }

    while (array[laufRechts] > vergleichsWert) {
      ++nComp;
      --laufRechts;
    }

    if (laufLinks <= laufRechts) {
      ++nExch;
      int swap = array[laufLinks];
      array[laufLinks] = array[laufRechts];
      array[laufRechts] = swap;
      ++laufLinks;
      --laufRechts;
    }
  } while (laufLinks <= laufRechts);

  // Teilarrays rekursiv sortieren
  if (startLinks < laufRechts)
    zerlege(array, startLinks, laufRechts);
    
  if (laufLinks < startRechts)
    zerlege(array, laufLinks, startRechts);
}

void quickSort(int* array, int n) {
  zerlege(array, 0, n - 1);
}

void testArray(int count) {
  printf("Array-Groesse: %d\n", count);
  int* array = allocateRandomArray(count);
  nComp = 0;
  nExch = 0;
  bubbleSort(array, count);
  printf("Bubble: %d Vergleiche, %d Vertauschungen\n", nComp, nExch);
//  for (int i = 0; i < count; ++i)
//    printf("%d ", array[i]);
//  printf("----\n");
  free(array);

  array = allocateRandomArray(count);
  nComp = 0;
  nExch = 0;
  selectionSort(array, count);
  printf("Selection: %d Vergleiche, %d Vertauschungen\n", nComp, nExch);
//  for (int i = 0; i < count; ++i)
//    printf("%d ", array[i]);
//  printf("----\n");
  free(array);

  array = allocateRandomArray(count);
  nComp = 0;
  nExch = 0;
  quickSort(array, count);
  printf("Quick: %d Vergleiche, %d Vertauschungen\n", nComp, nExch);
//  for (int i = 0; i < count; ++i)
//    printf("%d ", array[i]);
//  printf("----\n");
  free(array);
  
  printf("\n");
}

int main(void) {
  testArray(10);
  testArray(100);
  testArray(1000);
  return 0;
}

