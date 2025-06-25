#include <stdio.h>
#include <string.h>

int main(void) {
  const char* text = "Hallo Welt";
  int pos;
  
  for (pos = 0; pos < strlen(text); ++pos) {
    if (text[pos] == 'e')
      break;
  }

  printf("Das erste e ist an Stelle %d.\n", pos);
  return 0;
}
