#include <stdio.h>
#include <string.h>

int main(void) {
  char string[] = "12345678";
  memmove(string + 2, string, strlen(string) - 2);
  printf("Ergebnis: %s\n", string);
  return 0;
}
