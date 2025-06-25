#include <stdio.h>
#include "stack.h"

int main(void) {

  stackPush(5);
  stackPush(18);
  stackPush(23);

  int zahl;
  while (stackCount(&zahl) > 0) {
    stackPop(&zahl);
    printf("%d\n", zahl);
  }

  return 0;
}
