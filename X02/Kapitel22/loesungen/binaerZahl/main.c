#include <stdio.h>
#include "stack.h"

void binaerZahlIter(int zahl1) {
  int stelle;                         

  for (stelle = 0; zahl1 != 0; ++stelle) {
    stackPush(zahl1 % 2);
    zahl1 /= 2;
  }
  for (; stelle > 0; --stelle) {
    int wert;
    stackPop(&wert);
    printf("%d ", wert);
  }
} 

int main(void) {
  int zahl = 35;
  binaerZahlIter(zahl);
  return 0;
}
