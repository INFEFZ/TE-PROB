#include <stdio.h>

void printArray(int array[4]) {
  for (int i = 0; i < 4; ++i) {
    printf("%d ", array[i]);
  }
}

int main(void) {
  printArray((int[4]) {1, 2, 3, 4});
  return 0;
}
