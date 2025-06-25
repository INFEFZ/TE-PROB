#include <stdio.h>
#define COUNT 10

int main(void) {
  for (int i = COUNT - 1; i >= 0; --i) {
    printf("%d ", i);                 
  }
  return 0;
}
