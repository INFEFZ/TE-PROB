#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int* a = malloc(sizeof(int));
  *a = 3;
  printf("Inhalt nach malloc(): %d\n", *a);
  
  a = realloc(a, 2 * (sizeof(int)));
  a[1] = 6;
  printf("Inhalt nach realloc(): %d, %d\n", a[0], a[1]);

  free(a);
  return 0;
}
