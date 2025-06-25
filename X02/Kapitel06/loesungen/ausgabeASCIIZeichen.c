#include <stdio.h>
#include <string.h>

#define DER_STRING \
   "Achtung,\ndas geheime Passwort lautet\t\x1b 1234\t\nDanke!"

int main(void) {
  int len = strlen(DER_STRING);
  for (int curIndex = 0; curIndex < len; ++curIndex) {
    char c = DER_STRING[curIndex];

    if (c == '\t') {
      printf("\n********\n");
    } else if (c == '\n') {
      printf(" - STOP - ");
    } else if (c == '\x1b') {
      printf(" - VERBINDUNG UNTERBROCHEN - ");
      break;
    } else {
      printf("%c", c);
    }
  }
  printf("\n");
  return 0;
}
