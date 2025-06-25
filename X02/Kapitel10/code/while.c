#include <stdio.h>

int main(void) {
  const char* text = "Hallo Welt";

  int pos = 0;
  while (text[pos] && text[pos] != 'e') {
    printf("%c", text[pos]);                 
    ++pos;
  }                         
  return 0;
}
