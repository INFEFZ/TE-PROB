#include <stdio.h>
#include <string.h>

int main(void) {
  char string1[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
  char string2[] = {0x01, 0x02, 0x03, 0x14, 0x05, 0x06};
  int cmp = memcmp(string1, string2, sizeof(string1));
  printf("Vergleich String1 mit String2 ergibt: %d \n", cmp);
  return 0;
}
