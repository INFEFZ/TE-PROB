#include <stdio.h>

int main(void) {
  int x = 24;
  int y = 9;

  while (x != y) {
    if (x < y)
      y = y - x;
    else
      x = x - y;
  }
  
  printf("Der groesste gemeinsame Teiler ist: %d\n", x);
  return 0;
}
