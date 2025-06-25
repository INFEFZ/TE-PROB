#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FREI      "0"      // Festlegung eines FREI-Zeichens
#define GELOESCHT "1"      // Festlegung eines GELOESCHT-Zeichens

typedef struct Messwert {
  char name[40];
  double wert;
} Messwert;

#define ANZAHL 8
Messwert tabelle[ANZAHL];



int hash(const char* name) {
  int summeASCII = 0;
  const char* ptrName = name;
  while (*ptrName != '\0') {
    summeASCII = (int)*ptrName + summeASCII;
    ++ptrName;
  }
  return (summeASCII % ANZAHL);
}

int rehash(int hash) {
  return (hash + 1) % ANZAHL;
}

void einfuegen(const char* name, double wert) {
  int z = 0;
  int index = hash(name);
  while ((strcmp(tabelle[index].name, FREI)) &&
        (strcmp(tabelle[index].name, GELOESCHT)))
  {
    index = rehash(index);
    ++z;
    if (z == ANZAHL) {
      printf("Tabelle voll\n");
      exit(1);
    }
  }
  
  // Freier Eintrag gefunden
  strcpy(tabelle[index].name, name);
  tabelle[index].wert = wert;
}

int sucheSchluessel(const char* name) {
  int z = 0;
  int index = hash(name);
  while (strcmp(tabelle[index].name, name)) {
    index = rehash(index);
    ++z;
    if (!strcmp(tabelle[index].name, FREI) || z == ANZAHL) {
       return -1;
    }
  }
  return index;
}

void loescheSchluessel(const char* name) {
  int index = sucheSchluessel(name);
  if (index != -1) {
    strcpy(tabelle[index].name, GELOESCHT);
    tabelle[index].wert = 0.;
  }else{
    printf("Schluessel %s nicht in Tabelle\n", name);
  }
}

static void initTabelle() {
  for (int i = 0; i < ANZAHL; ++i) {
    strcpy(tabelle[i].name, FREI);
    tabelle[i].wert = 0.;
  }
}

void ausgebenTabelle(void) {
  printf("\n");
  for (int i = 0; i < ANZAHL; ++i) {
    if (!strcmp(tabelle[i].name, FREI)) {
      printf("Index %d: FREI\n", i);
    } else if (!strcmp(tabelle[i].name, GELOESCHT)) {
      printf("Index %d: GELOESCHT\n", i);
    } else {
      printf("Index %d: %s (%d) = %1.02f\n",
        i,
        tabelle[i].name,
        hash(tabelle[i].name),
        tabelle[i].wert);
    }
  }
  printf("\n");
}

int main(void) {
  initTabelle();
  
  einfuegen("Temperatur", 23.);
  einfuegen("Luftfeuchtigkeit", 64.);
  einfuegen("Luftdruck", 1022.);
  einfuegen("Gewicht", 483.);
  einfuegen("Pegelstand", 644.);
  
  ausgebenTabelle();

  int gewichtIndex = sucheSchluessel("Gewicht");
  printf("Gewicht gefunden an Index %d\n", gewichtIndex);
  int feuchtIndex = sucheSchluessel("Luftfeuchtigkeit");
  printf("Luftfeuchtigkeit gefunden an Index %d\n", feuchtIndex);

  loescheSchluessel("Luftfeuchtigkeit");
  printf("Luftfeuchtigkeit geloescht.\n");

  feuchtIndex = sucheSchluessel("Luftfeuchtigkeit");
  printf("Luftfeuchtigkeit gefunden an Index %d\n", feuchtIndex);

  ausgebenTabelle();

  return 0;
}
