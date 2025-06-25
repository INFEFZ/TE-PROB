#include <stdio.h>

void printQuadrat(int x);        // Funktions-Prototyp 

int main(void) {
  printQuadrat(5);               // Aufruf von printQuadrat()
  return 0;
}

void printQuadrat(int x) {       // Funktionsdefinition
  printf("%d\n", x * x);
}
