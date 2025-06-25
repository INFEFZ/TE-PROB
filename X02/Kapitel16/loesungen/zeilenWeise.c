// MSVC meldet fuer veraltete, unsichere C-Funktionen wie
// fopen einen Fehler.
// Mittels folgender Zeile koennen diese Fehler ausgeschaltet
// werden:
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
  FILE* fp = fopen("zahlen.dat", "r");
  char line[1000];

  int count = 0;
  while (!feof(fp)) {
    fgets(line, 1000, fp);
    ++count;
  }

  fclose(fp);
  printf("Die Datei hat %d Zeilen.\n", count);

  return 0;
}
