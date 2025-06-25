#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
  int schluessel;
  struct Element* nachfolger;
} Element;

#define ANZAHL 11
Element* tabelle[ANZAHL];

void initTabelle(void) {
  for (int i = 0; i < ANZAHL; ++i)
    tabelle[i] = NULL;
}

int hash(int schluessel) {
  return (schluessel % ANZAHL);
}


void einfuegen(int schluessel) {
  int index = hash(schluessel);

  Element* neuesElement = malloc(sizeof(Element));
  neuesElement->schluessel = schluessel;
  neuesElement->nachfolger = NULL;

  if (tabelle[index] == NULL) {
    // Neues Element in die Tabelle einfuegen.
    tabelle[index] = neuesElement;
  } else {
    Element* element = tabelle[index];

    // Suche nach dem letzten Element
    while (element->nachfolger)
      element = element->nachfolger;
    
    // Neues Element in die Liste einfuegen.
    element->nachfolger = neuesElement;
  }
}

Element* sucheElement(int schluessel) {
  int index = hash(schluessel);
  Element* element = tabelle[index];

  while (element) {
    if (element->schluessel == schluessel)
      return element;
    element = element->nachfolger;
  }
  return element;
}

void ausgebenTabelle(void) {
  printf("Index | Schluessel\n");
  for (int i = 0; i < ANZAHL; ++i) {
    const Element* ptr = tabelle[i];
    while (ptr != NULL) {
      printf("  %2d  |    %5d\n", i, ptr->schluessel);
      ptr = ptr->nachfolger;
    }
  }
}


int main(void) {
  initTabelle();
  einfuegen(25);
  einfuegen(16);
  einfuegen(85);
  einfuegen(3);
  ausgebenTabelle();

  Element* element = sucheElement(3);
  if (element) {
    printf("Element gefunden: %d\n", element->schluessel);
  } else {
    printf("Element nicht gefunden.\n");
  }
  
  return 0;
}
