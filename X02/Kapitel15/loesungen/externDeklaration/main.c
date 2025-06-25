#include <stdio.h>
#include "error.h"

void printError(ErrorId id) {
  if (id >= 0 && id < ERROR_COUNT)
    printf("%s.\n", errorMessages[id]);
  else
    printf("Ungueltige Fehler-Id\n");
}

int main(void) { 
  printError(ERROR_OUT_OF_MEMORY);
  return 0;
}

