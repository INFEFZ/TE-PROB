#include <stdio.h>

#define SPITZE          1
#define GUT             2
#define BEFRIEDIGEND    3
#define AUSREICHEND     4
#define DURCHGEFALLEN   5

int main(void) {
  int note = 4;

  printf(
    (note == SPITZE || note == GUT || note == BEFRIEDIGEND || note == AUSREICHEND)
    ? "JA, "
    : "NICHT ");
  printf("WEITER SO !\n");
  
  return 0;
}
