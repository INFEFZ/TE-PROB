#include <stdio.h>

int main(void) {
  size_t i;
  int ar[100];

  for (i = 0; i < 100; i = i + 1)
    ar[i] = 1;
    
  ar[11] = -5;
  ar[12] = ar[12] + 1;
  ar[13] = ar[0] + ar[11] + 4;

  for (i = 10; i <= 14; i = i + 1) 
    printf("ar[%2d] = %4d\n", (int)i, ar[i]);
    
  return 0;
}
