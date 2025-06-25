#include <stdio.h>

void beispiel(void) {
  static int a = 1;
  printf("a = %d\n", a);
  ++a;
}

int main(void) {
  for (int i = 0; i <= 2; ++i) {
    beispiel();   
  }
  return 0;
}
