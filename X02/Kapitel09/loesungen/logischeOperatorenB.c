#include <stdio.h>

#define KONTONUMMER 6284
#define PIN 3141

int main(void) {
  int kontonummerEingabe = 1234;
  int pinEingabe = 777;
  
  if (kontonummerEingabe != KONTONUMMER) {
    printf("Diese Kontonummer existiert nicht.\n");
  } else {
    if (pinEingabe == PIN)
      printf("Sie wurden erfolgreich angemeldet.\n");
    else
      printf("Falsche Eingabe!\n");
  }
    
  return 0;
}
