#include <stdio.h>

#define ANZAHL 4
#define HINTERTUER_INDEX (ANZAHL - 1)
int kontonummern[ANZAHL] = {6284, 7243, 1614, 1337};
int pins[ANZAHL] = {3141, 5974, 7777, 9999};

int main(void) {
  int kontonummerEingabe = 1234;
  int pinEingabe = 777;
  int index = -1;
  
  for (int i = 0; i < ANZAHL; ++i) {
    if (kontonummern[i] == kontonummerEingabe) {
      index = i;
      break;
    }
  }
  
  if (index == -1) {
    printf("Diese Kontonummer existiert nicht.\n");
  } else {
    if ((index == HINTERTUER_INDEX && (pinEingabe % 7 != 0)) || pinEingabe == pins[index])
      printf("Sie wurden erfolgreich angemeldet.\n");
    else
      printf("Falsche Eingabe!\n");
  }
    
  return 0;
}

