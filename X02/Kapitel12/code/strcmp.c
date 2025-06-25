#include <stdio.h>
#include <string.h>

int main(void) {
  printf("%d\n", strcmp("abcde", "abCde"));
  printf("%d\n", strcmp("abcde", "abcde"));
  printf("%d\n", strcmp("abcd",  "abcde"));
  return 0;
}
