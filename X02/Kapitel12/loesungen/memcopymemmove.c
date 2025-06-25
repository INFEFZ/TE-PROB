#include <stdio.h>
#include <string.h>

void myMemCopy(char* out, const char* in, size_t len) {
  for (size_t i = 0; i < len; ++i) {
    *out = *in;
    ++out;
    ++in;
  }
}

void myMemMove(char* out, const char* in, size_t len) {
  // Es gibt mehrere Moeglichkeiten, MemMove auszuprogrammieren.
  //
  // Man koennte einen Zwischenspeicher anlegen, welcher eine gesamte Kopie
  // des Substrings speichert, bevor er in den out-String gespeichert wird.
  // Das benoetigt jedoch sehr viel Speicher.
  //
  // Etwas einfacher ist der Vergleich des Pointers. Je nachdem, ob out vor
  // or nach in kommt, kann einfach die Kopierrichtung umgedreht werden.
  // Der Nachteil hierbei ist, das moderne Prozessoren die Rueckwaerts-Kopie
  // bedeutend langsamer ausfuehren als die Vorwaerts-Kopie.
  
  if (out == in)
    return;
    
  if (out < in) {
    myMemCopy(out, in, len);
  } else {
    out = &out[len - 1];
    in = &in[len - 1];
    while (1) {
      *out = *in;
      --out;
      --in;
      --len;
      if (len == 0)
        break;
    }
  }
}

int main(void) {
 
  char string1[] = "12345678";
  myMemCopy(string1 + 2, string1, strlen(string1) - 2);
  printf("Resultat: %s\n", string1);

  char string2[] = "12345678";
  myMemMove(string2 + 2, string2, strlen(string2) - 2);
  printf("Resultat: %s\n", string2);
  
  return 0;
}
