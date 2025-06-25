#include <stdio.h>

int main(void) {
  int max = 10;
  
  printf("Die ersten %d ganzzahligen Quadratzahlen sind:\n", max);
  
  int zahl = 1;
  while (zahl <= max) {
    printf("%d ", zahl * zahl);
    zahl = zahl + 1;
  }

  return 0;
}
