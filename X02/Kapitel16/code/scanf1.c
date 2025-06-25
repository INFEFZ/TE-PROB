// MSVC meldet fuer veraltete, unsichere C-Funktionen wie
// scanf einen Fehler.
// Mittels folgender Zeile koennen diese Fehler ausgeschaltet
// werden:
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
  printf("Eingabe: ");

  int zahl;
  int anzahl = scanf("%d", &zahl);

  printf("%d Wert erfolgreich eingelesen.\n", anzahl);
  printf("Der Wert war %d.\n", zahl);
  return 0;
}
