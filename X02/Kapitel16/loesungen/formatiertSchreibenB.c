// MSVC meldet fuer veraltete, unsichere C-Funktionen wie
// fopen oder fscanf einen Fehler.
// Mittels folgender Zeile koennen diese Fehler ausgeschaltet
// werden:
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
  FILE* fp = fopen("zahlen.dat", "r");

  int count = 0;
  double summe = 0.;
  while (!feof(fp)) {
    int zahl;
    fscanf(fp, "%d\n", &zahl);
    printf("Die Zahl war: %d\n", zahl);
    summe = summe + (double)zahl;
    ++count;
  }

  fclose(fp);
  printf("Der Durchschnitt der Zahlen war: %f\n", summe / count);

  return 0;
}
