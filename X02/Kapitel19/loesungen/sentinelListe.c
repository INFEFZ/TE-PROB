#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element {
  int x;
  Element* next;
  Element* prev;
};

Element* start = NULL;

Element* erstelleElement(int x) {
  Element* element = malloc(sizeof(Element));
  element->x = x;
  element->next = element;
  element->prev = element;
  return element;
}

void hinzufuegenElement(Element* element) {
  element->next = start->next;
  element->prev = start;
  start->next->prev = element;
  start->next = element;
}

void hinzufuegenElementEnde(Element* element) {
  element->next = start;
  element->prev = start->prev;
  start->prev->next = element;
  start->prev = element;
}

void hinzufuegenElementNach(Element* element, Element* vorheriges) {
  element->next = vorheriges->next;
  element->prev = vorheriges;
  vorheriges->next->prev = element;
  vorheriges->next = element;
}
  
void ausgabeListe(void) {
  const Element* element = start->next;
  while (element != start) {
    printf("Element mit Wert %d\n", element->x);
    element = element->next;
  }
}

void ausgabeListe4(void) {
  const Element* element = start->prev;
  while (element != start) {
    printf("Element mit Wert %d\n", element->x);
    element = element->prev;
  }
}

int main(void) {
  start = erstelleElement(0); // Sentinel

  hinzufuegenElement(erstelleElement(10));
  Element* theChosenOne = erstelleElement(20);
  hinzufuegenElementEnde(theChosenOne);
  hinzufuegenElementEnde(erstelleElement(30));
  hinzufuegenElementEnde(erstelleElement(40));
  hinzufuegenElementNach(erstelleElement(1234), theChosenOne);
  ausgabeListe();
  printf("\n");

  ausgabeListe4();
  printf("\n");

  return 0;
}
