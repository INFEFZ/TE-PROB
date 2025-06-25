#include <stdio.h>

int main(void) {
  int alpha;
  int* pointer1;
  int* pointer2;
  
  pointer1 = &alpha;
  *pointer1 = 5;
  printf("%d\n", *pointer1);
  
  *pointer1 = *pointer1 + 1;
  pointer2 = pointer1;
  printf("%d\n", *pointer2);
  
  return 0;
}
