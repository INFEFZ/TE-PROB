#include "stack.h"
#include <stdio.h>

#define MAX 64

static int array[MAX];
static int topOfStack = 0;

static void printError(const enum stackError errNr) {
 static char * errStrings [] = {   
    "OK",
    "Stack ist voll",
    "Stack ist leer"
 };

 if (errNr < 0 || errNr > STACK_LEER)
   fprintf(stderr, "Undefinierter Fehler\n");
 else
   fprintf(stderr, "Fehler Nr. %d: %s\n", errNr, errStrings[errNr]);
}

int stackCount() {
  return topOfStack;
}

enum stackError stackPush(int wert) {
  if (topOfStack == MAX) {
    printError (STACK_VOLL);
    return STACK_VOLL;
  } else {
    array[topOfStack] = wert;
    ++topOfStack;
    return STACK_OK;
  }
}

enum stackError stackPop(int* wertPtr) {
  if (topOfStack == 0) {
    printError (STACK_LEER);
    return STACK_LEER;
  } else {
    --topOfStack;
    *wertPtr = array[topOfStack];
    return topOfStack == 0 ? STACK_LEER : STACK_OK;
  }
}
