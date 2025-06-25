#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand((int)time(NULL));
  int zahl = rand() % 6 + 1;

  switch (zahl) {
    case 1:
    case 3:
    case 5:
      printf("Ungerade Zahl gewuerfelt: %d\n", zahl);
      break;
    case 2:
    case 4:
    case 6:
      printf("Gerade Zahl gewuerfelt: %d\n", zahl);
      break;
  }
  return 0;
}
