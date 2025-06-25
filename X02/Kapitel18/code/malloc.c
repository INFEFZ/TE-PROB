#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int* pointer = (int*)malloc(sizeof(int));
  if (pointer!= NULL) {
    *pointer = 3;
    printf("Wert an Pointer-Adresse: %d\n", *pointer);
    free(pointer);
  } else {
    printf("Nicht genuegend Speicher verfuegbar.\n");
  }
  return 0;
}
