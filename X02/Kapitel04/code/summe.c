// Summenberechnung. Berechnet die Summe aller Zahlen
// von 1 bis MAX.

#include <stdio.h>

#define MAX 100

int addition(int a, int b);

int summe(int n) {
   int sum = 0;
   for (int i = 1; i <= n; i = i + 1)
      sum = addition(sum, i);
   return sum;
}

int addition(int a, int b) {
  return a + b;
}

int main(void) {
   int resultat = summe(MAX);
   printf("Die Summe von 1 bis %d ist %d\n", MAX, resultat);
   return 0;
}
