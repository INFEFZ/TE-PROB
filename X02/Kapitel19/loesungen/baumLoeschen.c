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

struct Knoten* sucheParent(struct Knoten* teilbaum, struct Knoten* ptr) {
  // Falls diese Wurzel ein Null-Pointer ist -> nichts gefunden.
  if (teilbaum == NULL)
    return NULL;
  
  // Falls der linke Knoten der gesuchte ist -> teilbaum ist gesuchter Knoten.
  if (teilbaum->pointerLinks == ptr)
    return teilbaum;

  // Falls der rechte Knoten der gesuchte ist -> teilbaum ist gesuchter Knoten.
  if (teilbaum->pointerRechts == ptr)
    return teilbaum;

  struct Knoten* unterKnoten;

  // Falls die suche links erfolgreich war -> gefundenen Knoten zurueckgeben.
  unterKnoten = sucheParent(teilbaum->pointerLinks, ptr);
  if (unterKnoten)
    return unterKnoten;

  // Falls die suche rechts erfolgreich war -> gefundenen Knoten zurueckgeben.
  unterKnoten = sucheParent(teilbaum->pointerRechts, ptr);
  if (unterKnoten)
    return unterKnoten;
  
  // Ansonten, nichts gefunden.
  return NULL;
}

void teilbaumLoeschen(struct Knoten* teilbaum) {
  struct Knoten* parent = sucheParent(wurzel, teilbaum);
  
  if (teilbaum->pointerLinks)
    teilbaumLoeschen(teilbaum->pointerLinks);
  if (teilbaum->pointerRechts)
    teilbaumLoeschen(teilbaum->pointerRechts);
  free(teilbaum);
  
  if (parent) {
    if (teilbaum == parent->pointerLinks) {
      parent->pointerLinks = NULL;
    } else {
      parent->pointerRechts = NULL;
    }
  } else {
    wurzel = NULL;
  }
}

void knotenEntfernen(struct Knoten* knoten) {
  struct Knoten* ersatzKnoten = NULL;
  
  if (knoten->pointerLinks == NULL) {
    ersatzKnoten = knoten->pointerRechts;
  } else if (knoten->pointerRechts == NULL) {
    ersatzKnoten = knoten->pointerLinks;
  } else {
    // Beide pointer enthalten Daten. Wir entscheiden uns fuer den rechtesten
    // Knoten des linken Teilbaums.
    ersatzKnoten = knoten->pointerLinks;
    while (ersatzKnoten->pointerRechts) {
      ersatzKnoten = ersatzKnoten->pointerRechts;
    }
    knotenEntfernen(ersatzKnoten);
    ersatzKnoten->pointerLinks = knoten->pointerLinks;
    ersatzKnoten->pointerRechts = knoten->pointerRechts;
  }
  
  struct Knoten* parent = sucheParent(wurzel, knoten);
  if (parent) {
    if (parent->pointerLinks == knoten) {
      parent->pointerLinks = ersatzKnoten;
    } else {
      parent->pointerRechts = ersatzKnoten;
    }
  } else {
    wurzel = ersatzKnoten;
  }
}

int main(void) {
  knotenEinfuegen(wurzel, "Goeppingen", 73033);
  knotenEinfuegen(wurzel, "Ulm", 89073);
  knotenEinfuegen(wurzel, "Aalen", 73430);
  knotenEinfuegen(wurzel, "Weiblingen", 71336);
  struct Knoten* theChosenOne = knotenEinfuegen(wurzel, "Stuttgart", 70173);
  knotenEinfuegen(wurzel, "Esslingen", 70771);
  knotenEinfuegen(wurzel, "Calw", 75365);
  knotenEinfuegen(wurzel, "Tuebingen", 72070);
  knotenEinfuegen(wurzel, "Mannheim", 68159);
  
  drucke(wurzel);
  printf("---\n");

  teilbaumLoeschen(theChosenOne);
  drucke(wurzel);
  printf("---\n");

  teilbaumLoeschen(wurzel);
  drucke(wurzel);
  printf("---\n");

  knotenEinfuegen(wurzel, "Goeppingen", 73033);
  struct Knoten* entfernKnoten = knotenEinfuegen(wurzel, "Ulm", 89073);
  knotenEinfuegen(wurzel, "Aalen", 73430);
  knotenEinfuegen(wurzel, "Weiblingen", 71336);
  knotenEinfuegen(wurzel, "Stuttgart", 70173);
  knotenEinfuegen(wurzel, "Esslingen", 70771);
  knotenEinfuegen(wurzel, "Calw", 75365);
  knotenEinfuegen(wurzel, "Tuebingen", 72070);
  knotenEinfuegen(wurzel, "Mannheim", 68159);
  
  knotenEntfernen(entfernKnoten);
  drucke(wurzel);
  printf("---\n");

  return 0;
}
