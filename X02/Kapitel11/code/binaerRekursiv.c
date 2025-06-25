#include <stdio.h>

void binaerZahlReku(int zahl) {  
  if (zahl > 0) {
    binaerZahlReku(zahl / 2);
    printf("%d ", zahl % 2); 
  }
}

int main(void) {
  int zahl = 35;
  binaerZahlReku(zahl);
  return 0;
}
