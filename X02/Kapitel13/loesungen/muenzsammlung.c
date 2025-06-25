#include <stdio.h>

typedef struct Kategorie Kategorie;
struct Kategorie {
  char waehrung[4];
  double wert;
};

typedef struct Muenze Muenze;
struct Muenze {
  Kategorie* kategorie;
  int jahr;
  double tauschwert;
  double groesse;
  char kaufdatum[11];
};

void printMuenze(const Muenze* muenze) {
  printf("%.02f %-3s Muenze von %4d.\n",
    muenze->kategorie->wert,
    muenze->kategorie->waehrung,
    muenze->jahr);
  printf("Gekauft am %10s.\n", muenze->kaufdatum);
  printf("Aktueller Wert: %.02f\n", muenze->tauschwert);
  printf("\n");
}

int main(void) {
  Kategorie dmark1 = {"DM", 1.00};
  Kategorie franken5 = {"CHF", 5.00};
 
  Muenze meineMark =   {&dmark1, 1995, 2.00, 23.5, "2015-04-13"};
  Muenze gluecksMark = {&dmark1, 1991, 10.00, 23.5, "1991-07-04"};
  Muenze auslandGeld = {&franken5, 1888, 700.00, 31.45, "2010-11-28"};
  
  printMuenze(&meineMark);
  printMuenze(&gluecksMark);
  printMuenze(&auslandGeld);
  
  return 0;
}
