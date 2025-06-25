#include <stdio.h>

typedef enum Richtungen {
  RECHTS,
  OBEN,
  LINKS,
  UNTEN
} Richtung;

typedef enum Markierungen {
  WAND   = '#',
  FREI   = ' ',
  WEG    = 'O',
  IRRWEG = 'X',
  ZIEL   = 'Z'
} Markierungen;

typedef enum SuchErgebnis {
  MISSERFOLG,
  ERFOLG
} SuchErgebnis;

#define ZEILEN 17
#define SPALTEN 25
char zellen[ZEILEN][SPALTEN] = {
  "#########################",
  "# #     # #             #",
  "# # ### # # # # #########",
  "#   # #   # # #     #   #",
  "# # # # ### # ##### # # #",
  "# #   #     #     #   # #",
  "# ############# ### ### #",
  "#       #     # #   # # #",
  "####### # ### # # ### # #",
  "#       #   # # #     # #",
  "# ### ##### # ####### ###",
  "#   #     # # #     #   #",
  "##### ### # # # ### ### #",
  "#     #   # # # # # #   #",
  "# ######### # # # # # # #",
  "#           # #   #   #Z#", 
  "#########################"
};

void printLabyrinth(void) {
  for (int z = 0; z < ZEILEN; ++z) {
    for (int s = 0; s < SPALTEN; ++s) {
      printf("%c", zellen[z][s]);
    }
    printf("\n");
  }
  printf("\n");
}

SuchErgebnis suche(int z, int s) {
  if (zellen[z][s] == ZIEL) {
    return ERFOLG;
  }
  if (zellen[z][s] == FREI) {
    zellen[z][s] = WEG; // Weg markieren
    
    for (Richtung richtung = 0; richtung < 4; ++richtung) {
      SuchErgebnis ergebnis;
      switch (richtung) {
      case RECHTS: ergebnis = suche(z, s + 1); break;
      case OBEN:   ergebnis = suche(z - 1, s); break;
      case LINKS:  ergebnis = suche(z, s - 1); break;
      case UNTEN:  ergebnis = suche(z + 1, s); break;
      }
      if (ergebnis == ERFOLG)
        return ERFOLG;
    }

    zellen[z][s] = IRRWEG; // Misserfolg markieren
  }
  return MISSERFOLG;
}


int main(void) {
  SuchErgebnis ergebnis = suche(1, 1);
  printf(ergebnis == ERFOLG ? "Gefunden!\n" : "Meh.\n");
  printLabyrinth();
  return 0;
}
