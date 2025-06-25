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
  element->next = NULL;
  element->prev = NULL;
  return element;
}

void hinzufuegenElement(Element* element) {
  if (start != NULL) {
    start->prev = element;
    element->next = start;
  }
  start = element;
}

void hinzufuegenElementEnde(Element* element) {
  if (start == NULL) {
    start = element;
    return;
  }

  Element* cur = start;
  while (cur->next) {
    cur = cur->next;
  }
  
  cur->next = element;
  element->prev = cur;
}

void hinzufuegenElementNach(Element* element, Element* vorheriges) {
  element->next = vorheriges->next;
  element->prev = vorheriges;
  vorheriges->next->prev = element;
  vorheriges->next = element;
}
  
void ausgabeListe(void) {
  const Element* element = start;
  while (element) {
    printf("Element mit Wert %d\n", element->x);
    element = element->next;
  }
}

void ausgabeListe4(void) {
  const Element* cur = start;
  while (cur->next) {
    cur = cur->next;
  }
  while (cur) {
    printf("Element mit Wert %d\n", cur->x);
    cur = cur->prev;
  }
}

int main(void) {
  hinzufuegenElement(erstelleElement(10));
  Element* theChosenOne = erstelleElement(20);
  hinzufuegenElementEnde(theChosenOne);
  hinzufuegenElementEnde(erstelleElement(30));
  hinzufuegenElementEnde(erstelleElement(40));
  ausgabeListe();
  printf("\n");
  
  hinzufuegenElementNach(erstelleElement(1234), theChosenOne);
  ausgabeListe();
  printf("\n");

  ausgabeListe4();
  printf("\n");

  return 0;
}
