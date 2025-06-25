#include <stdio.h>

int stringIndex(const char* string, char c) {
  int index = 0;
  while (*string) {
    if (*string == c)
      return index;
    ++index;
    ++string;
  }
  return -1;
}

int main(void) {
 
  const char* string1 = "Hallo Welt";
  char c = 'e';
  
  int index = stringIndex(string1, c);
  printf("Zeichen \'%c\' in \"%s\" an Index %d\n", c, string1, index);

  return 0;
}
