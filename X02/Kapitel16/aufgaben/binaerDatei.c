// MSVC meldet fuer veraltete, unsichere C-Funktionen wie
// fopen einen Fehler.
// Mittels folgender Zeile koennen diese Fehler ausgeschaltet
// werden:
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define iN 7
#define fN 3

int iArr[iN] = { 1, 2, 3, 4, 5, 6, 7 };
float fArr[fN] = { 1.1f, 2.2f, 3.3f };

int main(void) {
  FILE* fp = fopen("test.dat", "wb");
  if (fp == NULL) {
    printf("Kann Datei nicht oeffnen.\n");
  } else {
    fwrite(iArr, sizeof(int), iN, fp);
    fwrite(fArr, sizeof(float), fN, fp);
    fclose(fp);
  }
  return 0;
}
