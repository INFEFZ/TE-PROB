#include <stdio.h>

void unbekannteFunktion(void) {
  int c = getchar();
  if (c != '\n') {
    unbekannteFunktion();
  }
  putchar(c);
}

int main(void) {
  unbekannteFunktion();
  return 0;
}
