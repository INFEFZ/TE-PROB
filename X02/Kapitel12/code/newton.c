#include <stdio.h>
#include <math.h>

double f(double x) {
  return x - cos(x);
}

double fStrich(double x) {
  return 1 + sin(x);
}

double berechneNullstelle(
  double x,
  double genauigkeit,
  double (*f) (double),
  double (*fstrich) (double))
{
  double z = x;

  do {
    x = z;
    z = x - f(x) / fstrich(x);
  } while (fabs(z - x) > genauigkeit);

  return z;
}

int main(void) {
  double rohwert = 3.;
  double epsilon = 0.1;

  printf("Die Nullstelle ist bei: %.2f\n",
        berechneNullstelle (rohwert, epsilon, f, fStrich));
  return 0;
}
