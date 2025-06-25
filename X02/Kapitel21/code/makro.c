#include <stdio.h>
#define square(x) x * x
#define twotimes(x) x + x

int main(void) {
  int zahl = 4;
  printf("zahl = %d\n", zahl);
  printf("1) square(5) = %d\n", square(5));
  printf("2) square(5+1) = %d\n", square(5+1));
  printf("3) square(zahl) = %d\n", square(zahl));
  printf("4) square(zahl++) = %d\n", square(zahl++));
  printf("5) zahl = %d\n", zahl);
  printf("6) twotimes(5) = %d\n", twotimes(5));
  printf("7) twotimes(5) * twotimes(6) = %d\n", 
          twotimes(5) * twotimes(6));
  return 0;
}
