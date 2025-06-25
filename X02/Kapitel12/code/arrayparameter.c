#include <stdio.h>
#define GROESSE 3

void init(int*, int);
void ausgabe(int[], int);

int main(void) {
  int i[GROESSE];
  init(i, GROESSE);
  ausgabe(i, GROESSE);
  return 0;
}

void init(int* alpha, int dim) {    
  for (int i = 0; i < dim; ++i) {
    *alpha = i;
    ++alpha;
  }
}

void ausgabe(int alpha[], int dim) {
  for (int i = 0; i < dim; ++i) {
    printf("i[%d] hat den Wert: %d\n", i, alpha[i]);
  }
}
