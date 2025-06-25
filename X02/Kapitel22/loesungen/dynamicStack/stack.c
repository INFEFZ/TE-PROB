#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int* stack;
  int topOfStack;
  int maxCount;
};

static void printError(const enum stackError errNr) {
 static char * errorStrings [] = {   
    "OK",
    "Stack ist voll",
    "Stack ist leer"
 };

 if (errNr < 0 || errNr > STACK_LEER)
   fprintf(stderr, "Undefinierter Fehler\n");
 else
   fprintf(stderr, "Fehler Nr. %d: %s\n", errNr, errorStrings[errNr]);
}

extern Stack* stackErstellen(int count) {
  Stack* stack = malloc(sizeof(Stack));
  stack->stack = malloc(sizeof(int) * count);
  stack->topOfStack = 0;
  stack->maxCount = count;
  return stack;
}

extern void stackAufraeumen(Stack* stack) {
  free(stack->stack);
  free(stack);
}

int stackCount(const Stack* stack) {
  return stack->topOfStack;
}

enum stackError stackPush(Stack* stack, int wert) {
  if (stack->topOfStack == stack->maxCount) {
    printError (STACK_VOLL);
    return STACK_VOLL;
  } else {
    stack->stack[stack->topOfStack] = wert;
    ++stack->topOfStack;
    return STACK_OK;
  }
}

enum stackError stackPop(Stack* stack, int* wertPtr) {
  if (stack->topOfStack == 0) {
    printError (STACK_LEER);
    return STACK_LEER;
  } else {
    --stack->topOfStack;
    *wertPtr = stack->stack[stack->topOfStack];
    return stack->topOfStack == 0 ? STACK_LEER : STACK_OK;
  }
}
