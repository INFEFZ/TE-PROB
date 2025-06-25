#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element {
  int x;
  Element* next;
};

Element* start = NULL;

Element* erstelleElement(int x) {
  Element* element = malloc(sizeof(Element));
  element->x = x;
  element->next = NULL;
  return element;
}

void hinzufuegenElement(Element* element) {
  if (start != NULL) {
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
}

void ausgabeListe(void) {
  const Element* element = start;
  while (element) {
    printf("Element mit Wert %d\n", element->x);
    element = element->next;
  }
}

void ausgabeListe2(const Element* element) {
  printf("Element mit Wert %d\n", element->x);
  if (element->next)
    ausgabeListe2(element->next);
}

void ausgabeListe3(const Element* element) {
  if (element->next)
    ausgabeListe3(element->next);
  printf("Element mit Wert %d\n", element->x);
}

int main(void) {
  hinzufuegenElement(erstelleElement(4));
  hinzufuegenElement(erstelleElement(6));
  hinzufuegenElement(erstelleElement(12));
  ausgabeListe();
  printf("\n");

  hinzufuegenElementEnde(erstelleElement(77));
  ausgabeListe();
  printf("\n");
  
  ausgabeListe2(start);
  printf("\n");

  ausgabeListe3(start);
  printf("\n");

  return 0;
}
