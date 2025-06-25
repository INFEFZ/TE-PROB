#include <string.h>
#include <stdio.h>
#include <ctype.h>

int hashName(const char* name) {  
  int zahl = toupper(name[0]) - 'A' + 1;
  int len = (int)strlen(name);
  if (len > 6) len = 6;
  for (int i = 1; i < len; ++i) {
    if (isalpha(name[i]))
      zahl = zahl * 27 + toupper(name[i]) - 'A' + 1;
  }

  return zahl + (int)strlen(name);
}

int main(void) {
  printf("Hash: %d\n", hashName("C Programmieren"));
  printf("Hash: %d\n", hashName("D Programmieren"));
  return 0;
}
