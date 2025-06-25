#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int* intPointer = malloc(sizeof(int));
  
  *intPointer = 42;
  printf("Inhalt der Variablen: %d\n", *intPointer);
  
  // Memory Leak:
  intPointer = malloc(sizeof(int));
  // Nicht initialisierter Wert:
  printf("Inhalt der Variablen: %d\n", *intPointer);

  *intPointer = 101;
  printf("Inhalt der Variablen: %d\n", *intPointer);
  
  free(intPointer);
  return 0;
}
