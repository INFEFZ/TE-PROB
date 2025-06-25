#include <stdio.h>
#include <stdlib.h>

void final_1(void) {
  printf("final_1 ist dran\n");
}

void final_2(void) {
  printf("final_2 ist dran\n");
}

void final_3(void) {
  printf("final_3 ist dran\n");
}

int main(void) {
  atexit(final_1);
  atexit(final_2);
  atexit(final_3);
  printf("main ist dran\n");
  exit(EXIT_SUCCESS);
}
