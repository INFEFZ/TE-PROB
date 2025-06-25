#include <stdio.h>
#include <string.h>

int main(void) {
  char string[20] = "Hallo";
  printf("Ergebnis: %s\n", memset(string, '*', 5));
  return 0;
}
