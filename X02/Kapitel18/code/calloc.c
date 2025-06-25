#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int* a = calloc(3, sizeof(int));
  if (a != NULL) {
    printf("Inhalt des Arrays: %d, %d, %d\n", a[0], a[1], a[2]);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    printf("Inhalt des Arrays: %d, %d, %d\n", a[0], a[1], a[2]);
    free(a);
  } else {
    printf("Nicht genuegend Speicher verfuegbar.\n");
  }
  return 0;
}
