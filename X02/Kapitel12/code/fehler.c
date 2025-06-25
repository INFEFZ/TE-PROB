#include <stdio.h>

const char* fehlertext(int n) {
  static const char* errDesc[] = {
    "kein Fehler",
    "Fehlertext Eins",
    "Fehlertext Zwei",
    "Fehlertext Drei"};

  return (n < 0 || n > 3) ? "Fehlercode existiert nicht" : 
         errDesc[n];
}

int main(void) {
  int fehlernummer = 2;
  printf("Text zu Fehler %d: %s\n", 
    fehlernummer, fehlertext(fehlernummer));
  return 0;
}
