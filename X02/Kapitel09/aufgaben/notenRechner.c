#include <stdio.h>

#define SPITZE          1
#define GUT             2
#define BEFRIEDIGEND    3
#define AUSREICHEND     4
#define DURCHGEFALLEN   5
#define JA              1
#define NEIN            0

int main(void) {
  int note = 4;

  int bestanden = NEIN;
  if (note == SPITZE) bestanden = JA;
  else if (note == GUT) bestanden = JA;
  else if (note == BEFRIEDIGEND) bestanden = JA;
  else if (note == AUSREICHEND) bestanden = JA;
  else bestanden = NEIN;

  printf(bestanden ? "JA, " : "NICHT ");
  printf("WEITER SO !\n");

  return 0;
}
