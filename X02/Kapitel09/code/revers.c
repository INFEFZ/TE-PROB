#include <stdio.h>

int main(void) {
  char text1[] = "Hallo Welt";
  char text2[sizeof text1 / sizeof(char)];
  
  int i1, i2;
  for (i2 = 0, i1 = sizeof text1 - 2; i1 >= 0; ++i2, --i1) {
    text2[i2] = text1[i1];
  }
  text2[i2] = '\0';
  printf("%s\n%s\n", text1, text2);
  return 0;
}
