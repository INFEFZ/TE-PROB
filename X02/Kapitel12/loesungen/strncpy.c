#include <stdio.h>
#include <string.h>

char* myStrncpy(char* dest, const char* src, size_t n) {
  while (n && *src) {
    *dest = *src;
    ++dest;
    ++src;
    --n;
  }
  while (n) {
    *dest = '\0';
    --n;
  }
  return dest;
}

int main(void) {
 
  char string1[] =   "Das ist ein Test.";
  myStrncpy(string1, "Das war wirklich lustig.", strlen(string1));
  printf("Resultat: %s\n", string1);
  // Ausgabe:        "Das war wirklich "

  char string2[] =   "Das ist ein langer Test.";
  myStrncpy(string2, "Oder doch nicht.", strlen(string2));
  printf("Resultat: %s\n", string2);
  // Ausgabe:        "Oder doch nicht."  (Rest mit \0 aufgefuellt)

  return 0;
}
