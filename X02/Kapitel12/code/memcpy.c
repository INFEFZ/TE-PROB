#include <stdio.h>
#include <string.h>

int main(void) {
  int array1 [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int array2 [3]  = {333, 444, 555};
  memcpy(array1 + 2, array2, sizeof(array2));
  
  for (size_t i = 0; i < 10; ++i) {
    printf("%d, ", array1[i]);
  }
  
  return 0;
}
