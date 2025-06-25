#include <stdio.h>

int main(void) {
  int alpha[5] = {1, 2, 3, 4, 5};
  int* pointer = alpha;

  int i = 0;
  while (i < 5) {
    printf("%d\n", *pointer);
    ++pointer;
    ++i;
  }
  
  return 0;
}
