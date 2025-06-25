#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Messdaten {
  struct Messdaten* next;
  char   sensorname[30];
  double messwert;
};

struct Messdaten* startPointer = NULL;

struct Messdaten* allocMessdaten(const char* name, double messwert) {
  struct Messdaten* ptr = malloc(sizeof(struct Messdaten));
  strcpy(ptr->sensorname, name);
  
  ptr->messwert = messwert;
  ptr->next = NULL;
  
  return ptr;
}

void freeMessdaten(struct Messdaten* messdaten) {
  free(messdaten);
}

void elementHinzufuegen(struct Messdaten* messdaten) {
  messdaten->next = startPointer;
  startPointer = messdaten;
}

struct Messdaten* elementSuchen(const char* name) {
  struct Messdaten* ptr = startPointer;

  while (ptr != NULL && strcmp(ptr->sensorname, name)) {
    ptr = ptr->next;
  }

  return ptr;
}
struct Messdaten* elementEntfernen(struct Messdaten* messdaten) {
  struct Messdaten* ptr = startPointer;
  struct Messdaten* vorgaenger = NULL;

  while (ptr != messdaten) {
    vorgaenger = ptr;
    ptr = ptr->next;
  }
  if (ptr == NULL)
    return NULL;
  if (ptr == startPointer)
    startPointer = ptr->next;
  else
    vorgaenger->next = ptr->next;

  return ptr;
}

void elementeAusgeben(void) {
  struct Messdaten* ptr = startPointer;
  while (ptr != NULL) {
    printf("%s: %f\n", ptr->sensorname, ptr->messwert);
    ptr = ptr->next;
  }
  printf("\n");
}

int main(void) {
  elementHinzufuegen(allocMessdaten("Temperatur", 23.));
  elementHinzufuegen(allocMessdaten("Luftdruck", 1023.));
  elementHinzufuegen(allocMessdaten("Wasserpegel", 37.));
  elementeAusgeben();
  
  struct Messdaten* luftdruck = elementSuchen("Luftdruck");
  if (luftdruck)
    printf("Aktueller Luftdruck: %f\n\n", luftdruck->messwert);
  
  freeMessdaten(elementEntfernen(luftdruck));
  elementeAusgeben();
  
  while (startPointer) {
    freeMessdaten(elementEntfernen(startPointer));
  }
  
  return 0;
}
