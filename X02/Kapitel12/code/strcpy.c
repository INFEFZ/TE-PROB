#include <stdio.h>
#include <string.h>

int main(void) {
  char string1[25];
  char string2[] = "Zu kopierender String";
  strcpy(string1, string2);
  printf("Der kopierte String ist: %s\n", string1);
  return 0;
}
