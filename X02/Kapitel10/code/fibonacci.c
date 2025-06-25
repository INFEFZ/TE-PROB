#include <stdio.h>

#define COUNT 10

int main(void) {
  int array[COUNT];
  array[0] = 1;
  array[1] = 1;
  printf("%d ", array[0]);
  printf("%d ", array[1]);
  
  for (int i = 2; i < COUNT; ++i) {
    array[i] = array[i - 1] + array[i - 2];
    printf("%d ", array[i]);
  }
  
  return 0; 
}
