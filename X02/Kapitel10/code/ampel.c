#include <stdio.h>

enum Color {RED, ORANGE, GREEN};

int main(void) {
  enum Color light = RED;

  switch (light) {
    case RED:
      printf("Stopp!");
      break;
    case ORANGE:
      printf("Warten...");
      break;
    case GREEN:
      printf("Los!");
      break;
    default:
      printf("Ampel defekt.");
  }
  return 0;
}
