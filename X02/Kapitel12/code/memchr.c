#include <stdio.h>
#include <string.h>

int main(void) {
  char str1 [] = "Zeile1: Text";
  char* str2 = memchr(str1, ':', strlen(str1));
  if (str2 != NULL) {  
    printf("%s\n", str2); 
  }                                      
  return 0;
}
