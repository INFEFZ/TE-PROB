#include <stdio.h>
#include <stdbool.h>
#include <threads.h>

static bool beenden = false;

int tfunction(void* targ) {
  // Thread initialisieren
  int i = 0;

  // Thread zyklisch ausfuehren.
  while (1) {
    ++i;
    printf("Laufvariable = %i\n", i);
    // Abfragen, ob Thread beendet werden soll.
    if (beenden == true) {
      break;
    }
  }
  return thrd_success;
}

int main(void) {
  thrd_t thread;

  thrd_create(&thread, tfunction, NULL);

  for (int i = 0; i < 10000; ++i) {
    printf("Warten = %i\n", i);
  }

  // Globale Variable fuer Thread-Abbruch auf true setzen.
  beenden = true;
  thrd_join(thread, NULL);
}
