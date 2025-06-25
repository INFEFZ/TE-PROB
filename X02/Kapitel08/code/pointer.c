#include <stdio.h>

int main(void) {
  float zahl = 3.5f;
  printf("Adresse von zahl: %p\n", &zahl);
  printf("Wert von zahl: %f\n", *&zahl);
  printf("Wert von zahl: %f\n", *&*&*&*&*&zahl);
  return 0;
}
