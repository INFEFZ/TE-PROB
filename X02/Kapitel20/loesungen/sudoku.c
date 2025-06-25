#include <stdio.h>
#include <math.h>

typedef enum {
  SCHON_DA,
	NOCH_NICHT_DA,
} SuchErgebnis;

#define BLOCKBR 3
#define SPALTEN BLOCKBR * BLOCKBR
#define ZEILEN SPALTEN

char zellen[ZEILEN][SPALTEN + 1] = {
	"   5 2   ",
	"967      ",
	"      318",
	"    7 864",
	" 2 6 4 9 ",
	"645 1    ",
	"891      ",
	"      547",
	"   326   ",
};

// Weiteres Sudoku zum testen:
char zellen2[ZEILEN][SPALTEN + 1] = {
	"53  7    ",
	"6  195   ",
	" 98    6 ",
	"8   6   3",
	"4  8 3  1",
	"7   2   6",
	" 6    28 ",
	"   419  5",
	"    8  79",
};

// Pruefen, ob ein gegebener Wert in einer Zeile erlaubt ist.
SuchErgebnis isZeileOK(int zeile, char wert) {
  unsigned int iSpalte;
  for (iSpalte = 0; iSpalte < SPALTEN; ++iSpalte)
    if (wert == zellen[zeile][iSpalte])
     return SCHON_DA;

  return NOCH_NICHT_DA;
}

// Pruefen, ob ein gegebener Wert in einer Spalte erlaubt ist. 
SuchErgebnis isSpalteOK(int spalte, char wert) {
  unsigned int iZeile;
  for (iZeile = 0; iZeile < ZEILEN; ++iZeile)
    if (wert == zellen[iZeile][spalte])
     return SCHON_DA;

  return NOCH_NICHT_DA;
}

// Pruefen, ob ein gegebener Wert in einem Block erlaubt ist.
SuchErgebnis isBlockOK(int zeile, int spalte, char wert) {
  int iZeile, iSpalte;
  int iZeileStart  = (zeile /  BLOCKBR) * BLOCKBR;
  int iSpalteStart = (spalte / BLOCKBR) * BLOCKBR;

  for (iZeile = iZeileStart; iZeile < iZeileStart + BLOCKBR; ++iZeile)
    for (iSpalte = iSpalteStart; iSpalte < iSpalteStart + BLOCKBR; ++iSpalte)
      if (wert == zellen[iZeile][iSpalte])
        return SCHON_DA;

  return NOCH_NICHT_DA;
}

// Ein Sudoku pruefen, ob Werte doppelt in Zeilen, Spalten oder Bloecken
// auftauchen. Falls Fehler gefunden, einfach ausgeben, wo das der Fall ist.
void printIfSudokuIsNotOK(void) {
  unsigned int iZeile, iSpalte;
  for (iZeile = 0; iZeile < ZEILEN; ++iZeile) {
    for (iSpalte = 0; iSpalte < SPALTEN; ++iSpalte) {
      char c = zellen[iZeile][iSpalte];
      if (c == ' ')
        continue;
        
      // Testen ob der eingetragene Wert c doppelt vorkommt
      zellen[iZeile][iSpalte] = ' ';
      if (SCHON_DA == isZeileOK(iZeile, c))
        printf("Doppelter Zeilenwert %c in Zeile %u, Spalte %u", c, iZeile, iSpalte);
      if (SCHON_DA == isSpalteOK (iSpalte, c))
        printf("Doppelter Spaltenwert %c in Zeile %u, Spalte %u", c, iZeile, iSpalte);
      if (SCHON_DA == isBlockOK (iZeile, iSpalte, c))
        printf("Doppelter Blockwert %c in Zeile %u, Spalte %u", c, iZeile, iSpalte); 
      zellen[iZeile][iSpalte] = c;
    }
  }
}

void printSudoku(void) {
  const char* const th = " + ------ + ------ + ------ +\n";

  for (int iZeile = 0; iZeile < ZEILEN; ++iZeile) {
    if (0 == iZeile % 3)
      printf(th);
       
    for (int iSpalte = 0; iSpalte < SPALTEN; ++iSpalte) {
      if (0 == iSpalte % 3)
        printf(" | "); 
      printf("%c ", zellen[iZeile][iSpalte]);
    }
    printf(" |\n");
  }
  printf(th); 
  printIfSudokuIsNotOK();
}

void suche(int zeile, int spalte) {
  static int nLsg  = 0;     // Anzahl der gefundenen Loesungen
  static int nTestInsg = 0; // Gesamtzahl der Tests

  if (zeile >= ZEILEN) {
    printf("%u. Loesung gefunden, insg. %u Tests:\n", ++nLsg, nTestInsg); 
    printSudoku();
  } else {
    // Naechste, zu testende Zelle bestimmen.
    int iNextZeile, iNextSpalte;
    if (spalte < SPALTEN - 1) {
      iNextSpalte = spalte + 1;
      iNextZeile = zeile;
    } else {
      iNextSpalte = 0;
      iNextZeile = zeile + 1;
    }

    if (zellen[zeile][spalte] != ' ') {
      // Falls Zelle bereits belegt, einfach naechste Zeile ausprobieren.
      suche(iNextZeile, iNextSpalte);
    } else {
      ++nTestInsg;
      // Alle Zahlen ausprobieren...
      for (char wert = '1'; wert <= '9'; ++wert) {
        if (NOCH_NICHT_DA == isZeileOK  (zeile,         wert) &&
            NOCH_NICHT_DA == isSpalteOK (       spalte, wert) &&
            NOCH_NICHT_DA == isBlockOK  (zeile, spalte, wert))
        {
          // Falls Wert moeglich, Wert setzen und Rekursion starten.
          zellen[zeile][spalte] = wert;
          suche (iNextZeile, iNextSpalte); // Rekursionsaufruf
        }
      }
      // Keiner der Werte war moeglich. Wert zuruecksetzen.
      zellen[zeile][spalte] = ' ';
      return; 
    }
  }
}

int main(void) {
  printSudoku();
  suche (0, 0);
  return 0;
}
