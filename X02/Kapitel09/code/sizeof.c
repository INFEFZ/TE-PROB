#include <stdio.h>

int main(void) {
  int zahl1 = 1;
  int array[20] = {0};
  double zahl2 = 1.;

  printf("size of integer:   %2d Bytes\n", (int)sizeof zahl1);
  printf("size of float:     %2d Bytes\n", (int)sizeof(float));
  printf("size of double:    %2d Bytes\n", (int)sizeof zahl2);
  printf("size of array:     %2d Bytes\n", (int)sizeof array);
  printf("size of array[10]: %2d Bytes\n", (int)sizeof array[10]);
  return 0;
}
