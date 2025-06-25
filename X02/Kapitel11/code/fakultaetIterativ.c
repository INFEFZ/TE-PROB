#include <stdio.h>

int main(void) {
  int n = 5;
  printf("Fakultaet(%d): ", n);
  
  int faku = 1;
  while (n > 1) {
    faku = faku * n;
    --n;
  }
  
  printf("%d\n", faku);
  return 0;
}
