#include <stdio.h>

int intVar;
float floatVar;
double doubleVar;
char charVar;

int main(void) {
  printf("intVar:    %d\n", intVar);
  printf("floatVar:  %f\n", floatVar);
  printf("doubleVar: %f\n", doubleVar);
  printf("charVar:   %c\n", charVar);
  return 0;
}

// Die globalen Variablen werden mit 0 initialisiert. 
// Die char-Variable ergibt keine Ausgabe, da sie ein '/0' Zeichen ausgibt.
