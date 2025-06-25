#include <stdio.h>

void textausgabe(char** textPointer, int anzZeilen) {
  while (anzZeilen-- > 0)
    printf("%s\n", *textPointer++);
}

int main(void) {
  char* zeilen[5] = {
    "Mein",
    "Computer",
    "kennt",
    "Else",
    "nicht"
  };
  textausgabe(&zeilen[1], 3);
  return 0;
}
