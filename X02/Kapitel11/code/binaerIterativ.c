#include <stdio.h>

void binaerZahlIter(int zahl1) {
  int array[sizeof(int) * 8]; 
  int stelle;                         

  for (int i = 0; i < (sizeof(int) * 8); ++i) {
    array[i] = 0;
  }
  for (stelle = 0; zahl1 != 0; ++stelle) {
    array[stelle] = zahl1 % 2;
    zahl1 /= 2;
  }
  for (; stelle > 0; --stelle) {
    printf("%d ", array[stelle - 1]);
  }
} 

int main(void) {
  int zahl = 35;
  binaerZahlIter(zahl);
  return 0;
}
