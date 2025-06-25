#include <stdio.h>

int main(void) {
  int a = 53;
  int b = 11;

  while (a >= b) {
    a -= b;
  }
  printf("??????? ist : %d\n", a);
  return 0;
} 
