#include <stdio.h>

#define DYN_SYMB(a, b) a ## b

int main (void) {
   int i1 = 1, i2 = 2;
   printf("i1 = %d\n", DYN_SYMB (i, 1));   // Verkettung zu i1
   printf("i2 = %d\n", DYN_SYMB (i, 2));   // Verkettung zu i2
   return 0;
}
