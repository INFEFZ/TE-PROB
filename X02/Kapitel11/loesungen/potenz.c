#include <stdio.h>
#include <math.h>

double mathPow(double a, int b) {
  return pow(a, b);
}

double mathLoop(double a, int b) {
  double resultat = 1.;
  while (b) {
    resultat *= a;
    --b;
  }
  return resultat;
}

double mathRekursion(double a, int b) {
  if (a == 0 && b == 0)
    return 1.;   // Spezialfall. 0 ^ 0 ist definiert als 1.
    
  if (b <= 1) {  // b == 1 würde bei (1 ^ 0) fehlschlagen.
    return a;
  } else {
    return a * mathRekursion(a, b - 1);
  }
}

void printResultat(double a, int b) {
  printf("%f ^ %d = %f, %f, %f\n",
    a,
    b,
    mathPow(a, b),
    mathLoop(a, b),
    mathRekursion(a, b));
}

int main(void) {
  printResultat(5., 2);
  printResultat(2.5, 8);
  printResultat(1000, 3);
  printResultat(3, 1000);
  printResultat(7, 1);
  printResultat(1, 7);
  //printResultat(1, 777777); // Absturz, da zuviele Rekursionen
  printResultat(0, 1);
  printResultat(1, 0);
  printResultat(0, 0);

  return 0;
}

// Das Programm liest Zeichen von der Tastatur und gibt sie in umgekehrter
// Reihenfolge wieder aus.
