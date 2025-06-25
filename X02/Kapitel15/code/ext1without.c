#include <stdio.h>

void f1(void);

int zahl = 6;

int main(void) {
  printf("Hier ist main, zahl = %d\n", zahl);
  f1();
  return 0;
}
