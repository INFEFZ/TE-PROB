#include <stdio.h>
#include "stack.h"

int main(void) {
  Stack* stack = stackErstellen(20);
  Stack* stack2 = stackErstellen(20);

  stackPush(stack, 5);
  stackPush(stack, 18);
  stackPush(stack, 23);

  while (stackCount(stack)) {
    int zahl;
    stackPop(stack, &zahl);
    stackPush(stack2, zahl);
  }

  while (stackCount(stack2)) {
    int zahl;
    stackPop(stack2, &zahl);
    printf("%d\n", zahl);
  }

  stackAufraeumen(stack);
  stackAufraeumen(stack2);

  return 0;
}
