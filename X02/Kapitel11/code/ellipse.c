#include <stdio.h>
#include <stdarg.h>

const double SCHWELLE = 3.0;
const double ENDE = -1;

double qualitaet(double, ...);

int main(void) {
  printf("Der Ausschuss betraegt %5.2f %%\n",
          100 * qualitaet(SCHWELLE, 2.5, 3.1, 2.9, 3.2, ENDE));
  printf("Der Ausschuss betraegt %5.2f %%\n",
          100 * qualitaet(SCHWELLE, 4.2, 3.8, 3.4, 2.9, 2.7, ENDE));
  return 0;  
}

double qualitaet(double schwellwert, ...) {
  int anzahlSchlechterTeile = 0;
  double wert;
  int i = 0;
  va_list listenposition;                             // (1)
  va_start(listenposition, schwellwert);              // (2)
  wert = va_arg(listenposition, double);              // (3)
  
  while (wert != ENDE) {
    if (wert > schwellwert) ++anzahlSchlechterTeile;
    ++i;
    wert = va_arg(listenposition, double);            // (4)
  }

  va_end(listenposition);                             // (5)
  return (double)anzahlSchlechterTeile / i;
}
