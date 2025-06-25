#include <stdio.h>

int main(void) {

  // Array mit ASCII Werten fuellen.
  char ascii1[128];
  for (int i = 0; i < 128; ++i) {
    ascii1[i] = i;
  }
  for (int i = 48; i <= 57; ++i) { // 0x30 bis 0x39 in Hex
    printf("%c", ascii1[i]);
  }

  printf("\n");

  // Maximum suchen.
  int array2[10] = {14, 7, 40, 58, 2, 65, 95, 11, 72, 37};
  int y = 0;
  for (int i = 1; i < 10; ++i) {
    if (array2[i] > array2[y]) {
      y = i;
    }
  }
  printf("Der hoechste Wert an Index %d hat den Wert %d.\n", y, array2[y]);

  // Skalarprodukt berechnen
  double a[3] = {4.6, 2.1, 7.3};
  double b[3] = {8.6, 5.7, 2.2};
  double resultat = 0.;
  for (int i = 0; i < 3; ++i) {
    resultat = resultat + a[i] * b[i];
  }
  printf("Das Skalarprodukt hat den Wert %f.\n", resultat);

  return 0;
}
