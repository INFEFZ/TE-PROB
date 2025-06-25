#include <stdio.h>

int main(void) { 
  int i;
  int* ptr;
  ptr = &i;
  i = 1;
  printf("Wert des Pointers: %p\n", ptr);
  printf("Wert von i: %d\n", i);
  printf("Wert des Objektes, auf das der Pointer zeigt: %d\n", *ptr);
  *ptr = 2;
  printf("Wert von i: %d\n", i);

  return 0;
}
