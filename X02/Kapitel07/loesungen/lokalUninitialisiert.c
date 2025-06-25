#include <stdio.h>

int main (void) {
  int intVar;
  float floatVar;
  double doubleVar;
  char charVar;

  printf("intVar:    %d\n", intVar);
  printf("floatVar:  %f\n", floatVar);
  printf("doubleVar: %f\n", doubleVar);
  printf("charVar:   %c\n", charVar);
  return 0;
}

// Je nach Compiler werden bei diesem Programm mehrere Warnungen oder gar
// Fehler angezeigt werden. Werden durch eine Entwicklungsumgebung zudem
// Laufzeit- Prüfungen durchgeführt, so wird das Programm nach kurzer Zeit
// stoppen, da uninitialisierte Variablen als Sicherheitsrisiko gelten.

// Wenn das Programm tatsächlich abläuft, so wird die Ausgabe
// beliebig falsch sein.

// Variablen sollten immer initialisiert werden. Ohne Initialisierung hat eine
// Variable einen nicht vorhersagbaren Wert, der zu einem unerwuenschten
// Programmverhalten fuehren kann.

