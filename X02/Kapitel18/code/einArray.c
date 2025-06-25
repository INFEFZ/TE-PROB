#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int anzahl = 3;
  int* ptrArray;

  ptrArray = malloc(anzahl * sizeof(int));
  for (size_t index = 0; index < anzahl; ++index) {
    ptrArray[index] = (int)index;
    printf("malloc Array[%d]: %d\n", (int)index, ptrArray[index]);
  }
  free(ptrArray);

  ptrArray = calloc(anzahl, sizeof(int));
  for (size_t index = 0; index < anzahl; ++index) {
    ptrArray[index] = (int)index;
    printf("calloc Array[%d]: %d\n", (int)index, ptrArray[index]);
  }
  free(ptrArray);
  
  return 0;
}
