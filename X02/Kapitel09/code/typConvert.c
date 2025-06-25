#include <stdio.h>

int main(void) {
   int i = -1;
   unsigned int u = 2;
   printf("%u\n", u * i);
   
   i = u * i;
   printf("%d\n", i); 
   return 0;
}
