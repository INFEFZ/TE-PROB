#include <stdio.h>

int main(void) {
  int a = 53;
  int b = 11;
  int originalA = a;

  while (a >= b) {
    a -= b;
  }
  printf("%d modulo %d ist : %d\n", originalA, b, a);
  printf("%d modulo %d ist : %d\n", originalA, b, originalA % b);
  return 0;
} 


// Zieht man von einer grösseren Zahl eine kleinere wiederholt ab, bis sie
// kleiner ist als die kleinere, so ergibt sich der Restbetrag einer Division.

// Das Ergebnis ist verifiziert durch die zweite Ausgabezeile.
