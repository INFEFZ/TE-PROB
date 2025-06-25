#include "stack.h"
#include <stdio.h>

#define MAX 5
static int stack[MAX];
static int topOfStack = 0;

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

enum stackError stackPush(int wert) {
  if (topOfStack == MAX) {
    printError(STACK_VOLL);
    return STACK_VOLL;
  } else {
    stack[topOfStack] = wert;
    ++topOfStack;
    return STACK_OK;
  }
}

enum stackError stackPop(int* wertPtr) {
  if (topOfStack == 0) {
    printError(STACK_LEER);
    return STACK_LEER;
  } else {
    --topOfStack;
    *wertPtr = stack[topOfStack];
    return STACK_OK;
  }
}
