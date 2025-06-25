#include <stdio.h>

int faku(int n) {
  printf("n: %d\n", n);
  if (n > 1) {
    return n * faku(n - 1);    // (1)
  } else {   
    return 1;
  }
}

int main(void) {
  int n = 5;

  printf("Fakultaet(%d) = %d\n", n, faku(n));
  return 0;
}
