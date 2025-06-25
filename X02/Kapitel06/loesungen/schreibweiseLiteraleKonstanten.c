#define ALPHA   -1e-0    // korrekt
#define BETA    -e12     // falsch
#define GAMMA    .517    // korrekt
#define DELTA    3+      // falsch

#define ZAHL1   55.5e5   // double
#define ZAHL2   55.      // double
#define ZAHL3   55e5f    // double
#define ZAHL4   55       // int
#define ZAHL5   55.5     // double

#include <stdio.h>

int main(void) {
  // Korrekte Ausgabe: 
  printf("%f\n", ZAHL1);    // 5550000.000000
  printf("%f\n", ZAHL2);    // 55.000000
  printf("%f\n", ZAHL3);    // 5500000.000000
  printf("%d\n", ZAHL4);    // 55
  printf("%f\n", ZAHL5);    // 55.500000

  printf("\n");

  // Falsche Ausgabe:
  // Moderne Compiler geben hier Warnungen aus:
  printf("%d\n", ZAHL1);    // 0
  printf("%d\n", ZAHL2);    // 0
  printf("%d\n", ZAHL3);    // 0
  printf("%f\n", ZAHL4);    // 0.000000
  printf("%d\n", ZAHL5);    // 0
  return 0;
}
