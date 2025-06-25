#include <stdio.h>

int main(void) {
  int x;

  for (x = 0; x < 10; ++x) {
    if (x < 5) {
      int y = 2;
      printf("x * y hat den Wert %d\n", x * y);
    } else { 
      int x = 1234;
      printf("Das innere x hat den Wert %d\n", x);
    }
  }

  printf("x hat den Wert %d\n", x);
  return 0;
}
