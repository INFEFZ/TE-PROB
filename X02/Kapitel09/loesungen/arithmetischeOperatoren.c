#include <stdio.h>

int main(void) {
  
  for (int i = 1; i <= 10; ++i) {
    printf("%d ", i);
    printf("%d ", i + (i - 1)); // Die Summe mit der vorherigen Zahl
    printf("%d ", i - 5);       // Die Differenz der Zahl zur Zahl 5
    printf("%d ", i * i);       // Das Quadrat der Zahl
    printf("%d ", i / 4);       // Die Zahl geteilt durch 4.
    printf("%d ", i % 3 == 0);  // Ob die Zahl ohne Rest durch 3 teilbar ist.
    printf("\n");
  }
  
  return 0;
}

