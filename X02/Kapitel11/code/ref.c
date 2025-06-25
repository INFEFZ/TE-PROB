#include <stdio.h>

void init(int* alpha) {
  *alpha = 10;
}

int main(void) {
  int a;
  init(&a);
  printf("Der Wert von a ist %d\n", a);
  return 0;
}
