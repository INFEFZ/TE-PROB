#include <stdio.h>

void reverse(void) {
  int c = getchar();
  if (c != '\n') {
    reverse();
  }
  putchar(c);
}

int main(void) {
  reverse();
  return 0;
}

// Das Programm liest Zeichen von der Tastatur und gibt sie in umgekehrter
// Reihenfolge wieder aus.
