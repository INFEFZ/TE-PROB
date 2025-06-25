#include <stdio.h>
#define COUNT 100

int main(void) {
  for (int i = 5, k = 1; i < COUNT && k < 10; i += k, ++k) {
    printf("%d ", i);
  }
  return 0;
}
