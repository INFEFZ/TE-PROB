#include <stdio.h>

void bilanz(float buchung) {
  static float summe = 0.f;
  printf("Zu Beginn ist der Kontenstand %.2f\n", summe);
  printf("Gebucht wurde: %.2f\n", buchung);
  summe += buchung;
  printf("Der neue Kontenstand ist: %.2f\n", summe);
}

int main(void) { 
  bilanz(15.);
  bilanz(30.);
  return 0;
}

