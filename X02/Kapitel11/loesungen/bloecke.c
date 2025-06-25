#include <stdio.h>

int x = 5;

void function1(int* u) {
  int x = 4;
  *u = 6;
  printf("f1   - der Wert von x ist %d\n", x);
}

void function2(int x) {
  printf("f2   - der Wert von x ist %d\n", x);
}

int main(void) {
  printf("main - der Wert von x ist %d\n", x); // der Wert von x ist 5
  function1(&x);                               // der Wert von x ist 4
  function2(7);                                // der Wert von x ist 7
  printf("main - der Wert von x ist %d\n", x); // der Wert von x ist 6
  return 0;
}
