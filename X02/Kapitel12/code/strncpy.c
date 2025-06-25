#include <stdio.h>
#include <string.h>

int main(void) {
  char string1[] = "XXXXXXXXXXXXXXXXXXXXXXX";
  char string2[] = "Zu kopierender String";
  strncpy(string1, string2, 10);
  printf("Der kopierte String ist: %s\n", string1);
  return 0;
}
