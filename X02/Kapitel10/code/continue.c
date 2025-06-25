#include <stdio.h>

int main(void) {
  int sum = 0;
  for (int i = 0; i < 20; ++i) {
    if (i % 2) {
      continue;
    }
    sum += i;
  }
  printf("Summe: %d\n", sum);

  return 0;
}
