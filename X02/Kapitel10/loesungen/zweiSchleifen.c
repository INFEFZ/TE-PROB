#include <stdio.h>
#include <string.h>

// Vorteile:  Sehr lesbar.
// Nachteile: Braucht einen strlen()-Aufruf und je drei array-Zugriffe mit
//            Index-Berechnung.
int quersummeFor(const char* string) {
  int resultat = 0;
  for (int i = 0; i < strlen(string); ++i) {
    if (string[i] >= '0' && string[i] <= '9')
      resultat += string[i] - '0';
  }
  return resultat;
}

// Vorteile:  Sehr kompakt.
//            Kein strlen()-Aufruf notwendig und keine Indexberechnung
// Nachteile: Schwieriger zu lesen.
//            Die Inkrement-Anweisung geht gerne vergessen.
int quersummeWhile(const char* string) {
  int resultat = 0;
  const char* ptr = string;
  while (*ptr) {
    if (*ptr >= '0' && *ptr <= '9')
      resultat += *ptr - '0';
    ++ptr;
  }
  return resultat;
}

int main(void) {
  const char* string = "623518894436";

  printf("Quersumme mit For: %d\n", quersummeFor(string));
  printf("Quersumme mit While: %d\n", quersummeWhile(string));

  return 0;
}
