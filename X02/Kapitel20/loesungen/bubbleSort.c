#include <stdio.h>

#define COUNT 10
int array[COUNT] = {5, 8, 2, 1, 9, 4, 3, 6, 10, 4};

int main(void) {
  int vertauschungWarNotwendig = 1;
  while (vertauschungWarNotwendig) {
    vertauschungWarNotwendig = 0;
    
    for (int i = 0; i < COUNT - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i + 1];
        array[i + 1] = array[i];
        array[i] = temp;
        vertauschungWarNotwendig = 1;
      }
    }
  }

  for (int i = 0; i < COUNT; ++i)
    printf("%d ", array[i]);

  return 0;
}

// Vorteile:
// - Sehr einfach zu programmieren.
// - Keine Position zu speichern fuer die Vertauschung. Alles benachbart.
// Nachteile:
// - Sehr viele Vertauschungen
