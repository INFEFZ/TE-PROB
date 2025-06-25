#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int x = 1;
  int y = 2;
  int i = (x == y) ? 1 : 0;
  printf("i = %d\n", i);
  return 0;
}
