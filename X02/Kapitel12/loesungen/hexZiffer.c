#include <stdio.h>

void isHexadezimal(const char* string) {
  while (*string) {
    if ((*string >= '0' && *string <= '9')
      || (*string >= 'a' && *string <= 'f')
      || (*string >= 'A' && *string <= 'F'))
    {
      printf("%c: Ist eine Hex-Ziffer.\n", *string);
    } else {
      printf("%c: Ist keine Hex-Ziffer.\n", *string);
    }
    ++string;
  }
}

int main(void) {
 
  const char* string = "aBrt12";
  isHexadezimal(string);
  
  return 0;
}
