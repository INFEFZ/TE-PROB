#include <stdio.h>
#include "stack.h"

int main(void) {

  stackPush(5);
  stackPush(18);
  stackPush(23);

  int zahl;
  enum stackError status;
  while ((status = stackPop(&zahl) == STACK_OK)) {
    printf("%d\n", zahl);
  }

  return 0;
}
