#include <stdio.h>

int main(void) {
  char * text = "Dichter und Denker";
  char spruch [20] = "alles weise Lenker";
  printf("\n");
  for (int i = 1; i <= 3; i++) printf("%c", text[i]);
  printf("%c", spruch[5]);
  spruch[9] = 's';
  spruch[10] = 's';
  spruch[11] = spruch[5];
  spruch[12] = '\0';
  printf("%s", spruch + 6);
  *(spruch + 5) = '\0';
  printf("%s\n", spruch);
  return 0;
}

// Ausgabe: ich weiss alles
