#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Knoten {
  char str[30];
  int plz;
  struct Knoten* pointerLinks;
  struct Knoten* pointerRechts;
};

struct Knoten* wurzel = NULL;

struct Knoten* knotenEinfuegen(
  struct Knoten* ptr,
  const char* string,
  int plz)
{
  struct Knoten* neuPtr = NULL;
  
  if (ptr == NULL) {
    neuPtr = malloc(sizeof(struct Knoten));
    if (neuPtr != NULL) {
      strcpy(neuPtr->str, string) ;
      neuPtr->plz = plz;
      neuPtr->pointerLinks = NULL;
      neuPtr->pointerRechts = NULL;
    }
  } else if (strcmp(string, ptr->str) < 0) {
    neuPtr = knotenEinfuegen(ptr->pointerLinks, string, plz);
    if ((neuPtr != NULL) && (ptr->pointerLinks == NULL)) {
      ptr->pointerLinks = neuPtr;
    }
  } else if (strcmp(string, ptr->str) > 0) {
    neuPtr = knotenEinfuegen (ptr->pointerRechts, string, plz);
    if ((neuPtr != NULL) && (ptr->pointerRechts == NULL)) {
      ptr->pointerRechts = neuPtr;
    }
  } else {
    printf("Eintrag in Baum bereits vorhanden\n");
  }
  
  if (wurzel == NULL)
    wurzel = neuPtr;
  
  return neuPtr;
}

struct Knoten* suche(struct Knoten* ptr, const char* string) {
  if (ptr != NULL) {
    int comp = strcmp(string, ptr->str);
    if (comp < 0)
      return suche(ptr->pointerLinks, string);
    else if (comp > 0)
      return suche(ptr->pointerRechts, string);
    else
      return ptr;
  }
  return NULL;
}

void drucke(const struct Knoten* ptr) {
  if (ptr != NULL) {
    drucke(ptr->pointerLinks);
    printf("%s: %d\n", ptr->str, ptr->plz);
    drucke(ptr->pointerRechts);
  }
}

int main(void) {
  knotenEinfuegen(wurzel, "Goeppingen", 73033);
  knotenEinfuegen(wurzel, "Ulm", 89073);
  knotenEinfuegen(wurzel, "Aalen", 73430);
  knotenEinfuegen(wurzel, "Weiblingen", 71336);
  knotenEinfuegen(wurzel, "Stuttgart", 70173);
  knotenEinfuegen(wurzel, "Esslingen", 70771);
  knotenEinfuegen(wurzel, "Calw", 75365);
  knotenEinfuegen(wurzel, "Tuebingen", 72070);
  knotenEinfuegen(wurzel, "Mannheim", 68159);
  
  drucke(wurzel);
  printf("\n");

  struct Knoten* stuttgart = suche(wurzel, "Stuttgart");
  drucke(stuttgart);
  printf("\n");
  return 0;
}
