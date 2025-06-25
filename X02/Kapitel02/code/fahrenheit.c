#include <stdio.h>

// Konstanten
#define UPPER      200
#define LOWER        0
#define STEP_SIZE   20

/* Diese Funktion gibt eine Tabelle aus,
 * in welcher Fahrenheit-Werte in die passenden
 * Celsius-Werte umgerechnet wurden.
 */
int main(void) {

  // Schleife von LOWER bis UPPER
  for (int fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP_SIZE) {
    int celsius = 5 * (fahr - 32) / 9;
    printf("%3d\t%3d\n", fahr, celsius);
  }
  
  return 0;  // Ende des Programmes
}
