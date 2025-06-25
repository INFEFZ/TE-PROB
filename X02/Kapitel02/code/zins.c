#include <stdio.h>

#define ZINS_1       5.0
#define ZINS_2       2.5
#define LAUFZEIT_1   3
#define LAUFZEIT_2   5
#define GRUNDKAPITAL 1000.00

void printKapital(int jahr, double kapital) {
  printf("Jahr: %2d\t", jahr);
  printf("Kapital: %7.2f EUR\n", kapital);
}

int main(void) {
  double kapital = GRUNDKAPITAL;
  printKapital(0, kapital);

  int totalLaufzeit = LAUFZEIT_1 + LAUFZEIT_2;
  for (int jahr = 1; jahr <= totalLaufzeit; jahr = jahr + 1) {
    if (jahr <= LAUFZEIT_1) {
      kapital = kapital * (1. + ZINS_1 / 100.);
    } else {
      kapital = kapital * (1. + ZINS_2 / 100.);
    }
    printKapital(jahr, kapital);
  }

  printf("\n");
  printf("Aus %7.2f EUR Grundkapital\n", GRUNDKAPITAL);
  printf("wurden in %d Jahren %7.2f EUR\n", totalLaufzeit, kapital);
  return 0;
}
