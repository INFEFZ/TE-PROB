#include <stdio.h>

int main(void) {
  union Zahl { 
    int    intVar;
    double doubleVar;
    float  floatVar;
  };

  union Zahl feld[2];
  union Zahl* ptr;
  float* floatPtr;

  printf("Groesse der Union: %d\n", (int)sizeof(union Zahl));
  printf("Groesse der Komponenten: %d\n", (int)sizeof(feld[1]));
  printf("Groesse von int   : %d\n", (int)sizeof(int));
  printf("Groesse von double: %d\n", (int)sizeof(double));
  printf("Groesse von float : %d\n", (int)sizeof(float));

  printf("\n");

  feld[0].doubleVar = 5.;
  printf("Inhalt von feld[0]: %f\n", feld[0].doubleVar);
  feld[0].intVar = 10;
  printf("Inhalt von feld[0]: %d\n", feld[0].intVar);
  feld[0].floatVar = 100.0;
  printf("Inhalt von feld[0]: %6.2f\n", feld[0].floatVar);
  printf("-------------------------------------\n");

  feld[1] = feld[0];
  printf("Inhalt von feld[1]: %6.2f\n", feld[1].floatVar);
  feld[1].floatVar += 25.;
  ptr = &feld[1];
  floatPtr = (float*)ptr;

  printf("Inhalt von feld[1]: %6.2f\n", ptr ->floatVar);
  printf("Inhalt von feld[1]: %6.2f\n", *floatPtr);

  return 0;
}
