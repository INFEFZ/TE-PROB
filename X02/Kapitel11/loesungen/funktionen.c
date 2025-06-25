#include <stdio.h>
#include <stdarg.h>

double globalResultat = 0.;

double berechnung1(double r1, double r2) {
  return (r1 * r2) / (r1 + r2);
}

void berechnung2(double r1, double r2, double* resultat) {
  *resultat = (r1 * r2) / (r1 + r2);
}

void berechnung3(double r1, double r2) {
  globalResultat = (r1 * r2) / (r1 + r2);
}

double berechnung4(int count, ...) {
  va_list argumentlist;
  va_start(argumentlist, count);
  
  double resultat = 0.;
  while (count) {
    double arg = va_arg(argumentlist, double);
    resultat += 1. / arg;
    --count;
  }
  
  va_end(argumentlist);
  return 1. / resultat;
}

int main (void) {

  double r1 = 55.5;
  double r2 = 10.;
  
  double resultat1 = berechnung1(r1, r2);
  printf("Parallel-Widerstand: %f\n", resultat1);
  
  double resultat2 = 0.;
  berechnung2(r1, r2, &resultat2);
  printf("Parallel-Widerstand: %f\n", resultat2);
  
  berechnung3(r1, r2);
  printf("Parallel-Widerstand: %f\n", globalResultat);

  double resultat4 = berechnung4(4, 55.5, 10., 24.8, 100.);
  printf("Parallel-Widerstand: %f\n", resultat4);
  
  return 0;
}
