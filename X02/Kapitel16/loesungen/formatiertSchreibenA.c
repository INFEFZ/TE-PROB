// MSVC meldet fuer veraltete, unsichere C-Funktionen wie
// fopen einen Fehler.
// Mittels folgender Zeile koennen diese Fehler ausgeschaltet
// werden:
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
  int count = 5;

  FILE* fp = fopen("zahlen.dat", "w");
  while (count) {
    int zahl = count;
    fprintf(fp, "%d\n", zahl);
    --count;
  }

  fclose(fp);
  return 0;
}
