#include <math.h>
#include <stdio.h>

#define sinus(X) _Generic ((X),                       \
                           default: sin,              \
                           long double: sinl,         \
                           float: sinf                \
                           )(X)

int main(void) {
  int i = 4;
  float f = 1.2f;
  double d = 3.2;

  printf("%f\n", sinus(d));  // ruft Defaultwert sin(d) auf
  printf("%f\n", sinus(f));  // ruft sinf(f) auf
  printf("%f\n", sinus(i));  // ruft Defaultwert sin(i) auf

  return 0;
}
