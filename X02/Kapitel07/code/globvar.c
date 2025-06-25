#include <stdio.h>

int alpha = 3;

void f(void) {
  int a;
  a = alpha;
  printf("a hat den Wert %d\n", a);
}

int main(void) {
  int b = 4;
  printf("alpha hat den Wert %d\n", alpha);
  alpha = b;
  printf("alpha hat den Wert %d\n", alpha);
  f();
  
  return 0;
}
