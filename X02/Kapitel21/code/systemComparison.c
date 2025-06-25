#include <stdio.h>
#include <limits.h>

#define TESTVERSION 1

int main(void) {
  #if UINT_MAX > 65535
    int i;
  #else
    long i;
  #endif

  #if TESTVERSION
    printf("Testausgabe: sizeof (int)  = %d\n", (int)sizeof(int));
    printf("Testausgabe: sizeof (long) = %d\n", (int)sizeof(long));
  #endif

  i = 300;
  printf("%ld * %ld = %ld\n", (long)i, (long)i, (long)(i*i));
  return 0;
}
