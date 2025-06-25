#include <stdio.h>

extern int zahl;

void f1(void) {
  printf("Hier ist f1, zahl = %d\n", zahl);
}
