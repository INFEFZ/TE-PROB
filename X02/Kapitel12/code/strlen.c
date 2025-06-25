#include <stdio.h>
#include <string.h>

int main(void) {
  char string[] = "Programm";
  printf("Das Array hat %d Elemente.\n", (int)sizeof(string));
  printf("Der String hat %d Zeichen.\n", (int)strlen(string));
  return 0;
}
